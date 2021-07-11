#ifndef __HOOPOE_ENGINE_CORE_PLATFORM_H__
#define __HOOPOE_ENGINE_CORE_PLATFORM_H__

/***** Determine OS type *****/
/*
 * It defines some of the following constants:
 *
 * OS_IS_WIN32          Win32 any kind
 * OS_IS_WIN32_NT       Windows NT/XP
 *
 * OS_IS_UNIX           UNIX any kind
 * OS_IS_UNIX_BSD       BSD UNIX any kind
 * OS_IS_UNIX_LINUX     Linux
 * OS_IS_UNIX_MACOS     MacOS/X
 *
 */
#if     defined(_MSC_VER) ||    \
        defined(__WIN32) ||     \
        defined(__WIN32__) ||   \
        defined(_WIN32) ||      \
        defined(WIN32) ||       \
        defined(__WINNT) ||     \
        defined(__WINNT__) ||   \
        defined(__WINNT)

#   define OS_IS_WIN32          1
#   define OS_IS_WIN32_NT       1

#elif defined(__linux) || defined(__linux__)

#   define OS_IS_UNIX           1
#   define OS_IS_UNIX_LINUX     1

#elif defined(__APPLE__)

#   define OS_IS_UNIX           1
#   define OS_IS_UNIX_BSD       1
#   define OS_IS_UNIX_MACOS     1

#else

#   error Cannot determine OS type

#endif // if

#endif // __HOOPOE_ENGINE_CORE_PLATFORM_H__