#include "Interfaces/Regex.h"
#include "Services/DataManager.h"
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
    XpressrService::Services::DataManager dataManager("dbfile.db");

    XpressrService::Interfaces::Regex server(*connection, "/com/github/jeysonflores/xpressrService/Regex", dataManager);

    LOG(INFO, "Service Starting...");
    connection->enterEventLoop();
}