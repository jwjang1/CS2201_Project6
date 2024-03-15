// File name: GuitarHero.cpp
// Author: Jungwon Jang
// userid: jangj1
// Email: jungwon.jang@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: 6
// Description:
// Honor statement: I have not given or received unauthorized aid on this assignment.
// Last Changed: Oct.30

#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include "GuitarString.h"


const double CONCERT_A = 440.0;
const int NUM_STRINGS = 37;
const double STEP = (double) 1 / ((double) SAMPLE_RATE);   //SAMPLE_RATE in GuitarString.h
const int END_OF_SONG = -1;


// open input and output files
// pre: user is prepared to enter file names at the keyboard
// post: files have been opened
void openFiles(std::ifstream &infile, std::ofstream &outfile);

double soundVal(GuitarString *strings[]);

// If you want to create your own helper functons (highly recommended), declare them
// here and then define them after the main() function.


int main() {

    // create the array of guitar strings (3 octaves)
    GuitarString *strings[NUM_STRINGS];
    for (int i = 0; i < NUM_STRINGS; i++) {
        double factor = pow(2, (i - 24) / 12.0);
        strings[i] = new GuitarString(CONCERT_A * factor);
    }

    //open data file
    std::ifstream infile;
    std::ofstream outfile;
    openFiles(infile, outfile);

    //prime the output file
    outfile.setf(std::ios::fixed, std::ios::floatfield);
    outfile.precision(10);
    std::string firstLine = "; Sample Rate " + std::to_string(SAMPLE_RATE);
    std::string secondLine = "; Channels 1";
    outfile << firstLine << std::endl;
    outfile << secondLine << std::endl;


    std::cout << "Reading the input file and generating a .dat file for sox" << std::endl;

    // TODO
    // your task is to read & process all the data in the input stream "infile",
    // and create & write the correct data to the output stream "outfile".
    // That work should be done here before the files are closed.
    // Define and use helper functions as needed for good style.

    double ts_val = 0.0;
    double prev = 0.0;
    double ts = 0.0;
    int frequency_val = 0;
    while (frequency_val != END_OF_SONG) {
        infile >> ts_val >> frequency_val;

        if (frequency_val > NUM_STRINGS - 1 || ts_val < prev) {
            throw std::out_of_range("Invalid input value");
        } else {
            while (ts < ts_val) {
                double sound_val = soundVal(strings);

                outfile << "  " << ts << "\t" << sound_val << "\n";
                ts += STEP;
            }

            if (frequency_val != -1) {
                strings[frequency_val]->pluck();
            }
            std::cout << ".";
        }
        prev = ts_val;
    }

    // close the files
    infile.close();
    outfile.close();
    std::cout << "Done." << std::endl;

    //Clean up all the strings
    for (int i = 0; i < NUM_STRINGS; i++) {
        if (strings[i] != nullptr)
            delete strings[i];
    }
    return 0;
}

double soundVal(GuitarString *strings[]) {
    double sound_val = 0;
    for (size_t i = 0; i < NUM_STRINGS; i++) {
        sound_val += strings[i]->sample();
        strings[i]->tic();
    }
    return sound_val;
}

// open input and output files
// pre: user is prepared to enter file names at the keyboard
// post: files have been opened
void openFiles(std::ifstream &infile, std::ofstream &outfile) {

    // open input data file
    std::string inFileName;
    std::cout << "Enter the name of the input file: ";
    std::cin >> inFileName;
    infile.open(inFileName.c_str());
    if (infile.fail()) {
        std::cout << "Error opening input data file" << std::endl;
        std::cout << "press enter to exit";
        std::cin.get();
        std::cin.get();
        exit(1);
    }
    // open output data file
    std::string outFileName;
    std::cout << "Enter the name of the output file: ";
    std::cin >> outFileName;
    outfile.open(outFileName.c_str());
    if (outfile.fail()) {
        std::cout << "Error opening output data file" << std::endl;
        std::cout << "press enter to exit";
        std::cin.get();
        std::cin.get();
        exit(1);
    }

}