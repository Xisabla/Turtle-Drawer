#ifndef TURTLE_DRAWING_INPUTLINE_H
#define TURTLE_DRAWING_INPUTLINE_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "StringExtra.h"

#define TAB "   "

class InputLine {
public:
    InputLine();

    InputLine(std::string line, const int &l = 0);

    int getLine() const;

    int getOffset() const;

    std::string getInstructionName() const;

    std::vector <std::string> getArguments() const;

    friend std::ostream &operator<<(std::ostream &os, const InputLine &input);

    static std::vector <InputLine> parseFile(std::ifstream &input);

    static std::vector <std::string> errorHandler;

private:
    int parseOffset(std::string &line);

    std::string parseInstructionName(std::string &line);

    std::vector <std::string> parseArguments(std::string &line, const int &l);

    int line;
    int offset;
    std::string instructionName;
    std::vector <std::string> arguments;
};

#endif //TURTLE_DRAWING_INPUTLINE_H
