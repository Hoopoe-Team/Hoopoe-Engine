#ifndef __ENGINE_CORE_ENTRY_H__
#define __ENGINE_CORE_ENTRY_H__

#include "Application.h"

extern Hoopoe::Application* Hoopoe::CreateApplication();

int main(int argc, char* argv[]) 
{
    Hoopoe::LogManager::Init();
    HE_CORE_INFO("Logging system initialized!");

    auto app = Hoopoe::CreateApplication();
    HE_EXCEPT(Hoopoe::Exception::ERR_NOT_IMPLEMENTED, "This code does not support to work.", "int main(int argc, char* argv[])");
    app->Run();
    delete app;

    return 0;
}

#endif