.DEFAULT_GOAL=help
.PHONY=all

#--------------------------------------#
#                                      #
#        Project configuration         #
#                                      #
#--------------------------------------#

# Compiler executable
CXX=g++

# Compilation flags
CXXFLAGS=

# SFML Compilation flags
SFML_FLAGS=-lsfml-graphics -lsfml-window -lsfml-system

# Project output filename
TARGET=bin/app

# Custom run script
SCRIPT=./$(TARGET)

#--------------------------------------#
#                                      #
#          Project sources             #
#                                      #
#--------------------------------------#

# Source (.cpp) files
SOURCES=$(shell find ./src -type f -name "*.cpp" ! -path "./src/main.cpp")

# Headers files
HEADERS=$(shell find ./src -type f -name "*.h")

# Objects files (to build)
OBJECTS=$(patsubst ./src/%.cpp, ./build/%.o, $(SOURCES))

#--------------------------------------#
#                                      #
#               Recipes                #
#                                      #
#--------------------------------------#

# Basics

help: ## Show this help.
	@printf "\033[32m%-30s     \033[32m %s\n" "VARIABLE NAME" "DEFAULT_VALUE"
	@grep -E '^[a-zA-Z_-]+(\?=|=).*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = "(?=|=)"}; {printf "\033[36m%-30s     \033[0m %s\n", $$1, $$2}'
	@printf "\n\033[32m%-30s     \033[32m %s\033[0m\n" "RECIPE" "DESCRIPTION"
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "make \033[36m%-30s\033[0m %s\n", $$1, $$2}'

.depend:
	$(CXX) -E -MM $(SOURCES) $(DEPENDS) > .depend

clean: ## Clean project from compiled & temporary files
	@echo "Cleaning..."
	rm -rf ./buildt
	find ./ -type f ! -name "*.*" ! -path "./Makefile" -delete
	find ./ -type f -name "*out*" -delete
	find ./ -type f -name "*.o" -delete
	find ./ -type f -name "*.gch" -delete
	find ./ -type f -name ".fuse*" -delete
	@echo

# Objects

build/%.o: src/%.cpp src/%.h .depend ## Build object file
	@echo "Building '$@'..."
	$(CXX) $(CXXFLAGS) -g -c $< -o $@
	@echo Build done.
	@echo

# Main & target

build/main.o: src/main.cpp ## Build main object
	@echo "Building 'main.o'..."
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o build/main.o
	@echo Build done.
	@echo

build: $(OBJECTS) build/main.o ## Build project
	@echo "Building '$(TARGET)'..."
	$(CXX) $(CXXFLAGS) build/main.o $(OBJECTS) $(SFML_FLAGS) -o $(TARGET)
	@echo Build done.
	@echo

$(TARGET): build

# Run

run: $(TARGET) ## Run the project executable build
	./$(SCRIPT)

# Spikes

stringextra: build/StringExtra.o ## Build spike related to StringExtra
	$(CXX) $(CXXFLAGS) spikes/stringextra.cpp build/StringExtra.o -o bin/stringextra

functionmap: ## Build spike related to functions in a map
	$(CXX) $(CXXFLAGS) spikes/functionmap.cpp -o bin/functionmap