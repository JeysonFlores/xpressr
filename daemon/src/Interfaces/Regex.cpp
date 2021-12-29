#include "Regex.h"

/**
**  Constructor of XpressrService::Interfaces::Regex.
*   @param connection the D-Bus instance connection.
*   @param objectPath the path for the object.
*   @param dbm DataManager instance to perform database operations.
*/
XpressrService::Interfaces::Regex::Regex(sdbus::IConnection& connection, std::string objectPath, XpressrService::Services::DataManager dbm)
    : AdaptorInterfaces(connection, std::move(objectPath))
    , dbManager(dbm)
{
    registerAdaptor();
}

/**
**  Destructor of XpressrService::Interfaces::Regex.
*/
XpressrService::Interfaces::Regex::~Regex()
{
    unregisterAdaptor();
}

/**
**  Gets all the Regex.
*   @return a std::vector with all the regexes.
*/
std::vector<sdbus::Struct<int32_t, std::string, std::string, std::string>> XpressrService::Interfaces::Regex::GetRegexes()
{
    LOG(INFO, "GetRegexes method called");
    try {
        return this->dbManager.getAll();
    } catch (std::exception& e) {
        throw sdbus::Error("com.github.jeysonflores.xpressrService.Error", e.what());
        LOG(ERROR, "There was an error retrieving all Regexes");
    }
}

/**
**  Gets a Regex by its id.
*   @param id the id of the regex.
*   @return a dbus::Struct (std::tuple) with the data of that Regex.
*/
sdbus::Struct<int32_t, std::string, std::string, std::string> XpressrService::Interfaces::Regex::GetRegexById(const int32_t& id)
{
    LOG(INFO, "GetRegexById method called");
    if (this->dbManager.exists(id)) {
        try {
            return this->dbManager.getById(id);
        } catch (std::exception& e) {
            throw sdbus::Error("com.github.jeysonflores.xpressrService.Error", e.what());
            LOG(ERROR, "There was an error retrieving a Regex");
        }
    }

    throw sdbus::Error("com.github.jeysonflores.xpressrService.Error", "There's no Regex that matches with the given Id");
}

/**
**  Inserts a new Regex.
*   @param name the name of the regex.
*   @param regex the regex itself.
*   @param example the example of that regex.
*   @return a bool flag that indicates if there's error or not.
*/
bool XpressrService::Interfaces::Regex::SetRegex(const std::string& name, const std::string& regex, const std::string& example)
{
    LOG(INFO, "SetRegex method called");
    int id;
    try {
        this->dbManager.set(id, name, regex, example);
        this->emitRegexAdded(id, name, regex, example);
        return true;
    } catch (std::exception& e) {
        throw sdbus::Error("com.github.jeysonflores.xpressrService.Error", e.what());
        LOG(ERROR, "There was an error setting a Regex");
    }

    return false;
}

/**
**  Updates a Regex.
*   @param id the id of the regex.
*   @param name the name of the regex.
*   @param regex the regex itself.
*   @param example the example of that regex.
*   @return a bool flag that indicates if there's error or not.
*/
bool XpressrService::Interfaces::Regex::UpdateRegex(const int32_t& id, const std::string& name, const std::string& regex, const std::string& example)
{
    LOG(INFO, "UpdateRegex method called");
    if (this->dbManager.exists(id)) {
        try {
            this->dbManager.update(id, name, regex, example);
            this->emitRegexUpdated(id, name, regex, example);
            return true;
        } catch (std::exception& e) {
            throw sdbus::Error("com.github.jeysonflores.xpressrService.Error", e.what());
            LOG(ERROR, "There was an error updating a Regex");
        }
    }

    throw sdbus::Error("com.github.jeysonflores.xpressrService.Error", "There's no Regex that matches with the given Id");
    return false;
}

/**
**  Deletes a Regex according to its id.
*   @param id the id of the regex.
*   @return a bool flag that indicates if there's error or not.
*/
bool XpressrService::Interfaces::Regex::DeleteRegex(const int32_t& id)
{
    LOG(INFO, "DeleteRegex method called");
    if (this->dbManager.exists(id)) {
        try {
            this->dbManager.remove(id);
            this->emitRegexDeleted(id);
            return true;
        } catch (std::exception& e) {
            throw sdbus::Error("com.github.jeysonflores.xpressrService.Error", e.what());
            LOG(ERROR, "There was an error deleting a Regex");
        }
    }

    throw sdbus::Error("com.github.jeysonflores.xpressrService.Error", "There's no Regex that matches with the given Id");
    return false;
}
