#pragma once
#include "Universe/Core.h"

#include <string>
#include <functional>

namespace Universe {

	//所有事件类型
	enum  class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowBlur, WindowMoved,//窗口事件
		AppTick, AppUpdate, AppRender,//应用程序事件
		KeyPressed, KeyReleased,//键盘事件
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled//鼠标事件
	};

	//事件的分类,用32位的int类型存储，每一位表示一种事件类型
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication  = BIT(0),//...000000001
		EventCategoryInput		  = BIT(1),//...000000010
		EventCategoryKeyBoard	  = BIT(2),//...000000100
		EventCategoryMouse		  = BIT(3),//...000001000
		EventCategoryMouseButton  = BIT(4) //...000010000

	};

//将一些基础的必备的定义成宏，减少代码量
//#是把后面的内容转为字符串
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	//event是所有事件的父类
	class UN_API Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;//返回事件类型
		virtual const char* GetName() const = 0;//返回事件名字
		virtual int GetCategoryFlags() const = 0;//返回事件类型
		virtual std::string ToString() const { return GetName(); }//调试用,其他事件可以根据需要重写，默认输出事件名字

		//判断事件是否在当前分类中
		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}

	protected:
		bool m_Handled = false;
	};


	//事件调度器
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