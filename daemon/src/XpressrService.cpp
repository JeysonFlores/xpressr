#include "Interfaces/RegexInterface.h"
#include "Utils/Logger.h"
#include <cstdlib>
#include <iostream>

INIT_LOGGER;

// TODO: Put the session's creation inside a Try-Catch statement
int main(int /*argc*/, char* /*argv*/[])
{
    auto connection = sdbus::createSessionBusConnection("com.github.jeysonflores.xpressrService");
    LOG(SUCCESS, "Name requested successfully...");

    XpressrService::Interfaces::RegexInterface server(*connection, "/com/github/jeysonflores/xpressrService/Regex");

    LOG(INFO, "Service Starting...");
    connection->enterEventLoop();

    LOG(INFO, "Service ended");
}