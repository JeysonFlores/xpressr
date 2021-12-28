#include "DataManager.h"

/**
**  Constructor of XpressrService::Services::DataManager.
*   @param databasePath the path of the database to connect.
*/
XpressrService::Services::DataManager::DataManager(const char* databasePath)
    : connection(sqlite::database(databasePath))
{
    this->connection << "CREATE table IF NOT EXISTS regexes ("
                        "   id integer primary key autoincrement not null,"
                        "   name text,"
                        "   regex text,"
                        "   example text"
                        ");";
}

/**
**  Destructor of XpressrService::Services::DataManager.
*/
XpressrService::Services::DataManager::~DataManager()
{
}

/**
**  Query all Regexes inside the database.
*   @return a std::vector with the queried data.
*/
std::vector<sdbus::Struct<int32_t, std::string, std::string, std::string>> XpressrService::Services::DataManager::getAll()
{
    std::vector<sdbus::Struct<int32_t, std::string, std::string, std::string>> result;
    this->connection << "SELECT id,name,regex,example FROM regexes ;"
        >> [&](int32_t id, std::string name, std::string regex, std::string example) {
              sdbus::Struct<int32_t, std::string, std::string, std::string> row = { id, name, regex, example };
              result.push_back(row);
          };
    return result;
}

/**
**  Query a Regex by its id given the databasePath.
*   @param id the id of the regex.
*   @return a dbus::Struct (std::tuple) with the queried data.
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
**  Inserts a Regex given the databasePath.
*   @param name the name of the regex.
*   @param regex the regex itself.
*   @param example the example of that regex.
*/
void XpressrService::Services::DataManager::set(int& id, std::string name, std::string regex, std::string example)
{
    this->connection << "INSERT INTO regexes (id,name,regex,example) VALUES (NULL,?,?,?);"
                     << name
                     << regex
                     << example;

    id = this->connection.last_insert_rowid();
}

/**
**  Updates a Regex given the databasePath.
*   @param name the id of the regex.
*   @param name the name of the regex.
*   @param regex the regex itself.
*   @param example the example of that regex.
*/
void XpressrService::Services::DataManager::update(int id, std::string name, std::string regex, std::string example)
{
    this->connection << "UPDATE regexes SET name = ?, regex = ?, example = ? WHERE id = ? ;"
                     << name
                     << regex
                     << example
                     << id;
}

/**
**  Query a Regex by its id given the databasePath.
*   @param id the id of the regex.
*/
void XpressrService::Services::DataManager::remove(int id)
{
    this->connection << "DELETE FROM regexes WHERE id = ? ;"
                     << id;
}

/**
**  Check if a Regex exists by its id given the databasePath.
*   @param id the id of the regex.
*   @return a bool flag that indicates if the regex exists.
*/
bool XpressrService::Services::DataManager::exists(int id)
{
    int rows = 0;
    this->connection << "SELECT COUNT(*) FROM regexes WHERE id = ? ;"
                     << id
        >> rows;
    return rows > 0;
}

/**
**  Counts how many rows are stored in the database.
*   @return the total amout of rows inside the database.
*/
int XpressrService::Services::DataManager::count()
{
    int rows = 0;
    this->connection << "SELECT COUNT(*) FROM regexes;"
        >> rows;
    return rows;
}