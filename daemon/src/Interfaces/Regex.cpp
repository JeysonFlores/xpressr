// TODO: Implement a way to return all the Regexes template
#include "Regex.h"

XpressrService::Interfaces::Regex::Regex(sdbus::IConnection& connection, std::string objectPath, XpressrService::Services::DataManager dbm)
    : AdaptorInterfaces(connection, std::move(objectPath))
    , dbManager(dbm)
{
    registerAdaptor();
}

XpressrService::Interfaces::Regex::~Regex()
{
    unregisterAdaptor();
}

/**
    Gets a Regex by its id.
    @param id the id of the regex.
    @return a dbus::Struct (tuple) with the data of that Regex.
*/
sdbus::Struct<int32_t, std::string, std::string, std::string> XpressrService::Interfaces::Regex::GetRegexById(const int32_t& id)
{
    LOG(INFO, "GetRegexById method called");
    return this->dbManager.getById(id);
}

/**
    Inserts a new Regex.
    @param name the name of the regex.
    @param regex the regex itself.
    @param example the example of that regex.
    @return a bool flag that indicates if there's error or not.
*/
bool XpressrService::Interfaces::Regex::SetRegex(const std::string& name, const std::string& regex, const std::string& example)
{
    LOG(INFO, "SetRegex method called");
    if (!this->dbManager.set(name, regex, example)) {
        return true;
    }

    LOG(ERROR, "There was an error setting a Regex");
    return false;
}

/**
    Updates a Regex.
    @param id the id of the regex.
    @param name the name of the regex.
    @param regex the regex itself.
    @param example the example of that regex.
    @return a bool flag that indicates if there's error or not.
*/
bool XpressrService::Interfaces::Regex::UpdateRegex(const int32_t& id, const std::string& name, const std::string& regex, const std::string& example)
{
    LOG(INFO, "UpdateRegex method called");
    if (!this->dbManager.update(id, name, regex, example)) {
        return true;
    }

    LOG(ERROR, "There was an error updating a Regex");
    return false;
}

/**
    Deletes a Regex according to its id.
    @param id the id of the regex.
    @return a bool flag that indicates if there's error or not.
    TODO: Improve logic.
*/
bool XpressrService::Interfaces::Regex::DeleteRegex(const int32_t& id)
{
    LOG(INFO, "DeleteRegex method called");
    if (this->dbManager.exists(id)) {
        LOG(INFO, "The given ID exists");
        if (!this->dbManager.remove(id)) {
            return true;
        }

        throw sdbus::Error("com.github.jeysonflores.xpressrService.Error", "An error ocurred when deleting the regex");
        return false;
    }

    throw sdbus::Error("com.github.jeysonflores.xpressrService.Error", "There's no Regex that matches with the given Id");
    return false;
}
