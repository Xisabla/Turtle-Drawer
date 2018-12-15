# Turtle Drawing

The goal of this school project is to create a drawing tool based on the moves of a Cursor

## Project Architecture

- *bin/* contains all the binary compiled runnable files
- *build/* contains all the compiled object files
- *doc/* contains all the documentation files at the Markdown, HTML, and PDF format
- *examples/* contains multiple folder that are each an example and contains a running script and a txt files
- *include/* is empty but would have contained third party includes
- *spikes/* contains small scripts for testing methods and libraries
- *src/* contains all the source files

## Documentation

- Turtle Drawing instructions ([markdown](./doc/markdown/TurtleDrawing.md), [html](./doc/html/TurtleDrawing.html), [pdf](./doc/pdf/TurtleDrawing.pdf))
- (**C++**) Cursor ([markdown](./doc/markdown/Cursor.md), [html](./doc/html/Cursor.html), [pdf](./doc/pdf/Cursor.pdf))

## Compiling

```bash
make build
```

## Running

It is recommended to clean old objects before running:

```bash
make clean run
```

Or

```bash
make clean build
./bin/app InstructionFile.txt
```