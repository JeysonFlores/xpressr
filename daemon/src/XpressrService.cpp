#include <iostream>
#include "Utils/Logger.h"
#include "Adaptors/Regex.h"

INIT_LOGGER;

int main(int /*argc*/, char */*argv*/[])
{
    LOG(INFO, "Service Started");
    LOG(INFO, "Requesting name...");
    LOG(SUCCESS, "Name requested successfully");
}