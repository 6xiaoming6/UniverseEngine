#pragma once
#include "Event.h"

#include <sstream>

namespace Universe {

	//窗口大小改变事件
	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			:m_Width(width), m_Height(height) {}

		inline unsigned int GetWidth() { return m_Width; }
		inline unsigned int GetHeight() { return m_Height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "窗口大小改变事件:" << m_Width << m_Height;
			return ss.str();
		}
		EVENT_CLASS_CATEGORY(EventCategoryApplication);
		EVENT_CLASS_TYPE(WindowResize);

	private:
		unsigned int m_Width, m_Height;
	};


	//窗口关闭事件
	class UN_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}
		EVENT_CLASS_TYPE(WindowClose);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);

	};


	//三巨头，主线任务
	//应用程序每帧执行事件
	class UN_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() {}
		EVENT_CLASS_TYPE(AppTick);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);

	};

	//应用程序更新事件
	class UN_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() {}
		EVENT_CLASS_TYPE(AppUpdate);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);

	};

	//应用程序渲染事件
	class UN_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() {}
		EVENT_CLASS_TYPE(AppRender);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);

	};

}