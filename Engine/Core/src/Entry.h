#ifndef __ENGINE_CORE_ENTRY_H__
#define __ENGINE_CORE_ENTRY_H__

#include "Application.h"

extern Hoopoe::Application* Hoopoe::CreateApplication();

int main(int argc, char* argv[]) 
{
    Hoopoe::ConfigFile engineCfg("hoopoe.cfg");
    Hoopoe::LogManager::Init(engineCfg);

    HE_CORE_INFO("hoopoe.cfg loaded.");
    HE_CORE_INFO("Logging system initialized.");

    HE_CORE_INFO("All subsystems of Hoopoe Engine ver." + engineCfg.getSetting("engine_version", "General", "0") + " were initialized!");

    auto app = Hoopoe::CreateApplication();
    HE_EXCEPT(Hoopoe::Exception::ERR_NOT_IMPLEMENTED, "This code does not support to work.", "int main(int argc, char* argv[])");
    app->Run();
    delete app;

    return 0;
}

#endif // __ENGINE_CORE_ENTRY_H__