#include "Robot.h"

//////////////////////////////////////////////////
// Constructors
//////////////////////////////////////////////////

Robot::Robot(Cursor *cursor, std::vector <InputLine> inputLines) :
        cursor(cursor), inputLines(inputLines), index(0) {};

//////////////////////////////////////////////////
// Setters
//////////////////////////////////////////////////

Robot &Robot::pushLine(InputLine inputLine) {
    this->inputLines.push_back(inputLine);

    return *this;
}

Robot &Robot::setBlocks(std::map <std::string, std::vector<InputLine>> blocks) {
    this->blocks = blocks;

    return *this;
}

//////////////////////////////////////////////////
// Methods
//////////////////////////////////////////////////

///////////////////
//  Basic
///////////////////

//  basic:say

bool Robot::execSay(const InputLine &inputLine) const {
    std::vector <std::string> arguments = inputLine.getArguments();

    for (unsigned int i = 0; i < arguments.size(); i++) {
        std::cout << arguments[i];
        if (i < arguments.size() - 1) std::cout << " ";
    }

    std::cout << std::endl;

    return true;
}

//  basic:pause

bool Robot::execPause(const InputLine &inputLine) const {
    std::vector <std::string> arguments = inputLine.getArguments();

    if (!expectArgumentsCount(inputLine, 0)) { return false; }

    std::cin.get();

    return true;
}

//  basic:exit

bool Robot::execExit(const InputLine &inputLine) const {
    std::vector <std::string> arguments = inputLine.getArguments();

    if (!expectArgumentsCount(inputLine, 1)) { return false; }

    exit(std::stoi(arguments[0]));

    return true;
}

///////////////////
//  Setters
///////////////////

//  setters:setdefault

bool Robot::execSetDefault(const InputLine &inputLine) {
    std::vector <std::string> arguments = inputLine.getArguments();

    if (!expectArgumentsCount(inputLine, 0)) { return false; }

    cursor->setPenOn();
    cursor->setPosition(0, 0);
    cursor->setOrientation(0);
    cursor->setColor("FFFFFF");
    cursor->setThickness(1);

    return true;
}

//  setters:setpen

bool Robot::execSetPen(const InputLine &inputLine) {
    std::vector <std::string> arguments = inputLine.getArguments();
    std::vector <std::string> status = {"on", "off"};

    if (!expectArgumentsCount(inputLine, 1)) { return false; }
    if (!expectArgumentToBe(inputLine, 0, status)) { return false; }

    if (arguments[0] == "on") { cursor->setPenStatus(true); }
    else { cursor->setPenStatus(false); }

    return true;
}

//  setters:setx

bool Robot::execSetX(const InputLine &inputLine) {
    std::vector <std::string> arguments = inputLine.getArguments();

    if (!expectArgumentsCount(inputLine, 1)) { return false; }

    cursor->setX(std::stof(arguments[0]));

    return true;
}

//  setters:sety

bool Robot::execSetY(const InputLine &inputLine) {
    std::vector <std::string> arguments = inputLine.getArguments();

    if (!expectArgumentsCount(inputLine, 1)) { return false; }

    cursor->setY(std::stof(arguments[0]));

    return true;
}

//  setters:setposition

bool Robot::execSetPosition(const InputLine &inputLine) {
    std::vector <std::string> arguments = inputLine.getArguments();

    if (!expectArgumentsCount(inputLine, 2)) { return false; }

    cursor->setX(std::stof(arguments[0]));
    cursor->setY(std::stof(arguments[1]));

    return true;
}

//  setters:setorientation

bool Robot::execSetOrientation(const InputLine &inputLine) {
    std::vector <std::string> arguments = inputLine.getArguments();

    if (!expectArgumentsCount(inputLine, 1)) { return false; }

    cursor->setOrientation(std::stof(arguments[0]));

    return true;
}

//  setters:setcolor

bool Robot::execSetColor(const InputLine &inputLine) {
    std::vector <std::string> arguments = inputLine.getArguments();

    if (!expectArgumentsCount(inputLine, 3)) { return false; }

    char r = (char) std::stoi(arguments[0]);
    char g = (char) std::stoi(arguments[1]);
    char b = (char) std::stoi(arguments[2]);

    cursor->setColor(r, g, b);

    return true;
}

//  setters:setcolorhex

bool Robot::execSetColorHex(const InputLine &inputLine) {
    std::vector <std::string> arguments = inputLine.getArguments();

    if (!expectArgumentsCount(inputLine, 1)) { return false; }

    cursor->setColor(arguments[0]);

    return true;
}

//  setters:setthickness

bool Robot::execSetThickness(const InputLine &inputLine) {
    std::vector <std::string> arguments = inputLine.getArguments();

    if (!expectArgumentsCount(inputLine, 1)) { return false; }

    cursor->setThickness(std::stoi(arguments[0]));

    return true;
}

///////////////////
//  Instructions
///////////////////

//  instruction:rotate

bool Robot::execRotate(const InputLine &inputLine) {
    std::vector <std::string> arguments = inputLine.getArguments();

    if (!expectArgumentsCount(inputLine, 1)) { return false; }

    cursor->rotate(std::stof(arguments[0]));

    return true;
}

//  instruction:forward

bool Robot::execForward(const InputLine &inputLine) {
    std::vector <std::string> arguments = inputLine.getArguments();

    if (!expectArgumentsCount(inputLine, 1)) { return false; }

    cursor->forward(std::stof(arguments[0]));

    return true;
}

//  instruction:backward

bool Robot::execBackward(const InputLine &inputLine) {
    std::vector <std::string> arguments = inputLine.getArguments();

    if (!expectArgumentsCount(inputLine, 1)) { return false; }

    cursor->backward(std::stof(arguments[0]));

    return true;
}

//  instruction:left

bool Robot::execLeft(const InputLine &inputLine) {
    std::vector <std::string> arguments = inputLine.getArguments();

    if (!expectArgumentsCount(inputLine, 1)) { return false; }

    cursor->left(std::stof(arguments[0]));

    return true;
}

//  instruction:right

bool Robot::execRight(const InputLine &inputLine) {
    std::vector <std::string> arguments = inputLine.getArguments();

    if (!expectArgumentsCount(inputLine, 1)) { return false; }

    cursor->right(std::stof(arguments[0]));

    return true;
}

//  instruction:arc

bool Robot::execArc(const InputLine &inputLine) {
    std::vector <std::string> arguments = inputLine.getArguments();

    if (!expectArgumentsCount(inputLine, 2)) { return false; }

    cursor->arc(std::stoi(arguments[0]), std::stoi(arguments[1]));

    return true;
}

///////////////////
//  Blocks
///////////////////

//  block:repeat

bool Robot::blockRepeat(const InputLine &inputLine) {
    std::vector <std::string> arguments = inputLine.getArguments();

    if (!expectArgumentsCount(inputLine, 1)) { return false; }

    unsigned int n = abs(std::stoi(arguments[0]));

    std::vector <InputLine> content;

    for (unsigned int i = (index + 1); i < inputLines.size(); i++) {
        InputLine line = inputLines[i];
        int offset = line.getOffset();

        if (offset <= inputLine.getOffset()) {
            break;
        }

        content.push_back(line);
    }

    for (unsigned int i = 0; i < n; i++) {
        if (!Robot(cursor, content).setBlocks(blocks).run()) return false;
    }

    index += content.size();

    return true;
}

//  block:block

bool Robot::blockBlock(const InputLine &inputLine) {
    std::vector <std::string> arguments = inputLine.getArguments();

    if (!expectArgumentsCount(inputLine, 1)) { return false; }

    std::string name = arguments[0];

    std::vector <InputLine> content;

    for (unsigned int i = (index + 1); i < inputLines.size(); i++) {
        InputLine line = inputLines[i];
        int offset = line.getOffset();

        if (offset <= inputLine.getOffset()) {
            break;
        }

        content.push_back(line);
    }

    blocks[name] = content;

    index += content.size();

    return true;
}

//  block:call

bool Robot::blockCall(const InputLine &inputLine) {
    std::vector <std::string> arguments = inputLine.getArguments();

    if (!expectArgumentsCount(inputLine, 1)) { return false; }

    std::string name = arguments[0];

    if (!expectBlockExists(inputLine, name)) { return false; }

    std::vector <InputLine> content = blocks[name];

    if (!Robot(cursor, content).setBlocks(blocks).run()) { return false; }

    return true;
}

///////////////////
//  Run
///////////////////

bool Robot::run() {
    for (index = 0; index < inputLines.size(); index++) {
        InputLine inputLine = inputLines[index];

        std::string instruction = inputLine.getInstructionName();
        std::vector <std::string> arguments = inputLine.getArguments();

        if (instruction == "say") {
            if (execSay(inputLine)) continue;
            return false;
        } else if (instruction == "pause") {
            if (execPause(inputLine)) continue;
            return false;
        } else if (instruction == "exit") {
            if (execExit(inputLine)) continue;
            return false;
        } else if (instruction == "setdefault") {
            if (execSetDefault(inputLine)) continue;
            return false;
        } else if (instruction == "setpen") {
            if (execSetPen(inputLine)) continue;
            return false;
        } else if (instruction == "setx") {
            if (execSetX(inputLine)) continue;
            return false;
        } else if (instruction == "sety") {
            if (execSetY(inputLine)) continue;
            return false;
        } else if (instruction == "setposition") {
            if (execSetPosition(inputLine)) continue;
            return false;
        } else if (instruction == "setorientation") {
            if (execSetOrientation(inputLine)) continue;
            return false;
        } else if (instruction == "setcolor") {
            if (execSetColor(inputLine)) continue;
            return false;
        } else if (instruction == "setcolorhex") {
            if (execSetColorHex(inputLine)) continue;
            return false;
        } else if (instruction == "setthickness") {
            if (execSetThickness(inputLine)) continue;
            return false;
        } else if (instruction == "rotate") {
            if (execRotate(inputLine)) continue;
            return false;
        } else if (instruction == "forward") {
            if (execForward(inputLine)) continue;
            return false;
        } else if (instruction == "backward") {
            if (execBackward(inputLine)) continue;
            return false;
        } else if (instruction == "left") {
            if (execLeft(inputLine)) continue;
            return false;
        } else if (instruction == "arc") {
            if (execArc(inputLine)) continue;
            return false;
        } else if (instruction == "right") {
            if (execRight(inputLine)) continue;
            return false;
        } else if (instruction == "repeat") {
            if (blockRepeat(inputLine)) continue;
            return false;
        } else if (instruction == "block") {
            if (blockBlock(inputLine)) continue;
            return false;
        } else if (instruction == "call") {
            if (blockCall(inputLine)) continue;
            return false;
        } else if (instruction == "comment" || instruction == "null") {
            continue;
        } else {
            std::cout << "Error executing line [" << inputLine.getLine() << "]: Unknown instruction: ";
            std::cout << instruction << std::endl;

            return false;
        }
    }

    return true;
}

//////////////////////////////////////////////////
// Private Methods
//////////////////////////////////////////////////

bool Robot::expectArgumentsCount(const InputLine &inputLine, const int &expectedArguments) const {
    int provided = inputLine.getArguments().size();

    if (provided != expectedArguments) {
        std::cout << "Error executing line [" << inputLine.getLine() << "]: candidate (";
        std::cout << inputLine.getInstructionName() << ") expects " << expectedArguments << " argument";

        if (expectedArguments > 1) { std::cout << "s"; }

        std::cout << ", " << provided << " provided" << std::endl;

        return false;
    }

    return true;
}

bool Robot::expectArgumentToBe(const InputLine &inputLine, const int &index, const std::vector <std::string> &values) const {
    std::string provided = inputLine.getArguments()[index];

    if (std::find(values.begin(), values.end(), provided) == values.end()) {
        std::cout << "Error executing line [" << inputLine.getLine() << "]: candidate (";
        std::cout << inputLine.getInstructionName() << ") expects argument " << index + 1 << " to be ";

        for (unsigned int i = 0; i < values.size(); i++) {
            std::cout << "\"" << values[i] << "\"";
            if (i < values.size() - 1) std::cout << ", or ";
        }

        std::cout << "; provided: " << provided << std::endl;

        return false;
    }

    return true;
}

bool Robot::expectBlockExists(const InputLine &inputLine, const std::string &name) const {
    if (blocks.find(name) == blocks.end()) {
        std::cout << "Error executing line [" << inputLine.getLine() << "]: candidate (";
        std::cout << inputLine.getInstructionName() << ") block " << name << " is not defined" << std::endl;

        return false;
    }

    return true;
}