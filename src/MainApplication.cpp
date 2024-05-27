#include "MainApplication.hpp"
#include "Poco/Util/IniFileConfiguration.h"
#include "Poco/Util/OptionSet.h"
#include <print>
#include <unordered_map>
#include <vector>

void AkashaRPServer::initialize(Application& app)
{
    ServerApplication::initialize(app);
}

void AkashaRPServer::defineOptions(Poco::Util::OptionSet& options)
{
    options.addOption
    (
        Poco::Util::Option("type","t")
        .description("Application type\nNormal Client = c or client\nNormal Server = s or server")
        .repeatable(false)
        .required(false)
        
    );
    options.addOption
    (
        Poco::Util::Option("config","c","Select configure file")
        .required(true)
        .repeatable(false)
        .callback(Poco::Util::OptionCallback<AkashaRPServer>(this, &AkashaRPServer::setConfigPath))
    );
}

int AkashaRPServer::main(const std::vector<std::string>& args)
{
    
    waitForTerminationRequest();
    
    return ExitCode::EXIT_OK;
}

void AkashaRPServer::setConfigPath(const std::string& name, const std::string& value)
{
    std::print("Load configure fille {}",value);
    configPath = value;
    config = new Poco::Util::IniFileConfiguration(configPath);
}

void AkashaRPServer::setApplicationType(const std::string& name, const std::string& value)
{
    static std::unordered_map<std::string, std::pair<i8, std::string>> nameToType = 
    {
        {"c",{Client,"Client"}},
        {"client",{Client,"Client"}},
        {"s",{Server,"Server"}},
        {"server",{Server,"Server"}}
    };
    if (nameToType.count(value) > 0)
    {
        std::print("Set application type to {}",nameToType[value].second);
        applicationType = nameToType[value].first;
    }
    else 
    {
        std::print("Application type {} not found",value);
    }
}