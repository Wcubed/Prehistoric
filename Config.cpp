//
// Created by wybe on 5-7-15.
//

#include "Config.h"

#include <fstream>
#include <iostream>

#include "stringutils.h"


Config::Config() {
    settings = StringMap(); // Create the string map

    // Start with the defaults
    settings.emplace("antialiasing", "8");
}

void Config::loadSettings() {
    /* Loads the settings from the settings file
     * and overrides the defaults with the settings found.
     */

    std::ifstream setfile;
    std::string line;

    // Open the settings file for reading
    setfile.open(SETTINGS_FILENAME, std::ios_base::in);

    // Parse all the lines
    while (std::getline(setfile, line))
    {
        // Setting lines look like this: KEY:VALUE
        unsigned long size_key;
        std::string key, value;

        // Find the delimiter "="
        size_key = line.find("=");

        key = line.substr(0, size_key);
        value = line.substr(size_key + 1, std::string::npos);

        // Trim the whitespaces
        key = str::trim(key);
        value = str::trim(value);

        // Check if both the key and the value are nonzero
        if (key != "" and value != "")
        {
            // If the key exists
            if (settings.count(key) != 0)
            {
                settings[key] = value;
            }
        }
    }

    // Close the settings file
    setfile.close();
}
