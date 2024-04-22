#pragma once
#ifdef UN_PLATFORM_WINDOWS
//外部函数声明,实际的函数声明在引擎的Application中,实际的函数定义在外部应用程序实现
extern Universe::Application* Universe::CreateApplication();

int main(int arg, char** args)
{
	auto app = Universe::CreateApplication();
	app->Run();

	delete app;
}


#endif // UN_PLATFORM_WINDOWS
