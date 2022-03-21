OBJECTS=Main.o Labyrinth.o MazeGenerator.o
CXXFLAGS= -g
LDFLAGS=
CXX=g++

main: $(OBJECTS)
	$(CXX) -g  -o main $(OBJECTS)
Labyrinth.o: Labyrinth.cpp Labyrinth.h

Main.o: Main.cpp MazeGenerator.h Labyrinth.h

MazeGenerator.o: MazeGenerator.cpp MazeGenerator.h Labyrinth.h


clean:
	rm -f $(OBJECTS)
