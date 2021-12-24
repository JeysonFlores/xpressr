#include "Interfaces/Regex.h"
#include "Utils/Logger.h"
#include <cstdlib>
#include <iostream>
#include <tuple>
#include <type_traits>

INIT_LOGGER;

// TODO: Put the session's creation inside a Try-Catch statement
int main(int /*argc*/, char* /*argv*/[])
{
    auto connection = sdbus::createSessionBusConnection("com.github.jeysonflores.xpressrService");
    LOG(SUCCESS, "Name requested successfully...");

    XpressrService::Interfaces::Regex server(*connection, "/com/github/jeysonflores/xpressrService/Regex");

    LOG(INFO, "Service Starting...");
    //connection->enterEventLoop();

    LOG(INFO, "Service ended");

    sdbus::Struct<int32_t, std::string, std::string, std::string> user;
    std::cout << std::get<1>(user).empty() << std::endl;
}