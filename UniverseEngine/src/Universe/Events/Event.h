#pragma once
#include "Universe/Core.h"

#include <string>
#include <functional>

namespace Universe {

	//�����¼�����
	enum  class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowBlur, WindowMoved,//�����¼�
		AppTick, AppUpdate, AppRender,//Ӧ�ó����¼�
		KeyPressed, KeyReleased,//�����¼�
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled//����¼�
	};

	//�¼��ķ���,��32λ��int���ʹ洢��ÿһλ��ʾһ���¼�����
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication  = BIT(0),//...000000001
		EventCategoryInput		  = BIT(1),//...000000010
		EventCategoryKeyBoard	  = BIT(2),//...000000100
		EventCategoryMouse		  = BIT(3),//...000001000
		EventCategoryMouseButton  = BIT(4) //...000010000

	};

//��һЩ�����ıر��Ķ���ɺ꣬���ٴ�����
//#�ǰѺ��������תΪ�ַ���
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	//event�������¼��ĸ���
	class UN_API Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;//�����¼�����
		virtual const char* GetName() const = 0;//�����¼�����
		virtual int GetCategoryFlags() const = 0;//�����¼�����
		virtual std::string ToString() const { return GetName(); }//������,�����¼����Ը�����Ҫ��д��Ĭ������¼�����

		//�ж��¼��Ƿ��ڵ�ǰ������
		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}

	protected:
		bool m_Handled = false;
	};


	//�¼�������
	class UN_API EventDispatcher
	{
		template<typename T>
		using EventFun = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& event)
			: m_Event(event){}

		template<typename T>
		bool Dispatch(EventFun<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled = func(static_cast<T&>(m_Event));
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}

}