#include "DataManager.h"

XpressrService::Services::DataManager::DataManager(std::string database_path) : connection(database_path) {
    std::cout << "DataManager created";
}

XpressrService::Services::DataManager::~DataManager() {

}