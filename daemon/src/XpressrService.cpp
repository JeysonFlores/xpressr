#include <iostream>
#include "Interfaces/RegexInterface.h"
#include "Utils/Logger.h"

INIT_LOGGER;

// TODO: Put the session's creation inside a Try-Catch statement
int main(int /*argc*/, char* /*argv*/[])
{
    LOG(INFO, "Service Started");

    const char* serviceName = "com.github.jeysonflores.xpressrService";
    auto connection = sdbus::createSessionBusConnection(serviceName);

    LOG(SUCCESS, "Name requested successfully...");

    const char* objectPath = "/com/github/jeysonflores/xpressrService/Regex";
    RegexInterface server(*connection, objectPath);

    connection->enterEventLoop();
    LOG(INFO, "Service ended");
}