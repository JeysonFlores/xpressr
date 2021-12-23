// TODO: Implement a way to implement the sdbus::Struct<> template
#include "RegexInterface.h"

RegexInterface::RegexInterface(sdbus::IConnection& connection, std::string objectPath)
    : AdaptorInterfaces(connection, std::move(objectPath))
{
    registerAdaptor();
}

RegexInterface::~RegexInterface()
{
    unregisterAdaptor();
}

bool RegexInterface::SetRegex(const std::string& name, const std::string& regex, const std::string& example)
{
    std::cout << "Hola :D";

    return false;
}

bool RegexInterface::UpdateRegex(const int32_t& id, const std::string& name, const std::string& regex, const std::string& example)
{
    std::cout << "Hola :D";

    return false;
}

bool RegexInterface::DeleteRegex(const int32_t& id)
{
    std::cout << "Hola :D";

    return false;
}
