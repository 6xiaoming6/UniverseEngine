#pragma once
#include "Event.h"

#include <sstream>

namespace Universe {

	//�����¼��̳��¼��࣬ͬʱ���¼��������м����¼��ĸ���
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

	//���̰����¼�
	class UN_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keyCode, int repeatCount)
			:KeyEvent(keyCode), m_RepeatCount(repeatCount) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "���̰����¼�:" << m_KeyCode << "�ظ�����:" << m_RepeatCount;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed);

	private:
		int m_RepeatCount;
	};

	//���̵����¼�
	class UN_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keyCode)
			:KeyEvent(keyCode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "���̵����¼�:" << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased);

	};
}