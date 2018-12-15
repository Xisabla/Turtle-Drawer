#ifndef TURTLE_DRAWER_FACTORY_H
#define TURTLE_DRAWER_FACTORY_H

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "Cursor.h"
#include "InputLine.h"

#define mapBlocks std::map <std::string, std::vector <InputLine>>

typedef bool instruction(Cursor &cursor, const std::vector <InputLine> &inputLines, int &index, mapBlocks &blocks);

//  builders

std::vector <InputLine> buildBlock(const std::vector <InputLine> &inputLines, int &index, const int &offset = 0);

//  validators

bool validateArgs(const InputLine &inputLine, std::vector <std::string> validate);

bool validateBlock(const InputLine &inputLine, std::string name, mapBlocks &blocks);

//  setters

bool execSetDefault(Cursor &cursor, const std::vector <InputLine> &inputLines, int &index, mapBlocks &blocks);

bool execSetPen(Cursor &cursor, const std::vector <InputLine> &inputLines, int &index, mapBlocks &blocks);

bool execSetX(Cursor &cursor, const std::vector <InputLine> &inputLines, int &index, mapBlocks &blocks);

bool execSetY(Cursor &cursor, const std::vector <InputLine> &inputLines, int &index, mapBlocks &blocks);

bool execSetPosition(Cursor &cursor, const std::vector <InputLine> &inputLines, int &index, mapBlocks &blocks);

bool execSetOrientation(Cursor &cursor, const std::vector <InputLine> &inputLines, int &index, mapBlocks &blocks);

bool execSetColor(Cursor &cursor, const std::vector <InputLine> &inputLines, int &index, mapBlocks &blocks);

bool execSetColorHex(Cursor &cursor, const std::vector <InputLine> &inputLines, int &index, mapBlocks &blocks);

bool execSetThickness(Cursor &cursor, const std::vector <InputLine> &inputLines, int &index, mapBlocks &blocks);

//  moves

bool execRotate(Cursor &cursor, const std::vector <InputLine> &inputLines, int &index, mapBlocks &blocks);

bool execForward(Cursor &cursor, const std::vector <InputLine> &inputLines, int &index, mapBlocks &blocks);

bool execBackward(Cursor &cursor, const std::vector <InputLine> &inputLines, int &index, mapBlocks &blocks);

bool execLeft(Cursor &cursor, const std::vector <InputLine> &inputLines, int &index, mapBlocks &blocks);

bool execRight(Cursor &cursor, const std::vector <InputLine> &inputLines, int &index, mapBlocks &blocks);

bool execArc(Cursor &cursor, const std::vector <InputLine> &inputLines, int &index, mapBlocks &blocks);

//  blocks

bool execRepeat(Cursor &cursor, const std::vector <InputLine> &inputLines, int &index, mapBlocks &blocks);

bool execBlock(Cursor &cursor, const std::vector <InputLine> &inputLines, int &index, mapBlocks &blocks);

bool execCall(Cursor &cursor, const std::vector <InputLine> &inputLines, int &index, mapBlocks &blocks);

//  runner

bool run(Cursor &cursor, const std::vector<InputLine> &inputLines, mapBlocks &blocks);

#endif //TURTLE_DRAWER_FACTORY_H
