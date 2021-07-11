#ifndef __HOOPOE_ENGINE_CORE_APPLICATION_H__
#define __HOOPOE_ENGINE_CORE_APPLICATION_H__

#include "Memory.h"

namespace Hoopoe 
{

class Application
{
public:
    Application();
    virtual ~Application();

    void Run();
}; // Application

Application *CreateApplication();
    
} // Hoopoe

#endif // __HOOPOE_ENGINE_CORE_APPLICATION_H__