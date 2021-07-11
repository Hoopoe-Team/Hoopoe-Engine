#ifndef __HOOPOE_ENGINE_CORE_LOGMANAGER_H__
#define __HOOPOE_ENGINE_CORE_LOGMANAGER_H__

#include <memory>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/rotating_file_sink.h"

#include "CoreHeaders.h"
#include "ConfigFile.h"

namespace Hoopoe 
{

class LogManager
{
public:
    static void Init();
    static void Init(const Hoopoe::ConfigFile &config);

    static void configure(const ConfigFile &config);
    static void setPattern(const String &pattern);

    inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return CoreLogger; }
    inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return ClientLogger; }

private:
    static std::shared_ptr<spdlog::logger> CoreLogger;
    static std::shared_ptr<spdlog::logger> ClientLogger;
}; // LogManager

} // Hoopoe

#define HE_CORE_TRACE(...) Hoopoe::LogManager::GetCoreLogger()->trace(__VA_ARGS__)
#define HE_CORE_INFO(...) Hoopoe::LogManager::GetCoreLogger()->info(__VA_ARGS__)
#define HE_CORE_WARN(...) Hoopoe::LogManager::GetCoreLogger()->warn(__VA_ARGS__)
#define HE_CORE_ERROR(...) Hoopoe::LogManager::GetCoreLogger()->error(__VA_ARGS__)
#define HE_CORE_CRITICAL(...) Hoopoe::LogManager::GetCoreLogger()->critical(__VA_ARGS__)

#define HE_CLIENT_TRACE(...) Hoopoe::LogManager::GetClientLogger()->trace(__VA_ARGS__)
#define HE_CLIENT_INFO(...) Hoopoe::LogManager::GetClientLogger()->info(__VA_ARGS__)
#define HE_CLIENT_WARN(...) Hoopoe::LogManager::GetClientLogger()->warn(__VA_ARGS__)
#define HE_CLIENT_ERROR(...) Hoopoe::LogManager::GetClientLogger()->error(__VA_ARGS__)
#define HE_CLIENT_CRITICAL(...) Hoopoe::LogManager::GetClientLogger()->critical(__VA_ARGS__)

#endif // __HOOPOE_ENGINE_CORE_LOGMANAGER_H__