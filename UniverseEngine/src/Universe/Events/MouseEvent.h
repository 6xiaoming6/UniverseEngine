#pragma once
#include "Event.h"
#include <sstream>

namespace Universe {

	//鼠标移动事件
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
			ss << "鼠标移动事件:" << m_MouseX << " " << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);
		EVENT_CLASS_TYPE(MouseMoved);

	private:
		float m_MouseX, m_MouseY;//鼠标在屏幕的x,y坐标
	};
	

	//鼠标滚轮事件
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
			ss << "鼠标滚轮事件:" << m_OffsetX << " " << m_OffsetY;
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);
		EVENT_CLASS_TYPE(MouseScrolled);

	private:
		float m_OffsetX, m_OffsetY;//鼠标滚轮滚动的方向
	};

	//鼠标按键事件，是所有鼠标按键事件的父类
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

	//鼠标按键按下事件
	class UN_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button)
			:MouseButtonEvent(button) {}


		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "鼠标按键按下事件:" << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed);
	private:

	};

	//鼠标按键弹起事件
	class UN_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button)
			:MouseButtonEvent(button) {}


		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "鼠标按键弹起事件:" << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased);

	private:
	};
}