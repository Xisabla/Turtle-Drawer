#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Cursor.h"
#include "InputLine.h"
#include "Robot.h"

#define DEFAULT_INPUT_FILE "instructions.txt"

using namespace std;

int main(int argc, char **argv) {
    string input_file = (argc > 1) ? argv[1] : DEFAULT_INPUT_FILE;
    ifstream input(input_file);

    vector <InputLine> inputLines = InputLine::parseFile(input);

    if (InputLine::errorHandler.size() > 0) {
        for (auto &err : InputLine::errorHandler) cout << err << endl;
        return 1;
    }

    sf::RenderWindow window(sf::VideoMode(1300, 700), "Turtle Drawing: Render");

    Cursor cursor(&window);

    Robot robot(&cursor, inputLines);

    if (!robot.run()) { return 1; }

    cursor.render();

    return 0;
}