#ifndef __HOOPOE_ENGINE_CORE_FILESYSTEM_H__
#define __HOOPOE_ENGINE_CORE_FILESYSTEM_H__

#include "CoreHeaders.h"

#ifdef OS_IS_UNIX_LINUX
    #include "platform/linux/FileSystem.h"
#elif defined(OS_IS_WIN32)
    #include "platform/win/FileSystem.h"
#elif defined(OS_IS_UNIX_MACOS)
    #include "platform/mac/FileSystem.h"
#endif

#endif // __HOOPOE_ENGINE_CORE_FILESYSTEM_H__