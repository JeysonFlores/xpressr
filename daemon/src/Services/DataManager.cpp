#include "DataManager.h"

XpressrService::Services::DataManager::DataManager(const char* database_path)
    : connection(database_path)
{
    std::cout << "DataManager created";
}

XpressrService::Services::DataManager::~DataManager()
{
}