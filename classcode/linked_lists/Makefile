OBJECTS=main.o List.o Node.o
CXX=g++
CXXFLAGS=
LDFLAGS=

main: $(OBJECTS)
	g++ $(CXXFLAGS) $(LDFLAGS) -o main $(OBJECTS)

main.o: main.cpp List.h Node.h

List.o: List.cpp List.h Node.h

Node.o: Node.cpp Node.h

clean:
	rm -f $(OBJECTS)
