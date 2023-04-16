main: main.o funcs.o
	g++ -o main main.o funcs.o

funcs.o: funcs.h

tests: tests.o funcs.o
	g++ tests -o tests.o funcs.o

clean:
	rm -f *.o main tests a.out
	