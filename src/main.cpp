#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>

#include "Cursor.h"
#include "Factory.h"
#include "InputLine.h"

#define DEFAULT_INPUT_FILE "instructions.txt"

using namespace std;

int main(int argc, char **argv) {
    // Opening the input file
    string input_file = (argc > 1) ? argv[1] : DEFAULT_INPUT_FILE;
    ifstream input(input_file);

    // Initializing empty blocks map for the Factory
    map <string, vector <InputLine>> blocks;

    // Parsing input file into inputLines vector
    vector <InputLine> inputLines = InputLine::parseFile(input);

    // Checking for parsing errors
    if (InputLine::errorHandler.size() > 0) {
        for (auto &err : InputLine::errorHandler) cout << err << endl;
        return 1;
    }

    // Initializing a basic window
    sf::RenderWindow window(sf::VideoMode(1300, 700), "Turtle Drawing: Render");

    // Initializing the cursor with the window
    Cursor cursor(&window);

    // Running the Factory, if return false, stop the program (there is a problem)
    if(!run(cursor, inputLines, blocks)) return 1;

    // Render the window with the cursor draws
    cursor.render();

    return 0;
}