#include "Cursor.h"

//////////////////////////////////////////////////
// Constructors
//////////////////////////////////////////////////

Cursor::Cursor(sf::RenderWindow *window, float x, float y, float orientation, int thickness, sf::Color color) :
        window(window), x(x), y(y), orientation(orientation), thickness(thickness), color(color), penOn(true) {};

//////////////////////////////////////////////////
// Getters
//////////////////////////////////////////////////

bool Cursor::isPenOn() const { return penOn; }

float Cursor::getX() const { return x; }

float Cursor::getY() const { return y; }

float Cursor::getOrientation() const { return orientation; }

//////////////////////////////////////////////////
// Setters
//////////////////////////////////////////////////

Cursor &Cursor::setPenStatus(const bool &status) {
    this->penOn = status;

    return *this;
}

Cursor &Cursor::setPenOn() {
    this->penOn = true;

    return *this;
}

Cursor &Cursor::setPenOff() {
    this->penOn = false;

    return *this;
}

Cursor &Cursor::setX(const float &x) {
    this->x = x;

    return *this;
}

Cursor &Cursor::setY(const float &y) {
    this->y = y;

    return *this;
}

Cursor &Cursor::setPosition(const float &x, const float &y) {
    this->x = x;
    this->y = y;

    return *this;
}

Cursor &Cursor::setOrientation(const float &angle) {
    this->orientation = angle;

    return *this;
}

Cursor &Cursor::setColor(const sf::Color &color) {
    this->color = color;

    return *this;
}

Cursor &Cursor::setColor(const char &r, const char &g, const char &b) {
    return setColor(sf::Color(r, g, b));
}

Cursor &Cursor::setColor(const std::string &hex) {
    if(hex.size() != 6) { return setColor(255, 255, 255); }

    char r = ((hex[0] <= '9' && hex[0] >= '0') ? (hex[0] - '0') : (hex[0] - 'A' + 10)) * 16;
    r += (hex[1] <= '9' && hex[1] >= '0') ? (hex[1] - '0') : (hex[1] - 'A' + 10);

    char g = ((hex[2] <= '9' && hex[2] >= '0') ? (hex[2] - '0') : (hex[2] - 'A' + 10)) * 16;
    g += (hex[3] <= '9' && hex[3] >= '0') ? (hex[3] - '0') : (hex[3] - 'A' + 10);

    char b = ((hex[4] <= '9' && hex[4] >= '0') ? (hex[4] - '0') : (hex[4] - 'A' + 10)) * 16;
    b += (hex[5] <= '9' && hex[5] >= '0') ? (hex[5] - '0') : (hex[5] - 'A' + 10);

    return setColor(r, g, b);
}

Cursor &Cursor::setThickness(const int &thickness) {
    this->thickness = thickness;

    return *this;
}

//////////////////////////////////////////////////
// Methods
//////////////////////////////////////////////////

Cursor &Cursor::rotate(const float &rotation) {
    orientation += rotation;

    return *this;
}

Cursor &Cursor::forward(const float &distance) {
    if (penOn) {
        sf::RectangleShape line(sf::Vector2f(distance, thickness));
        line.setPosition(x, y);
        line.setFillColor(color);
        line.rotate(orientation);

        window->draw(line);
    }

    x += distance * cos(orientation / 360 * 2 * M_PI);
    y += distance * sin(orientation / 360 * 2 * M_PI);

    return *this;
}

Cursor &Cursor::backward(const float &distance) { return forward(-distance); }

Cursor &Cursor::right(const float &angle) { return rotate(abs(angle)); }

Cursor &Cursor::left(const float &angle) { return rotate(-abs(angle)); }

Cursor& Cursor::arc(const int &angle, const int &radius) {
    int n = abs(angle);
    float length = 2 * M_PI * radius / 360;

    if(angle < 0) rotate(180);

    for(int i = 0; i < n; i++) {
        forward(length);
        if(angle < 0) rotate(-1);
        else rotate(1);
    }

    return *this;
}

void Cursor::render() {
    window->display();

    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
        }
    }
}