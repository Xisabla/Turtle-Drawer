#ifndef TURTLE_DRAWING_STRINGEXTRA_H
#define TURTLE_DRAWING_STRINGEXTRA_H

#include <sstream>
#include <string>
#include <vector>

std::string trim(const std::string &s, const char &delimiter = ' ');

std::vector <std::string> explode(const std::string &s, const char &delimiter = ' ');

#endif //TURTLE_DRAWING_STRINGEXTRA_H
