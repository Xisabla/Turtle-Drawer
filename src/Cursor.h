#ifndef TURTLE_DRAWING_CURSOR_H
#define TURTLE_DRAWING_CURSOR_H

#include <SFML/Graphics.hpp>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

class Cursor {
public:
    Cursor(sf::RenderWindow *window, float x = 0, float y = 0, float orientation = 0, int thickness = 1,
           sf::Color color = sf::Color(225, 225, 255));

    // --------------- Getters --------------- //

    bool isPenOn() const;

    float getX() const;

    float getY() const;

    float getOrientation() const;

    int getThickness() const;

    sf::Color getColor() const;

    // --------------- Setters --------------- //

    Cursor &setPenStatus(const bool &status);

    Cursor &setPenOn();

    Cursor &setPenOff();

    Cursor &setX(const float &x);

    Cursor &setY(const float &y);

    Cursor &setPosition(const float &x, const float &y);

    Cursor &setOrientation(const float &angle);

    Cursor &setColor(const sf::Color &color);

    Cursor &setColor(const char &r, const char &g, const char &b);

    Cursor &setColor(const std::string &hex);

    Cursor &setThickness(const int &thickness);

    // --------------- Methods --------------- //

    Cursor &rotate(const float &rotation);

    Cursor &forward(const float &distance);

    Cursor &backward(const float &distance);

    Cursor &right(const float &angle);

    Cursor &left(const float &angle);

    Cursor &arc(const int &angle, const int &radius);

    void render();

private:
    bool penOn;

    float x;
    float y;

    float orientation;
    int thickness;

    std::vector<sf::RectangleShape> lines;
    sf::Color color;
    sf::RenderWindow *window;
};

#endif //TURTLE_DRAWING_CURSOR_H
