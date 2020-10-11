#include <iostream>

#include "cat.hpp"

//  Put related functions together in one file - then define prototypes for them
// all in a header file that can be included where you want to use them
// Common pattern in C++

using namespace std;

Cat::Cat() {
    happy = true;
    name = "Cat"; // Would really rather pass this in as a variable, hopefully that lesson is soon XD
    cout << "Constructing cat " << name << endl;
}


void Cat::jump() {
    cout << "Jumping to warm lap <3" << endl;
}

void Cat::luvvies() {
    happy = true;
}

void Cat::no_luv() {
    happy = false;
}

void Cat::set_name(string new_name) {
    name = new_name;

}

void Cat::speak() {
    if(happy) {
        cout << "*purr*" << endl;
    } else {
        cout << "Mew :(" << endl;
    }
}

string Cat::stringify() {
    if(happy) {
        return "Name: " + name + "\nHappy?: Yes";
    } else {
        return "Name: " + name + "\nHappy?: No";
    }
}

Cat::~Cat() {
    cout << "Cat " << name << " deconstructed :( :( " << endl;
}