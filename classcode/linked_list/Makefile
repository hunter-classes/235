OBJECTS=main.o Node.o list.o
NODEDEMOOBJECTS=nodedemo.o Node.o
CXXFLAGS=
LDFLAGS=
main: main.o Node.o List.o
	g++ -o main main.o Node.o List.o

nodedemo: nodedemo.o Node.o
	g++ -o nodedemo nodedemo.o Node.o


nodedemo.o: nodedemo.cpp Node.h

main.o: main.cpp List.h Node.h

List.o: List.cpp List.h

Node.o: Node.cpp Node.h

clean: clean_main clean_nodedemo

clean_main:
	marm -f $(OBJECTS)

clean_nodedemo:
	rm -f $(NODEDEMOOJECTS)
