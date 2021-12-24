#include "Interfaces/RegexInterface.h"
#include "Utils/Logger.h"
#include <iostream>
#include <cstdlib>

INIT_LOGGER;

// TODO: Put the session's creation inside a Try-Catch statement
int main(int /*argc*/, char* /*argv*/[])
{
    auto connection = sdbus::createSessionBusConnection("com.github.jeysonflores.xpressrService");
    LOG(SUCCESS, "Name requested successfully...");

    RegexInterface server(*connection, "/com/github/jeysonflores/xpressrService/Regex");

    LOG(INFO, "Service Starting...");
    connection->enterEventLoop();

    LOG(INFO, "Service ended");
}