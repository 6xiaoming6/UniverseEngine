#pragma once
#include "Event.h"
#include <sstream>

namespace Universe {

	//����ƶ��¼�
	class UN_API MouseMovedEvnet : public Event
	{
	public:
		MouseMovedEvnet(float x, float y)
			:m_MouseX(x), m_MouseY(y)
		{}
		inline float GetMouseX() { return m_MouseX; }
		inline float GetMouseY() { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "����ƶ��¼�:" << m_MouseX << " " << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);
		EVENT_CLASS_TYPE(MouseMoved);

	private:
		float m_MouseX, m_MouseY;//�������Ļ��x,y����
	};
	

	//�������¼�
	class UN_API MouseScrolledEvnet : public Event
	{
	public:
		MouseScrolledEvnet(float offsetX, float offsetY)
			:m_OffsetX(offsetX), m_OffsetY(offsetY)
		{}
		inline float GetOffsetX() { return m_OffsetX; }
		inline float GetOffsetY() { return m_OffsetY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "�������¼�:" << m_OffsetX << " " << m_OffsetY;
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);
		EVENT_CLASS_TYPE(MouseScrolled);

	private:
		float m_OffsetX, m_OffsetY;//�����ֹ����ķ���
	};

	//��갴���¼�����������갴���¼��ĸ���
	class UN_API MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryMouseButton);
	protected:
		MouseButtonEvent(int button)
			:m_Button(button) {}

		int m_Button;
	};

	//��갴�������¼�
	class UN_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button)
			:MouseButtonEvent(button) {}


		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "��갴�������¼�:" << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed);
	private:

	};

	//��갴�������¼�
	class UN_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button)
			:MouseButtonEvent(button) {}


		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "��갴�������¼�:" << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased);

	private:
	};
}