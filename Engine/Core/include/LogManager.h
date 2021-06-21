#ifndef __HOOPOE_ENGINE_CORE_LOG_H__
#define __HOOPOE_ENGINE_CORE_LOG_H__

#include <memory>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Hoopoe 
{

class LogManager
{
public:
    static void Init();

    static void setPattern(const std::string &pattern);

    inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
    inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

private:
    static std::shared_ptr<spdlog::logger> s_CoreLogger;
    static std::shared_ptr<spdlog::logger> s_ClientLogger;
};

}

#define HE_CORE_TRACE(...) ::Hoopoe::LogManager::GetCoreLogger()->trace(__VA_ARGS__)
#define HE_CORE_INFO(...) ::Hoopoe::LogManager::GetCoreLogger()->info(__VA_ARGS__)
#define HE_CORE_WARN(...) ::Hoopoe::LogManager::GetCoreLogger()->warn(__VA_ARGS__)
#define HE_CORE_ERROR(...) ::Hoopoe::LogManager::GetCoreLogger()->error(__VA_ARGS__)
#define HE_CORE_CRITICAL(...) ::Hoopoe::LogManager::GetCoreLogger()->critical(__VA_ARGS__)

#define HE_CLIENT_TRACE(...) ::Hoopoe::LogManager::GetClientLogger()->trace(__VA_ARGS__)
#define HE_CLIENT_INFO(...) ::Hoopoe::LogManager::GetClientLogger()->info(__VA_ARGS__)
#define HE_CLIENT_WARN(...) ::Hoopoe::LogManager::GetClientLogger()->warn(__VA_ARGS__)
#define HE_CLIENT_ERROR(...) ::Hoopoe::LogManager::GetClientLogger()->error(__VA_ARGS__)
#define HE_CLIENT_CRITICAL(...) ::Hoopoe::LogManager::GetClientLogger()->critical(__VA_ARGS__)

#endif