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

//ʵ�ֻ�ȡӦ�ó���������������ڵ����
Universe::Application* Universe::CreateApplication()
{
	return new SandboxApp();
}



