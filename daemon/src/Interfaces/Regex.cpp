// TODO: Implement a way to return the sdbus::Struct<> template
#include "Regex.h"

XpressrService::Interfaces::Regex::Regex(sdbus::IConnection& connection, std::string objectPath)
    : AdaptorInterfaces(connection, std::move(objectPath))
{
    registerAdaptor();
}

XpressrService::Interfaces::Regex::~Regex()
{
    unregisterAdaptor();
}

sdbus::Struct<int32_t, std::string, std::string, std::string> XpressrService::Interfaces::Regex::GetRegexById(const int32_t& id)
{

    sdbus::Struct<int32_t, std::string, std::string, std::string> ola;
    return ola;
}

bool XpressrService::Interfaces::Regex::SetRegex(const std::string& name, const std::string& regex, const std::string& example)
{
    std::cout << "Hola :D";

    return false;
}

bool XpressrService::Interfaces::Regex::UpdateRegex(const int32_t& id, const std::string& name, const std::string& regex, const std::string& example)
{
    std::cout << "Hola :D";

    return false;
}

bool XpressrService::Interfaces::Regex::DeleteRegex(const int32_t& id)
{
    std::cout << "Hola :D";

    return false;
}
