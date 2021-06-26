#include "LogManager.h"

namespace Hoopoe 
{

std::shared_ptr<spdlog::logger> LogManager::CoreLogger;
std::shared_ptr<spdlog::logger> LogManager::ClientLogger;

void LogManager::Init()
{
    spdlog::set_pattern("%^[%T] %n: %v%$");

    CoreLogger = spdlog::stdout_color_mt("HOOPOE");
    CoreLogger->set_level(spdlog::level::trace);

    ClientLogger = spdlog::stdout_color_mt("APP");
    ClientLogger->set_level(spdlog::level::trace);
}

void LogManager::Init(const ConfigFile &config)
{
    LogManager::configure(config);

    spdlog::register_logger(CoreLogger);
    spdlog::register_logger(ClientLogger);
}

void LogManager::configure(const ConfigFile &config)
{
    spdlog::set_pattern(config.getSetting("log_pattern", "Log Manager", "%^[%T] %n: %v%$"));

    bool allowConsoleLogging = config.getSetting("log_allow_console_logging", "Log Manager", "0") == "1" ? true : false;
    bool allowFileLogging = config.getSetting("log_allow_file_logging", "Log Manager", "0") == "1" ? true : false;

    std::vector<spdlog::sink_ptr> CoreSinks;
    std::vector<spdlog::sink_ptr> ClientSinks;

    if(allowConsoleLogging)
    {
        CoreSinks.push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
        ClientSinks.push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
    }

    if(allowFileLogging)
    {
        // Set the file name 
        String coreLogFileName = String("logs/") + config.getSetting("log_core_file_name", "Log Manager", "EngineLog.txt");
        String clientLogFileName = String("logs/") + config.getSetting("log_client_file_name", "Log Manager", "SandboxLog.txt");

        // Set the maximum file size 
        int coreFileMaxSize = std::stoi(config.getSetting("log_core_file_max_size", "Log Manager", "1048576"));
        int clientFileMaxSize = std::stoi(config.getSetting("log_client_file_max_size", "Log Manager", "1048576"));

        CoreSinks.push_back(std::make_shared<spdlog::sinks::rotating_file_sink_mt>(coreLogFileName, coreFileMaxSize, 5, false));
        ClientSinks.push_back(std::make_shared<spdlog::sinks::rotating_file_sink_mt>(clientLogFileName, clientFileMaxSize, 5, false));
    }

    CoreLogger = std::make_shared<spdlog::logger>("HOOPOE", begin(CoreSinks), end(CoreSinks));
    ClientLogger = std::make_shared<spdlog::logger>("APP", begin(ClientSinks), end(ClientSinks));

    // Circus trick
    CoreLogger->set_level(static_cast<spdlog::level::level_enum>(std::stoi(config.getSetting("log_core_level", "Log Manager", "0"))));
    ClientLogger->set_level(static_cast<spdlog::level::level_enum>(std::stoi(config.getSetting("log_client_level", "Log Manager", "0"))));

    CoreLogger->flush_on(spdlog::level::err);
    ClientLogger->flush_on(spdlog::level::err);
}

void LogManager::setPattern(const String &pattern)
{
    spdlog::set_pattern(pattern);
}

} // Hoopoe