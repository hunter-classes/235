OBJECTS=List.o main.o Node.o

main: $(OBJECTS)
	g++ -o main $(OBJECTS)

List.o: List.cpp Node.h List.h

main.o: main.cpp List.h Node.h

Node.o: Node.cpp Node.h


clean:
	rm -f $(OBJECTS)
