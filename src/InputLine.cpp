#include "InputLine.h"

std::vector <std::string> InputLine::errorHandler;

//////////////////////////////////////////////////
// Constructors
//////////////////////////////////////////////////

InputLine::InputLine() : offset(-1), instructionName(), arguments() {};

InputLine::InputLine(std::string line, const int &l) : InputLine() {
    // If line is empty, put default data for empty lines
    if (line.size() == 0) {
        offset = -1;
        instructionName = "null";
        arguments = std::vector<std::string>(0);
    } else {
        // If the line is juste a comment, put default data for comment lines
        if (trim(explode(line, '#')[0]).size() == 0) {
            offset = -1;
            instructionName = "comment";
            arguments = std::vector<std::string>(0);
        } else {
        // Get offset, instruction & arguments
            offset = parseOffset(line);
            instructionName = parseInstructionName(line);
            arguments = parseArguments(line, l);
        }
    }

    // Set line
    this->line = l;

};

//////////////////////////////////////////////////
// Getters
//////////////////////////////////////////////////

int InputLine::getLine() const { return line; }

int InputLine::getOffset() const { return offset; }

std::string InputLine::getInstructionName() const { return instructionName; }

std::vector <std::string> InputLine::getArguments() const { return arguments; }

//////////////////////////////////////////////////
// Operators
//////////////////////////////////////////////////

std::ostream &operator<<(std::ostream &os, const InputLine &input) {
    os << "------- INPUT LINE -------" << std::endl;
    os << "InstructionName: " << input.instructionName << std::endl;
    os << "Arguments: ";
    for (auto &arg : input.arguments) os << " |" << arg << "| ";
    os << std::endl;
    os << "Offset: " << input.offset << std::endl;
    os << "---------- END -----------" << std::endl;

    return os;
}

//////////////////////////////////////////////////
// Methods
//////////////////////////////////////////////////

int InputLine::parseOffset(std::string &line) const {
    int firstTab = line.find_first_not_of(TAB);
    int firstSpace = line.find_first_not_of(" ");

    // Determine of the offset is done with spaces or tabs
    int offset = (firstSpace > firstTab) ? firstSpace : firstTab;

    // Returns the offset, automatically find if it's 4 spaces or 1
    return (offset % 4 == 0) ? offset / 4 : offset;
}

std::string InputLine::parseInstructionName(std::string &line) {
    // Remove spaces
    line = trim(line);

    // First word is the instruction
    std::string instructionName = explode(line, ' ')[0];

    // Remove instruction name from the line
    line.erase(0, instructionName.size() + 1);

    return instructionName;
}

std::vector <std::string> InputLine::parseArguments(std::string &line, const int &l) {
    if (line.size() == 0) return std::vector<std::string>(0);

    // Purge comments
    std::string commentPurged = explode(line, '#')[0];

    // Init vector
    std::vector <std::string> arguments;

    // Count number of quotes chars
    size_t n = std::count(commentPurged.begin(), commentPurged.end(), '"');

    // If quotes chars is not a multiple of 2;, there is a problem
    if (n % 2 != 0) {
        std::string errorMsg = "Error parsing line [";
        errorMsg += std::to_string(l);
        errorMsg += "]: Invalid quotes";

        InputLine::errorHandler.push_back(errorMsg);

        return arguments;
    }

    // If no quotes, just explode spaces
    if (n == 0) { return explode(commentPurged, ' '); }

    // Otherwise, explode quotes
    std::vector <std::string> marksExploded = explode(commentPurged, '"');

    // For each string outside of a quote, explode spaces
    for (unsigned int i = 0; i < marksExploded.size(); i++) {
        if (i % 2 == 1) { arguments.push_back(marksExploded[i]); }

        else if (marksExploded[i].size() != 0) {
            for (auto &arg : explode(marksExploded[i], ' ')) {
                if (arg.size() > 0) arguments.push_back(arg);
            }
        }
    }

    return arguments;
}

//////////////////////////////////////////////////
// Static
//////////////////////////////////////////////////

std::vector <InputLine> InputLine::parseFile(std::ifstream &input) {
    std::vector <InputLine> result;
    std::string line;

    int n = 0;

    // For each line
    while (getline(input, line)) {
        // Increase the line counter
        n++;

        // Push the InputLine
        result.push_back(InputLine(line, n));
    }

    return result;
}