#pragma once

#include <iostream>
#include <sdbus-c++/sdbus-c++.h>
#include <sqlite_modern_cpp.h>

//TODO: Implement getAll method
namespace XpressrService {
namespace Services {
    class DataManager {
    public:
        DataManager(const char* databasePath);
        ~DataManager();

    private:
        sqlite::database connection;

    public:
        //void getAll();
        sdbus::Struct<int32_t, std::string, std::string, std::string> getById(int id);
        void set(std::string name, std::string regex, std::string example);
        void update(int id, std::string name, std::string regex, std::string example);
        void remove(int id);
        bool exists(int id);
    };
}
}