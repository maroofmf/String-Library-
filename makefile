# Author: Maroof
# File type: makefile
# Description: Utiltiy to build project
# Usage:
# 	-> Go to terminal and type:
# 		* make 			-> Builds and runs all projects
# 		* make clean	-> Clears out/obj/pch files

CC = g++	# Compiler 
VERSION = -std=c++14 #C++ Version


all:
	$(CC) $(VERSION) main.cpp String.cpp
	./a.out

clean:
	rm -rf *.o *.gch *.out


