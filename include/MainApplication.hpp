#include "Poco/AutoPtr.h"
#include "Poco/Util/AbstractConfiguration.h"
#include "Poco/Util/Application.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/Util/ServerApplication.h"
#include "pch.hpp"

class AkashaRPServer : Poco::Util::ServerApplication
{
private:
    std::string configPath;
    enum ApplicationTypes
    {
        Client = 0,
        Server = 1
    };
    i8 applicationType = Client;
    Poco::AutoPtr<Poco::Util::AbstractConfiguration> config;
protected:
    void initialize(Poco::Util::Application& app) override;
    void defineOptions(Poco::Util::OptionSet& options) override;
    void setConfigPath(const std::string& name, const std::string& value);
    void setApplicationType(const std::string& name, const std::string& value);
public:
    int main(const std::vector<std::string>& args) override;;
};