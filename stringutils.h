//
// Created by wybe on 4-7-15.
//

#pragma once


#include <string>

namespace str {

    const std::string WHITESPACE = " \n\r\t"; // Specifies what counts as a whitespace

    std::string trimRight(const std::string& s) {
        /*
         * Trims whitespaces of the left side of a sting
         */

        size_t startpos = s.find_first_not_of(WHITESPACE);
        return (startpos == std::string::npos) ? "" : s.substr(startpos);
    }

    std::string trimLeft(const std::string& s) {
        /*
         * Trims whitespaces of the left side of a sting
         */

        size_t endpos = s.find_last_not_of(WHITESPACE);
        return (endpos == std::string::npos) ? "" : s.substr(0, endpos+1);
    }

    std::string trim(const std::string& s) {
        /*
         * Trims whitespaces of both ends of a string
         */

        return trimRight(trimLeft(s));
    }
}