#include "Factory.h"

//  builder:block

std::vector<InputLine> buildBlock(const std::vector<InputLine> &inputLines, int &index, const int &offset)
{
    // Init output vector
    std::vector<InputLine> content;

    // For current line to the end
    for (++index; index < (int)inputLines.size(); index++)
    {
        // Get line
        InputLine line = inputLines[index];

        // If the line offset is lower or equal to the input offset, break
        if (line.getOffset() <= offset)
            break;

        // Otherwise, put the line in the vector & continue
        content.push_back(line);
    }

    // As the last line broke, remove one to index
    --index;

    return content;
}

//  validator:args

bool validateArgs(const InputLine &inputLine, std::vector<std::string> validate)
{
    // Get arguments
    std::vector<std::string> args = inputLine.getArguments();

    // Output error, and return false if args count isn't the good one
    if (args.size() != validate.size())
    {
        std::cout << "Error executing line [" << inputLine.getLine() << "]: candidate (";
        std::cout << inputLine.getInstructionName() << ") expects " << validate.size() << " argument";

        if (validate.size() > 1)
        {
            std::cout << "s";
        }

        std::cout << ", " << args.size() << " provided" << std::endl;

        return false;
    }

    // (BONUS TODO): Check if the args can be transformed (string to int, string to float, multiple a/b/c)

    return true;
}

//  validator:block

bool validateBlock(const InputLine &inputLine, std::string name, mapBlocks &blocks)
{
    // Returns false and output error if the block doesn't exist
    if (blocks.find(name) == blocks.end())
    {
        std::cout << "Error executing line [" << inputLine.getLine() << "]: candidate (";
        std::cout << inputLine.getInstructionName() << ") block " << name << " is not defined" << std::endl;

        return false;
    }

    return true;
}

//  setters:setdefault

bool execSetDefault(Cursor &cursor, const std::vector<InputLine> &inputLines, int &index, mapBlocks &blocks)
{
    // Get stuff
    InputLine inputLine = inputLines[index];
    std::vector<std::string> validate(0);
    std::vector<std::string> arguments = inputLine.getArguments();

    // Validate args
    if (!validateArgs(inputLine, validate))
        return false;

    // Set cursor values to default
    cursor.setPosition(0, 0).setPenOn().setOrientation(0).setColor("FFFFFF").setThickness(1);

    return true;
}

//  setters:setpen

bool execSetPen(Cursor &cursor, const std::vector<InputLine> &inputLines, int &index, mapBlocks &blocks)
{
    // Get stuff
    InputLine inputLine = inputLines[index];
    std::vector<std::string> validate = {"on/off"};
    std::vector<std::string> arguments = inputLine.getArguments();

    // Validate args
    if (!validateArgs(inputLine, validate))
        return false;

    std::string status = arguments[0];

    // Set cursor pen status
    if (status == "on")
        cursor.setPenOn();
    if (status == "off")
        cursor.setPenOff();

    return true;
}

//  setters:setx

bool execSetX(Cursor &cursor, const std::vector<InputLine> &inputLines, int &index, mapBlocks &blocks)
{
    // Get stuff
    InputLine inputLine = inputLines[index];
    std::vector<std::string> validate = {"float"};
    std::vector<std::string> arguments = inputLine.getArguments();

    // Validate args
    if (!validateArgs(inputLine, validate))
        return false;

    // Set cursor x position
    cursor.setX(std::stof(arguments[0]));

    return true;
}

//  setters:sety

bool execSetY(Cursor &cursor, const std::vector<InputLine> &inputLines, int &index, mapBlocks &blocks)
{
    // Get stuff
    InputLine inputLine = inputLines[index];
    std::vector<std::string> validate = {"float"};
    std::vector<std::string> arguments = inputLine.getArguments();

    // Validate args
    if (!validateArgs(inputLine, validate))
        return false;

    // Set cursor y position
    cursor.setY(std::stof(arguments[0]));

    return true;
}

//  setters:setposition

bool execSetPosition(Cursor &cursor, const std::vector<InputLine> &inputLines, int &index, mapBlocks &blocks)
{
    // Get stuff
    InputLine inputLine = inputLines[index];
    std::vector<std::string> validate = {"float", "float"};
    std::vector<std::string> arguments = inputLine.getArguments();

    // Validate args
    if (!validateArgs(inputLine, validate))
        return false;

    // Set x & y position
    cursor.setX(std::stof(arguments[0]));
    cursor.setY(std::stof(arguments[1]));

    return true;
}

//  setters:setorientation

bool execSetOrientation(Cursor &cursor, const std::vector<InputLine> &inputLines, int &index, mapBlocks &blocks)
{
    // Get stuff
    InputLine inputLine = inputLines[index];
    std::vector<std::string> validate = {"float"};
    std::vector<std::string> arguments = inputLine.getArguments();

    // Validate args
    if (!validateArgs(inputLine, validate))
        return false;

    // Set the orientation
    cursor.setOrientation(std::stof(arguments[0]));

    return true;
}

//  setters:setcolor

bool execSetColor(Cursor &cursor, const std::vector<InputLine> &inputLines, int &index, mapBlocks &blocks)
{
    // Get stuff
    InputLine inputLine = inputLines[index];
    std::vector<std::string> validate = {"int", "int", "int"};
    std::vector<std::string> arguments = inputLine.getArguments();

    // Validate args
    if (!validateArgs(inputLine, validate))
        return false;

    // Fetch r, g & b
    char r = std::stoi(arguments[0]);
    char g = std::stoi(arguments[1]);
    char b = std::stoi(arguments[2]);

    // Set the color
    cursor.setColor(r, g, b);

    return true;
}

//  setters:setcolorhex

bool execSetColorHex(Cursor &cursor, const std::vector<InputLine> &inputLines, int &index, mapBlocks &blocks)
{
    // Get stuff
    InputLine inputLine = inputLines[index];
    std::vector<std::string> validate = {"string"};
    std::vector<std::string> arguments = inputLine.getArguments();

    // Validate args
    if (!validateArgs(inputLine, validate))
        return false;

    // Set the color
    cursor.setColor(arguments[0]);

    return true;
}

//  setters:setthickness

bool execSetThickness(Cursor &cursor, const std::vector<InputLine> &inputLines, int &index, mapBlocks &blocks)
{
    // Get stuff
    InputLine inputLine = inputLines[index];
    std::vector<std::string> validate = {"int"};
    std::vector<std::string> arguments = inputLine.getArguments();

    // Validate args
    if (!validateArgs(inputLine, validate))
        return false;

    // Set the thickness
    cursor.setThickness(std::stoi(arguments[0]));

    return true;
}

//  move:rotate

bool execRotate(Cursor &cursor, const std::vector<InputLine> &inputLines, int &index, mapBlocks &blocks)
{
    // Get stuff
    InputLine inputLine = inputLines[index];
    std::vector<std::string> validate = {"float"};
    std::vector<std::string> arguments = inputLine.getArguments();

    // Validate args
    if (!validateArgs(inputLine, validate))
        return false;

    // Fetch angle
    float angle = std::stof(arguments[0]);

    // Execute rotate
    cursor.rotate(angle);

    return true;
}

//  move:forward

bool execForward(Cursor &cursor, const std::vector<InputLine> &inputLines, int &index, mapBlocks &blocks)
{
    // Get stuff
    InputLine inputLine = inputLines[index];
    std::vector<std::string> validate = {"float"};
    std::vector<std::string> arguments = inputLine.getArguments();

    // Validate args
    if (!validateArgs(inputLine, validate))
        return false;

    // Fetch distance
    float distance = std::stof(arguments[0]);

    // Execute forward
    cursor.forward(distance);

    return true;
}

//  move:backward

bool execBackward(Cursor &cursor, const std::vector<InputLine> &inputLines, int &index, mapBlocks &blocks)
{
    // Get stuff
    InputLine inputLine = inputLines[index];
    std::vector<std::string> validate = {"float"};
    std::vector<std::string> arguments = inputLine.getArguments();

    // Validate args
    if (!validateArgs(inputLine, validate))
        return false;

    // Fetch distance
    float distance = std::stof(arguments[0]);

    // Execute backward
    cursor.backward(distance);

    return true;
}

//  move:left

bool execLeft(Cursor &cursor, const std::vector<InputLine> &inputLines, int &index, mapBlocks &blocks)
{
    // Get stuff
    InputLine inputLine = inputLines[index];
    std::vector<std::string> validate = {"float"};
    std::vector<std::string> arguments = inputLine.getArguments();

    // Validate args
    if (!validateArgs(inputLine, validate))
        return false;

    // Fetch angle
    float angle = std::stof(arguments[0]);

    // Execute left
    cursor.left(angle);

    return true;
}

//  move:right

bool execRight(Cursor &cursor, const std::vector<InputLine> &inputLines, int &index, mapBlocks &blocks)
{
    // Get stuff
    InputLine inputLine = inputLines[index];
    std::vector<std::string> validate = {"float"};
    std::vector<std::string> arguments = inputLine.getArguments();

    // Validate args
    if (!validateArgs(inputLine, validate))
        return false;

    // Fetch angle
    float angle = std::stof(arguments[0]);

    // Execute right
    cursor.right(angle);

    return true;
}

//  move:arc

bool execArc(Cursor &cursor, const std::vector<InputLine> &inputLines, int &index, mapBlocks &blocks)
{
    // Get stuff
    InputLine inputLine = inputLines[index];
    std::vector<std::string> validate = {"int", "float"};
    std::vector<std::string> arguments = inputLine.getArguments();

    // Validate args
    if (!validateArgs(inputLine, validate))
        return false;

    // Fetch angle & radius
    int angle = std::stoi(arguments[0]);
    float radius = std::stof(arguments[1]);

    // Execute a circle arc
    cursor.arc(angle, radius);

    return true;
}

//  block:repeat

bool execRepeat(Cursor &cursor, const std::vector<InputLine> &inputLines, int &index, mapBlocks &blocks)
{
    // Get stuff
    InputLine inputLine = inputLines[index];
    std::vector<std::string> validate = {"int"};
    std::vector<std::string> arguments = inputLine.getArguments();

    // Validate args
    if (!validateArgs(inputLine, validate))
        return false;

    // Fetch iterations
    int n = std::stoi(arguments[0]);

    // Build content
    std::vector<InputLine> content = buildBlock(inputLines, index, inputLine.getOffset());

    // Repeat the run n times
    for (int i = 0; i < n; i++)
    {
        if (!run(cursor, content, blocks))
            return false;
    }

    return true;
}

//  block:block

bool execBlock(Cursor &cursor, const std::vector<InputLine> &inputLines, int &index, mapBlocks &blocks)
{
    // Get stuff
    InputLine inputLine = inputLines[index];
    std::vector<std::string> validate = {"string"};
    std::vector<std::string> arguments = inputLine.getArguments();

    // Validate args
    if (!validateArgs(inputLine, validate))
        return false;

    // Fetch block name
    std::string name = arguments[0];

    // Build content
    std::vector<InputLine> content = buildBlock(inputLines, index, inputLine.getOffset());

    // Push the block
    blocks[name] = content;

    return true;
}

//  block:call

bool execCall(Cursor &cursor, const std::vector<InputLine> &inputLines, int &index, mapBlocks &blocks)
{
    // Get stuff
    InputLine inputLine = inputLines[index];
    std::vector<std::string> validate = {"string"};
    std::vector<std::string> arguments = inputLine.getArguments();

    // Validate args
    if (!validateArgs(inputLine, validate))
        return false;

    // Fetch name
    std::string name = arguments[0];

    // Validate block
    if (!validateBlock(inputLine, name, blocks))
        return false;

    // Fetch content
    std::vector<InputLine> content = blocks[name];

    // Run it
    run(cursor, content, blocks);

    return true;
}

//  runner:run

bool run(Cursor &cursor, const std::vector<InputLine> &inputLines, mapBlocks &blocks)
{
    // Defines instructions map, with pointers on executors function
    std::map<std::string, instruction *> instructions;

    instructions["setdefault"] = execSetDefault;
    instructions["setpen"] = execSetPen;
    instructions["setx"] = execSetX;
    instructions["sety"] = execSetY;
    instructions["setposition"] = execSetPosition;
    instructions["setorientation"] = execSetOrientation;
    instructions["setcolor"] = execSetColor;
    instructions["setcolorhex"] = execSetColorHex;
    instructions["setthickness"] = execSetThickness;
    instructions["rotate"] = execRotate;
    instructions["forward"] = execForward;
    instructions["backward"] = execBackward;
    instructions["left"] = execLeft;
    instructions["right"] = execRight;
    instructions["arc"] = execArc;
    instructions["repeat"] = execRepeat;
    instructions["block"] = execBlock;
    instructions["call"] = execCall;

    for (int index = 0; index < (int)inputLines.size(); index++)
    {
        // Get line
        InputLine inputLine = inputLines[index];

        // Get instruction
        std::string instructionName = inputLine.getInstructionName();

        // Check if the instruction exist
        if (instructions.find(instructionName) != instructions.end())
        {
            // Execute it, return false if there is a problem
            if (!instructions.find(inputLine.getInstructionName())->second(cursor, inputLines, index, blocks))
                return false;

            // Or if the line is empty or a comment
        }
        else if (instructionName != "comment" && instructionName != "null")
        {
            // Otherwise, output error & return false
            std::cout << "Error executing line [" << inputLine.getLine() << "]: Unknown instruction: ";
            std::cout << instructionName << std::endl;

            return false;
        }
    }

    return true;
}