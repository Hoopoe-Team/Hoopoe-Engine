#include "../include/LogManager.h"

namespace Hoopoe 
{

std::shared_ptr<spdlog::logger> LogManager::s_CoreLogger;
std::shared_ptr<spdlog::logger> LogManager::s_ClientLogger;

void LogManager::Init()
{
    spdlog::set_pattern("%^[%T] %n: %v%$");

    s_CoreLogger = spdlog::stdout_color_mt("HOOPOE");
    s_CoreLogger->set_level(spdlog::level::trace);

    s_ClientLogger = spdlog::stdout_color_mt("APP");
    s_ClientLogger->set_level(spdlog::level::trace);
}

void LogManager::setPattern(const String &pattern)
{
    spdlog::set_pattern(pattern);
}

}