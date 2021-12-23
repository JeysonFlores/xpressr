#pragma once

#include "../Adaptors/RegexAdaptor.h"
#include <iostream>
#include <sdbus-c++/sdbus-c++.h>

// TODO: Define a way to implement the sdbus::Struct<> template
class RegexInterface final : public sdbus::AdaptorInterfaces<com::github::jeysonflores::RegexAdaptor> {
public:
    RegexInterface(sdbus::IConnection& connection, std::string objectPath);
    ~RegexInterface();

private:
    //virtual sdbus::Struct<int32_t, std::string, std::string, std::string> GetRegexById(const int32_t& id) override;
    virtual bool SetRegex(const std::string& name, const std::string& regex, const std::string& example) override;
    virtual bool UpdateRegex(const int32_t& id, const std::string& name, const std::string& regex, const std::string& example) override;
    virtual bool DeleteRegex(const int32_t& id) override;
};
