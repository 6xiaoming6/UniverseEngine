#include <Universe.h>

class SandboxApp:public Universe::Application
{
public:
	SandboxApp()
	{

	};
	~SandboxApp()
	{

	};

private:

};

//实现获取应用程序函数，引擎入入口点调用
Universe::Application* Universe::CreateApplication()
{
	return new SandboxApp();
}



