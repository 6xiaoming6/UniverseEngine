#pragma once
#include "Core.h"

namespace Universe {

	class UN_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	Application* CreateApplication();

}