#ifndef TURTLE_DRAWING_ROBOT_H
#define TURTLE_DRAWING_ROBOT_H

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "Cursor.h"
#include "InputLine.h"

class Robot {
public:
    Robot(Cursor *cursor, std::vector <InputLine> inputLines = std::vector<InputLine>(0));

    // --------------- Setters --------------- //

    Robot &pushLine(InputLine inputLine);

    Robot &setBlocks(std::map <std::string, std::vector <InputLine>> blocks);

    // --------------- Methods --------------- //

    //  Basics

    bool execSay(const InputLine &inputLine) const;

    bool execPause(const InputLine &inputLine) const;

    bool execExit(const InputLine &inputLine) const;

    //  Setters

    bool execSetDefault(const InputLine &inputLine);

    bool execSetPen(const InputLine &inputLine);

    bool execSetX(const InputLine &inputLine);

    bool execSetY(const InputLine &inputLine);

    bool execSetPosition(const InputLine &inputLine);

    bool execSetOrientation(const InputLine &inputLine);

    bool execSetColor(const InputLine &inputLine);

    bool execSetColorHSL(const InputLine &inputLine);

    bool execSetColorHex(const InputLine &inputLine);

    bool execSetThickness(const InputLine &inputLine);

    //  Instructions

    bool execRotate(const InputLine &inputLine);

    bool execForward(const InputLine &inputLine);

    bool execBackward(const InputLine &inputLine);

    bool execLeft(const InputLine &inputLine);

    bool execRight(const InputLine &inputLine);

    bool execArc(const InputLine &inputLine);

    //  Blocks

    bool blockRepeat(const InputLine &inputLine);

    bool blockBlock(const InputLine &inputLine);

    bool blockCall(const InputLine &inputLine);

    //  Run

    bool run();

private:
    Cursor* cursor;

    unsigned int index;
    std::vector <InputLine> inputLines;
    std::map <std::string, std::vector <InputLine>> blocks;

    bool expectArgumentsCount(const InputLine &inputLine, const int &expectedArguments) const;
    bool expectArgumentToBe(const InputLine &inputLine, const int &index, const std::vector<std::string> &values) const;
    bool expectBlockExists(const InputLine &inputLine, const std::string &name) const;
};

typedef bool executor(Robot &robot, InputLine inputLine);

#endif //TURTLE_DRAWING_ROBOT_H
