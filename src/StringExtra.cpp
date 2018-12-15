#include "StringExtra.h"

std::string trim(const std::string &s, const char &delimiter) {
    size_t first = s.find_first_not_of(delimiter);

    if (first == std::string::npos) {
        return "";
    }

    size_t last = s.find_last_not_of(delimiter);

    return s.substr(first, (last - first + 1));
}

std::vector <std::string> explode(const std::string &s, const char &delimiter) {
    std::vector <std::string> result;
    std::istringstream iss(s);

    for (std::string token; std::getline(iss, token, delimiter);) {
        result.push_back(std::move(token));
    }

    return result;
}