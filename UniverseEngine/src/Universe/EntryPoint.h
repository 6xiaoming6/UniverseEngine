#pragma once
#ifdef UN_PLATFORM_WINDOWS
//�ⲿ��������,ʵ�ʵĺ��������������Application��,ʵ�ʵĺ����������ⲿӦ�ó���ʵ��
extern Universe::Application* Universe::CreateApplication();

int main(int arg, char** args)
{
	auto app = Universe::CreateApplication();
	app->Run();

	delete app;
}


#endif // UN_PLATFORM_WINDOWS
