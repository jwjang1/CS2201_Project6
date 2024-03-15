// File name: GuitarString.cpp
// Author: Jungwon Jang
// userid: jangj1
// Email: jungwon.jang@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: 6
// Description: models and simulates a vibrating guitar string of a given frequency
// Honor statement: I have not given or received unauthorized aid on this assignment.
// Last Changed: Oct.30

#include "GuitarString.h"
#include <stdexcept>
#include <chrono>
#include <random>

// create a guitar string representing the given frequency
GuitarString::GuitarString(double frequency) {
    if (frequency <= 0) {
        throw std::invalid_argument("The frequency is not positive");
    }
    size_t N = SAMPLE_RATE / frequency;
    for (size_t i = 0; i < N; i++) {
        dq.enqueue(0);
    }
    freq = frequency;
}

// pluck the string - excite with white noise between -0.5 and 0.5
void GuitarString::pluck() {
    // create the seed
    unsigned seed = (unsigned) std::chrono::system_clock::now().time_since_epoch().count();
    // create the generator using the seed
    std::default_random_engine generator(seed);
    // create the appropriate distribution
    std::uniform_real_distribution<double> distribution(-0.5, 0.5);

    for (size_t i = 0; i < dq.size(); i++) {
        dq.dequeue();
        // create random numbers as needed
        double num = distribution(generator);
        dq.enqueue(num);
    }
}

// advance the simulation one step
void GuitarString::tic() {
    double add = dq.front();
    dq.dequeue();
    add += dq.front();
    dq.enqueue((add / 2) * DECAY_FACTOR);
    numTics++;
}

// current sample
double GuitarString::sample() const {
    return dq.front();
}

// number of time steps = number of calls to tic()
size_t GuitarString::getTime() const {
    return numTics;
}

// return the frequency of the string
double GuitarString::getFrequency() const {
    return freq;
}