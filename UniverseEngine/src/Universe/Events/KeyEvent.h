#pragma once
#include "Event.h"

#include <sstream>

namespace Universe {

	//键盘事件继承事件类，同时该事件又是所有键盘事件的父类
	class UN_API KeyEvent :public Event
	{
	public:
		EVENT_CLASS_CATEGORY(EventCategoryKeyBoard | EventCategoryInput);
		inline int GetKeyCode() { return m_KeyCode; }

	protected:
		KeyEvent(int keyCode)
			:m_KeyCode(keyCode){}

		int m_KeyCode;

	};

	//键盘按下事件
	class UN_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keyCode, int repeatCount)
			:KeyEvent(keyCode), m_RepeatCount(repeatCount) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "键盘按下事件:" << m_KeyCode << "重复次数:" << m_RepeatCount;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed);

	private:
		int m_RepeatCount;
	};

	//键盘弹起事件
	class UN_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keyCode)
			:KeyEvent(keyCode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "键盘弹起事件:" << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased);

	};
}