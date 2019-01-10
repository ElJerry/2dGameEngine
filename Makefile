CXX		  := g++
CXX_FLAGS := -Wall -Wextra -ggdb 

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:= 
EXECUTABLE	:= main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $^  -I$(INCLUDE) -I/usr/local/include/SDL2 -I/usr/include/SDL2 -L/usr/local/lib -Wl,-rpath,/usr/local/lib -Wl,--enable-new-dtags -lSDL2 -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*
