#include "Interfaces/Regex.h"
#include "Services/DataManager.h"
#include "Utils/Logger.h"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <type_traits>

INIT_LOGGER;

int main(int /*argc*/, char* /*argv*/[])
{
    auto connection = sdbus::createSessionBusConnection("com.github.jeysonflores.xpressrService");

    LOG(SUCCESS, "Name requested successfully...");

    std::string env_p;
    if (std::getenv("XPRESSR_CONFIG_FLATPAK"))
        env_p = std::getenv("XPRESSR_CONFIG_FLATPAK");
    else {
        std::string db_path = "/.local/share/com.github.jeysonflores.xpressr.db";
        env_p = std::getenv("HOME") + db_path;
    }

    std::cout << "Database path is: " << env_p << '\n';

    XpressrService::Services::DataManager dataManager(env_p.c_str());

    XpressrService::Interfaces::Regex server(*connection, "/com/github/jeysonflores/xpressrService/Regex", dataManager);

    LOG(INFO, "Service Starting...");
    connection->enterEventLoop();
}