// File name: DblQueueTest.cpp
// Author: Jungwon Jang
// userid: jangj1
// Email: jungwon.jang@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: 6
// Description: tests DblQueue.cpp
// Honor statement: I have not given or received unauthorized aid on this assignment.
// Last Changed: Oct.30

#include "DblQueue.h"
#include <iostream>

int main() {
    std::cout << "Testing DblQueue..." << std::endl;

    DblQueue dq1;   // create an empty Queue object via default ctor

    if (!dq1.isEmpty()) {
        std::cout << "Default ctor did not produce an empty DblStack" << std::endl;
    }
    if (dq1.size() != 0) {
        std::cout << "Default ctor failed to create an empty DblStack" << std::endl;
        std::cout << "Reported that " << dq1.size() << " stacks exist" << std::endl;
    }
    try {
        dq1.dequeue();
    }
    catch (std::underflow_error &excpt) {
        std::cout << "Underflow exception successfully thrown!:: " << excpt.what() << std::endl;
    }
    try {
        dq1.front();
    }
    catch (std::underflow_error &excpt) {
        std::cout << "Underflow exception successfully thrown!:: " << excpt.what() << std::endl;
    }

    dq1.enqueue(23.5);//first item added
    if (dq1.isEmpty()) {
        std::cout << "failed to enqueue item" << std::endl;
    }
    if (dq1.front() != 23.5) {
        std::cout << "Wrong item" << std::endl;
        std::cout << "Item returned: " << dq1.front() << std::endl;
    }
    if (dq1.size() != 1) {
        std::cout << "Wrong size" << std::endl;
        std::cout << "Reported that " << dq1.size() << " queues exist" << std::endl;
    }
    dq1.enqueue(40);//second item added
    if (dq1.isEmpty()) {
        std::cout << "failed to enqueue item" << std::endl;
    }
    if (dq1.front() != 23.5) {
        std::cout << "Wrong item" << std::endl;
        std::cout << "Item returned: " << dq1.front() << std::endl;
    }
    if (dq1.size() != 2) {
        std::cout << "Wrong size" << std::endl;
        std::cout << "Reported that " << dq1.size() << " queues exist" << std::endl;
    }

    dq1.enqueue(55.7);//third item added
    if (dq1.isEmpty()) {
        std::cout << "failed to enqueue item" << std::endl;
    }
    if (dq1.front() != 23.5) {
        std::cout << "Wrong item" << std::endl;
        std::cout << "Item returned: " << dq1.front() << std::endl;
    }
    if (dq1.size() != 3) {
        std::cout << "Wrong size" << std::endl;
        std::cout << "Reported that " << dq1.size() << " queues exist" << std::endl;
    }

    dq1.dequeue(); //testing dequeue()
    if (dq1.front() != 40) {
        std::cout << "Failed to dequeue" << std::endl;
        std::cout << "Item returned: " << dq1.front() << std::endl;
    }
    if (dq1.size() != 2) {
        std::cout << "Wrong size" << std::endl;
        std::cout << "Reported that " << dq1.size() << " queues exist" << std::endl;
    }

    DblQueue dq2;
    dq2 = dq1; //testing copy ctor
    if (dq2.front() != 40) {
        std::cout << "Failed to copy" << std::endl;
        std::cout << "Item returned: " << dq2.front() << std::endl;
    }
    if (dq2.size() != 2) {
        std::cout << "Wrong size" << std::endl;
        std::cout << "Reported that " << dq2.size() << " queues exist" << std::endl;
    }

    DblQueue dq3(dq1);//testing assignment operator
    if (dq3.front() != 40) {
        std::cout << "Failed to assign" << std::endl;
        std::cout << "Item returned: " << dq3.front() << std::endl;
    }
    if (dq3.size() != 2) {
        std::cout << "Wrong size" << std::endl;
        std::cout << "Reported that " << dq3.size() << " queues exist" << std::endl;
    }

    return 0;
}
