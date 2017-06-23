// Author: Maroof
//
// ---------------------------------------------------------------------//

CC = g++
VERSION = -std=c++14


all:
	$(CC) $(VERSION) main.cpp String.cpp String.hpp
	./a.out

clean:
	rm -rf *.o *.gch *.out


