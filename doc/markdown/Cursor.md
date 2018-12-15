# Documentation: (C++) Cursor

- [Documentation: (C++) Cursor](#documentation-c-cursor)
  - [`public Cursor(sf::RenderWindow *window, float x, float y, float orientation, int thickness, sf::Color color)`](#public-cursorsfrenderwindow-window-float-x-float-y-float-orientation-int-thickness-sfcolor-color)
  - [`public bool isPenOn() const`](#public-bool-ispenon-const)
  - [`public float getX() const`](#public-float-getx-const)
  - [`public float getY() const`](#public-float-gety-const)
  - [`public float getOrientation() const`](#public-float-getorientation-const)
  - [`public int getThickness() const`](#public-int-getthickness-const)
  - [`public sf::Color getColor() const`](#public-sfcolor-getcolor-const)
  - [`public Cursor &setPenStatus(const bool &status)`](#public-cursor-setpenstatusconst-bool-status)
  - [`public Cursor &setPenOn()`](#public-cursor-setpenon)
  - [`public Cursor &setPenOff()`](#public-cursor-setpenoff)
  - [`public Cursor &setX(const float &x)`](#public-cursor-setxconst-float-x)
  - [`public Cursor &setY(const float &y)`](#public-cursor-setyconst-float-y)
  - [`public Cursor &setPosition(const float &x, const float &y)`](#public-cursor-setpositionconst-float-x-const-float-y)
  - [`public Cursor &setOrientation(const float &angle)`](#public-cursor-setorientationconst-float-angle)
  - [`public Cursor &setColor(const sf::Color &color)`](#public-cursor-setcolorconst-sfcolor-color)
  - [`public Cursor &setColor(const char &r, const char &g, const char &b)`](#public-cursor-setcolorconst-char-r-const-char-g-const-char-b)
  - [`public Cursor &setColor(const std::string &hex)`](#public-cursor-setcolorconst-stdstring-hex)
  - [`public Cursor &setThickness(const int &thickness)`](#public-cursor-setthicknessconst-int-thickness)
  - [`public Cursor &rotate(const float &rotation)`](#public-cursor-rotateconst-float-rotation)
  - [`public Cursor &forward(const float &distance)`](#public-cursor-forwardconst-float-distance)
  - [`public Cursor &backward(const float &distance)`](#public-cursor-backwardconst-float-distance)
  - [`public Cursor &right(const float &angle)`](#public-cursor-rightconst-float-angle)
  - [`public Cursor &left(const float &angle)`](#public-cursor-leftconst-float-angle)
  - [`public Cursor &arc(const int &angle, const int &radius)`](#public-cursor-arcconst-int-angle-const-int-radius)
  - [`public void render()`](#public-void-render)
  - [`private bool penOn`](#private-bool-penon)
  - [`private float x`](#private-float-x)
  - [`private float y`](#private-float-y)
  - [`private float orientation`](#private-float-orientation)
  - [`private int thickness`](#private-int-thickness)
  - [`private sf::Color color`](#private-sfcolor-color)
  - [`private sf::RenderWindow* window`](#private-sfrenderwindow-window)

## `public Cursor(sf::RenderWindow *window, float x, float y, float orientation, int thickness, sf::Color color)`

This is basically the constructor, it returns an instance of [`Cursor`](#documentation-c-cursor)

- `window` is a pointer to the *SFML `RenderWindow`* object in which will be draw the Cursor moves.
- `x` is a float describing the base x position of the Cursor (**default: 0**).
- `y` is a float describing the base y position of the Cursor (**default: 0**).
- `orientation` is a float describing the base orientation of the Cursor (**default: 0**).
- `thickness` is an int describing the base thickness of the Cursor (**default: 1**).
- `color` is an *SFML `Color`* object describing the base color of the Cursor (**default: `sf::Color(255, 255, 255)`**).

[↑ Back to top](#documentation-c-cursor)

## `public bool isPenOn() const`

Returns `true` if the pen status is on *true*, otherwise, returns `false`.

[↑ Back to top](#documentation-c-cursor)

## `public float getX() const`

Returns the current x position of the Cursor.

[↑ Back to top](#documentation-c-cursor)

## `public float getY() const`

Returns the current y position of the Cursor.

[↑ Back to top](#documentation-c-cursor)

## `public float getOrientation() const`

Returns the current orientation's absolute angle of the Cursor.

[↑ Back to top](#documentation-c-cursor)

## `public int getThickness() const`

Returns the current thickness of the Cursor.

[↑ Back to top](#documentation-c-cursor)

## `public sf::Color getColor() const`

Returns the current color of the Cursor as an *SFML Color* object.

[↑ Back to top](#documentation-c-cursor)

## `public Cursor &setPenStatus(const bool &status)`

Defines the Cursor pen status, if on `true`, the Cursor will draw while moving, elsewhere, on `false`, it won't draw but update it's position and orientation while moving.

Returns the instance of the Cursor.

[↑ Back to top](#documentation-c-cursor)

## `public Cursor &setPenOn()`

Defines the Cursor pen status on true.

[↑ Back to top](#documentation-c-cursor)

## `public Cursor &setPenOff()`

Defines the Cursor pen status on false.

Returns the instance of the Cursor.

[↑ Back to top](#documentation-c-cursor)

## `public Cursor &setX(const float &x)`

Defines the x position of the Cursor, can be outside of the window.

Returns the instance of the Cursor.

[↑ Back to top](#documentation-c-cursor)

## `public Cursor &setY(const float &y)`

Defines the y position of the Cursor, can be outside of the window.

Returns the instance of the Cursor.

[↑ Back to top](#documentation-c-cursor)

## `public Cursor &setPosition(const float &x, const float &y)`

Defines the x and y position of the Cursor, both can be outside of the window.

Returns the instance of the Cursor.

[↑ Back to top](#documentation-c-cursor)

## `public Cursor &setOrientation(const float &angle)`

Defines the absolution orentation's angle of the Cursor. While moving the Cursor will forward following this angle orientation.

Returns the instance of the Cursor.

[↑ Back to top](#documentation-c-cursor)

## `public Cursor &setColor(const sf::Color &color)`

Defines the Cursor color using an *SFML Color* object.

Returns the instance of the Cursor.

[↑ Back to top](#documentation-c-cursor)

## `public Cursor &setColor(const char &r, const char &g, const char &b)`

Defines the Cursor color using an *rgb code*.

Returns the instance of the Cursor.

## `public Cursor &setColor(const std::string &hex)`

Defines the Cursor color using an *hexadecimal code* stored in a string. All letters must be in **capital letters**. By default if the string size is not 6, it sets the color to white.

Returns the instance of the Cursor.

[↑ Back to top](#documentation-c-cursor)

## `public Cursor &setThickness(const int &thickness)`

Defines the Cursor thickness. More the thickness is, thicker the lines drawed by the Cursor will be.

Returns the instance of the Cursor.

[↑ Back to top](#documentation-c-cursor)

## `public Cursor &rotate(const float &rotation)`

`rotate` increments the orientation angle of the Cursor by the given angle.

Returns the instance of the Cursor.

[↑ Back to top](#documentation-c-cursor)

## `public Cursor &forward(const float &distance)`

`forward` make the Cursor go forward of the choosen distance, if the *penStatus* is on `true`, it will draw a line. In any case, it will update its x and y coordonates.

Returns the instance of the Cursor.

[↑ Back to top](#documentation-c-cursor)

## `public Cursor &backward(const float &distance)`

`backward` executes the [`forward`](#public-cursor-forwardconst-float-distance) method with the opposite value of the distance.

Returns the instance of the Cursor.

[↑ Back to top](#documentation-c-cursor)

## `public Cursor &right(const float &angle)`

`right` method makes rotation with the absolute value of the given angle.

Returns the instance of the Cursor.

[↑ Back to top](#documentation-c-cursor)

## `public Cursor &left(const float &angle)`

`left` method makes the same as `right` with the opposite of the absolute value of the given angle.

Returns the instance of the Cursor.

[↑ Back to top](#documentation-c-cursor)

## `public Cursor &arc(const int &angle, const int &radius)`

`arc` draws a circle arc of the given radius, on the given angle. This draws one line and rotate to one degree repeated as the same number of times as the given angle.

Returns the instance of the Cursor.

[↑ Back to top](#documentation-c-cursor)

## `public void render()`

Dispalys the window containing all the drawed shapes.

[↑ Back to top](#documentation-c-cursor)

## `private bool penOn`

Stores current Cursor pen status.

[↑ Back to top](#documentation-c-cursor)

## `private float x`

Stores current Cursor x positon.

[↑ Back to top](#documentation-c-cursor)

## `private float y`

Stores current Cursor y positon.

[↑ Back to top](#documentation-c-cursor)

## `private float orientation`

Stores currenct absolute orientation angle of the Cursor.

[↑ Back to top](#documentation-c-cursor)

## `private int thickness`

Stores the currect thickness of the Cursor.

[↑ Back to top](#documentation-c-cursor)

## `private sf::Color color`

Stores the current color of the Cursor.

[↑ Back to top](#documentation-c-cursor)

## `private sf::RenderWindow* window`

Stores the adress of the window in which the Cursor will draw.

[↑ Back to top](#documentation-c-cursor)