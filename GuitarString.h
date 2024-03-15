// File name: GuitarString.h
// Author: Jungwon Jang
// userid: jangj1
// Email: jungwon.jang@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: 6
// Description: defines GuitarString.cpp
// Honor statement: I have not given or received unauthorized aid on this assignment.
// Last Changed: Oct.30

#ifndef GUITARSTRING_H
#define GUITARSTRING_H

#include "DblQueue.h"


const size_t SAMPLE_RATE = 44100;
const double DECAY_FACTOR = 0.996;

class GuitarString {
private:

    DblQueue dq;
    size_t numTics;
    double freq;


public:
    // create a guitar string representing the given frequency
    GuitarString(double frequency);

    // pluck the string - excite with white noise between -0.5 and 0.5
    void pluck();

    // advance the simulation one step
    void tic();

    // current sample
    double sample() const;

    // number of time steps = number of calls to tic()
    size_t getTime() const;

    // return the frequency of the string
    double getFrequency() const;

};

#endif
