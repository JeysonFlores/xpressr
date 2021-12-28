#pragma once

#include <sdbus-c++/sdbus-c++.h>
#include <string>
#include <tuple>

//TODO: Implement getAll method
namespace XpressrService {
namespace Adaptors {

    class Regex {
    public:
        static constexpr const char* INTERFACE_NAME = "com.github.jeysonflores.Regex";

    protected:
        Regex(sdbus::IObject& object)
            : object_(object)
        {
            object_.registerMethod("GetRegexes").onInterface(INTERFACE_NAME).withOutputParamNames("regexes").implementedAs([this]() { return this->GetRegexes(); });
            object_.registerMethod("GetRegexById").onInterface(INTERFACE_NAME).withInputParamNames("id").withOutputParamNames("regex").implementedAs([this](const int32_t& id) { return this->GetRegexById(id); });
            object_.registerMethod("SetRegex").onInterface(INTERFACE_NAME).withInputParamNames("name", "regex", "example").withOutputParamNames("was_completed").implementedAs([this](const std::string& name, const std::string& regex, const std::string& example) { return this->SetRegex(name, regex, example); });
            object_.registerMethod("UpdateRegex").onInterface(INTERFACE_NAME).withInputParamNames("id", "name", "regex", "example").withOutputParamNames("was_completed").implementedAs([this](const int32_t& id, const std::string& name, const std::string& regex, const std::string& example) { return this->UpdateRegex(id, name, regex, example); });
            object_.registerMethod("DeleteRegex").onInterface(INTERFACE_NAME).withInputParamNames("id").withOutputParamNames("was_completed").implementedAs([this](const int32_t& id) { return this->DeleteRegex(id); });
            object_.registerSignal("RegexAdded").onInterface(INTERFACE_NAME).withParameters<int32_t, std::string, std::string, std::string>("id", "name", "regex", "example");
            object_.registerSignal("RegexUpdated").onInterface(INTERFACE_NAME).withParameters<int32_t, std::string, std::string, std::string>("id", "name", "regex", "example");
            object_.registerSignal("RegexDeleted").onInterface(INTERFACE_NAME).withParameters<int32_t>("id");
        }

        ~Regex() = default;

    public:
        void emitRegexAdded(const int32_t& id, const std::string& name, const std::string& regex, const std::string& example)
        {
            object_.emitSignal("RegexAdded").onInterface(INTERFACE_NAME).withArguments(id, name, regex, example);
        }

        void emitRegexUpdated(const int32_t& id, const std::string& name, const std::string& regex, const std::string& example)
        {
            object_.emitSignal("RegexUpdated").onInterface(INTERFACE_NAME).withArguments(id, name, regex, example);
        }

        void emitRegexDeleted(const int32_t& id)
        {
            object_.emitSignal("RegexDeleted").onInterface(INTERFACE_NAME).withArguments(id);
        }

    private:
        virtual std::vector<sdbus::Struct<int32_t, std::string, std::string, std::string>> GetRegexes() = 0;
        virtual sdbus::Struct<int32_t, std::string, std::string, std::string> GetRegexById(const int32_t& id) = 0;
        virtual bool SetRegex(const std::string& name, const std::string& regex, const std::string& example) = 0;
        virtual bool UpdateRegex(const int32_t& id, const std::string& name, const std::string& regex, const std::string& example) = 0;
        virtual bool DeleteRegex(const int32_t& id) = 0;

    private:
        sdbus::IObject& object_;
    };

}
} // namespaces