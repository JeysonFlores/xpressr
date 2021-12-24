#include "DataManager.h"


/**
    Constructor of DataManager.
    @param database_path the path of the database to connect.
*/
XpressrService::Services::DataManager::DataManager(const char* database_path)
    : connection(sqlite::database(database_path))
{
    this->connection << "CREATE table IF NOT EXISTS regexes ("
                        "   id integer primary key autoincrement not null,"
                        "   name text,"
                        "   regex text,"
                        "   example text"
                        ");";
}


XpressrService::Services::DataManager::~DataManager()
{
}

/**
    Query a Regex by its id given the database_path.
    @param id the id of the regex.
    @return a dbus::Struct (tuple) with the queried data.
*/
sdbus::Struct<int32_t, std::string, std::string, std::string> XpressrService::Services::DataManager::getById(int id)
{
    sdbus::Struct<int32_t, std::string, std::string, std::string> queriedRegex;
    this->connection << "SELECT id,name,regex,example FROM regexes WHERE id = ? ;"
                     << id
        >> [&](int32_t _id, std::string name, std::string regex, std::string example) {
              std::get<0>(queriedRegex) = _id;
              std::get<1>(queriedRegex) = name;
              std::get<2>(queriedRegex) = regex;
              std::get<3>(queriedRegex) = example;
          };

    return queriedRegex;
}

/**
    Inserts a Regex given the database_path.
    @param name the name of the regex.
    @param regex the regex itself.
    @param example the example of that regex.
    @return a bool flag that indicates if there's error or not.
*/
bool XpressrService::Services::DataManager::set(std::string name, std::string regex, std::string example)
{
    bool error = false;
    try {
        this->connection << "INSERT INTO regexes (id,name,regex,example) VALUES (NULL,?,?,?);"
                         << name
                         << regex
                         << example;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        error = true;
    }

    return error;
}

/**
    Updates a Regex given the database_path.
    @param name the id of the regex.
    @param name the name of the regex.
    @param regex the regex itself.
    @param example the example of that regex.
    @return a bool flag that indicates if there's error or not.
*/
bool XpressrService::Services::DataManager::update(int id, std::string name, std::string regex, std::string example)
{
    bool error = false;
    try {
        this->connection << "UPDATE regexes SET name = ?, regex = ?, example = ? WHERE id = ? ;"
                         << name
                         << regex
                         << example
                         << id;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        error = true;
    }

    return error;
}

/**
    Query a Regex by its id given the database_path.
    @param id the id of the regex.
    @return a bool flag that indicates if there's error or not.
*/
bool XpressrService::Services::DataManager::remove(int id)
{
    bool error = false;
    try {
        this->connection << "DELETE FROM regexes WHERE id = ? ;"
                         << id;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        error = true;
    }

    return error;
}