// File name: GuitarStringTest.cpp
// Author: Jungwon Jang
// userid: jangj1
// Email: jungwon.jang@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: 6
// Description: tests GuitarString.cpp
// Honor statement: I have not given or received unauthorized aid on this assignment.
// Last Changed: Oct.30

#include "GuitarString.h"
#include <iostream>

int main() {
    std::cout << "Testing GuitarString..." << std::endl;

    GuitarString gs1(5.5); //create a string
    if (gs1.sample() != 0) {
        std::cout << "Constructor failed to create a ring buffer of 0's" << std::endl;
    }

    if (gs1.getTime() != 0) {
        std::cout << "Wrong number of times" << std::endl;
        std::cout << "returned " << gs1.getTime() << "." << std::endl;
    }

    gs1.tic();
    gs1.tic();
    gs1.tic();
    gs1.tic();

    if (gs1.getTime() != 4) {
        std::cout << "Wrong number of times" << std::endl;
        std::cout << "returned " << gs1.getTime() << "." << std::endl;
    }

    if (gs1.getFrequency() != 5.5) {
        std::cout << "Wrong frequency" << std::endl;
        std::cout << "returned " << gs1.getFrequency() << "." << std::endl;
    }

    try {
        GuitarString gs2(-5.5);
    }
    catch (std::invalid_argument &excpt) {
        std::cout << "Invalid argument exception successfully thrown!:: " << excpt.what() << std::endl;
    }

    return 0;
}
