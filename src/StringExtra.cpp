#include "StringExtra.h"

std::string trim(const std::string &s, const char &delimiter) {
    // Find the first char that is not the delimiter
    size_t first = s.find_first_not_of(delimiter);

    // If it's the last char, returns empty string
    if (first == std::string::npos) {
        return "";
    }

    // Find the last char that is not the delimiter
    size_t last = s.find_last_not_of(delimiter);

    // Trim with substr
    return s.substr(first, (last - first + 1));
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  I found this method on stackoverflow:
//
//      https://stackoverflow.com/questions/12966957/is-there-an-equivalent-in-c-of-phps-explode-function
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

std::vector <std::string> explode(const std::string &s, const char &delimiter) {
    std::vector <std::string> result;
    std::istringstream iss(s);

    for (std::string token; std::getline(iss, token, delimiter);) {
        result.push_back(std::move(token));
    }

    return result;
}