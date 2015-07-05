//
// Created by wybe on 5-7-15.
//

#pragma once

#include <string>
#include <map>


// The type of map that will hold all the settings.
typedef std::map<std::string, std::string> StringMap;

class Config {

public:
    Config();
    void loadSettings();

public:
    StringMap settings;

private:
    const std::string SETTINGS_FILENAME = "Settings.cfg";
};
