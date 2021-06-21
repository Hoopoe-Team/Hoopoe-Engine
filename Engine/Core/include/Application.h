#ifndef __ENGINE_CORE_APPLICATION_H__
#define __ENGINE_CORE_APPLICATION_H__

namespace Hoopoe 
{

class Application
{
public:
    Application();
    virtual ~Application();

    void Run();
};

Application *CreateApplication();
    
}

#endif