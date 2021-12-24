#include <iostream>
#include <sqlite_modern_cpp.h>

namespace XpressrService {
namespace Services {
    class DataManager {
    public:
        DataManager(const char* database_path);
        ~DataManager();

    private:
        std::string connection;
        /*public:
                void initializeDatabase();
                void getAll();
                void getById(int id);
                void set(std::string name, std::string regex, std::string example);
                void update(int id, std::string name, std::string regex, std::string example);
                void remove(int id);*/
    };
}
}