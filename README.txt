# Author: Maroof Mohammed Farooq

# Program Details:
    -> Compiler:        g++
    -> Dependencies:    None
    -> C++ Version:     C++14 (Not tested with c++11 or below)
    -> OS: macOS Sierra

# File Structure:
    -> String.hpp: Header file containing forward declrations for class and enum
    -> String.cpp: Contains implementation for class String
    -> main.cpp:   Contains the main program that intantiates the class to produce the output

# Description:
    
    * This application works to compare two strings and returns a value and a string based on the
      problem statement. It also has the ability to print error messages.

    * This console application can be built by the following methods:
        1> Run: g++ -std=c++14 String.cpp main.cpp
        2> Run: make
    
    * This program can only take ASCII alphanumeric input values. Eg:
        -> aaaabbb111
        -> 123
        -> a
        -> 1a2b3c

# Member functions:

    * readInput() -> Prompts the user to enter two strings and returns a boolean to indicate if the inputs are valid
    * printReport() -> If the reading is successfull, the program provides the final report as per the problem statement!

