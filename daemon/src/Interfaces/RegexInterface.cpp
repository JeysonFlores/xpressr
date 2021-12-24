// TODO: Implement a way to return the sdbus::Struct<> template
#include "RegexInterface.h"

XpressrService::Interfaces::RegexInterface::RegexInterface(sdbus::IConnection& connection, std::string objectPath)
    : AdaptorInterfaces(connection, std::move(objectPath))
{
    registerAdaptor();
}

XpressrService::Interfaces::RegexInterface::~RegexInterface()
{
    unregisterAdaptor();
}

bool XpressrService::Interfaces::RegexInterface::SetRegex(const std::string& name, const std::string& regex, const std::string& example)
{
    std::cout << "Hola :D";

    return false;
}

bool XpressrService::Interfaces::RegexInterface::UpdateRegex(const int32_t& id, const std::string& name, const std::string& regex, const std::string& example)
{
    std::cout << "Hola :D";

    return false;
}

bool XpressrService::Interfaces::RegexInterface::DeleteRegex(const int32_t& id)
{
    std::cout << "Hola :D";

    return false;
}
