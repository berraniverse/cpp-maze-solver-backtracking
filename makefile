CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude
TARGET = MazeSolver.exe
SOURCES = src/Konum.cpp src/Labirent.cpp src/Test.cpp

all:
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

run: all
	./$(TARGET)

.PHONY: all run