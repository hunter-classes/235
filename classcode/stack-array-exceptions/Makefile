
main: main.o stack.o
	g++ -o main main.o stack.o

main.o: main.cpp stack.h

stack.o: stack.cpp stack.h

clean:
	rm -f main.o stack.o
