# Documentation: Turtle Drawing

- [Documentation: Turtle Drawing](#documentation-turtle-drawing)
  - [Setters instructions](#setters-instructions)
    - [`setdefault`](#setdefault)
    - [`setpen <on/off>`](#setpen-onoff)
    - [`setx <x>`](#setx-x)
    - [`sety <y>`](#sety-y)
    - [`setposition <x> <y>`](#setposition-x-y)
    - [`setorientation <angle>`](#setorientation-angle)
    - [`setcolor <r> <g> <b>`](#setcolor-r-g-b)
    - [`setcolorhex <hex>`](#setcolorhex-hex)
    - [`setthickness <thickness>`](#setthickness-thickness)
  - [Draw/move instructions](#drawmove-instructions)
    - [`rotate <angle>`](#rotate-angle)
    - [`forward <distance>`](#forward-distance)
    - [`backward <distance>`](#backward-distance)
    - [`left <angle>`](#left-angle)
    - [`right <angle>`](#right-angle)
    - [`arc <angle> <radius>`](#arc-angle-radius)
  - [Blocks](#blocks)
    - [`repeat <times>`](#repeat-times)
    - [`block <name>`](#block-name)
    - [`call <name>`](#call-name)

## Setters instructions

Those instructions allow the user to define the curser values

### `setdefault`

`setdefault` reset all cursor values to default, it means:

- the pen set on "on"
- the position (0, 0)
- the orientation 0°
- the color: white
- the thickness set on 1

**Example:**

```text
setcolor 255 10 10
forward 200

setdefault
forward 100
```

[↑ Back to top](#documentation-turtle-drawing)

### `setpen <on/off>`

`setpen on` makes the cursor draw will moving

`setpen off` denies the cursor from drawing will moving

**Example:**

```text
setpen off
forward 100
setpen on
forward 100
```

[↑ Back to top](#documentation-turtle-drawing)

### `setx <x>`

`setx` will redifine the x coordonate value of the cursor

**Example:**

```text
setx 200
forward 100
```

[↑ Back to top](#documentation-turtle-drawing)

### `sety <y>`

`sety` will redifine the y coordonate value of the cursor

**Example:**

```text
sety 200
forward 100
```

[↑ Back to top](#documentation-turtle-drawing)

### `setposition <x> <y>`

`setposition` is a mix betwenn [`setx`](#setx-x) and [`sety`](#sety-y), it will redifine the x and y coordonate values of the cursor

**Example:**

```text
setposition 200 200
forward 100
```

[↑ Back to top](#documentation-turtle-drawing)

### `setorientation <angle>`

`setorientation` will redifine the current cursor orientation

**Example:**

```text
setorientation 45
forward 100
```

[↑ Back to top](#documentation-turtle-drawing)

### `setcolor <r> <g> <b>`

`setcolor` will redifine the cursor color and tus the drawing shapes color

**Example:**

```text
setcolor 255 14 14
forward 100
```

[↑ Back to top](#documentation-turtle-drawing)

### `setcolorhex <hex>`

`setcolorhex` will do the same thing as [`setcolor`](#setcolor-r-g-b) but with the hexa value of the color instead of the rgb values.

**Be careful**, the letters of the hexa value have to be in **capital letter**

**Example:**

```text
setcolorhex FF0000
forward 100
```

[↑ Back to top](#documentation-turtle-drawing)

### `setthickness <thickness>`

`setthickness` will redifine the thickness of every lines drawed by the cursor

**Example:**

```text
setthickness 5
forward 100
```

[↑ Back to top](#documentation-turtle-drawing)

## Draw/move instructions

Those instructions allow the user to make the cursor move and thus draw is the pen status is "on"

### `rotate <angle>`

`rotate` instruction allow the cursor to inscrease his rotation to the defined angle

**Example:**

```text
forward 100
rotate 95
forward 100
```

[↑ Back to top](#documentation-turtle-drawing)

### `forward <distance>`

`forward` allow the cursor to go in his direction for the specified distance

**Example:**

```text
forward 100
```

[↑ Back to top](#documentation-turtle-drawing)

### `backward <distance>`

`backward` is the same as [`forward`](#forward-distance), but the cursor will go in the opposite direction than his orientation

**Example:**

```text
forward 100
rotate 90
forward 100
rotate 90
backward 100
```

[↑ Back to top](#documentation-turtle-drawing)

### `left <angle>`

`left` is the same as [`rotate`](#rotate-angle), but will take the opposite value of the absolute value of the angle

**Example:**

```text
setposition 200 200
forward 100
left 100
forward 100
```

[↑ Back to top](#documentation-turtle-drawing)

### `right <angle>`

`right` is like [`left`](#left-angle), but il will only take the absolute value of the angle

**Example:**

```text
forward 100
right 100
forward 100
```

[↑ Back to top](#documentation-turtle-drawing)

### `arc <angle> <radius>`

`arc` allow the cursor to draw an arc of a circle of the specified `radius`

**Example:**

```text
forward 100
arc 180 100
```

[↑ Back to top](#documentation-turtle-drawing)

## Blocks

The following methods will allow the user to create and run blocks of instructions or juste repeat instructions

### `repeat <times>`

`repeat` will allow the user to repeat `times` times some instructions. All the tabulated instructions will be take. Line break also breaks the repeat block

**Example:**

```text
repeat 4
    forward 100
    rotate 90
forward 200
```

Is the same as :

```text
repeat 4
    forward 100
    rotate 90

    forward 200
```

[↑ Back to top](#documentation-turtle-drawing)

### `block <name>`

`block` allow the user to create block of instructions that can be called by the [`call`](#call-name) instruction

**Example:**

```text
block square
    repeat 4
        forward 100
        rotate 90
```

[↑ Back to top](#documentation-turtle-drawing)

### `call <name>`

The `call` method allow the user to execute a defined [`block`](#block-name)

**Example:**

```text
block square
    repeat 4
        forward 100
        rotate 90

call square
forward 100
call square
```

[↑ Back to top](#documentation-turtle-drawing)