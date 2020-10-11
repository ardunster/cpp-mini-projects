
#include "cat.hpp"

//  Put related functions together in one file - then define prototypes for them
// all in a header file that can be included where you want to use them
// Common pattern in C++

using namespace std;

Cat::Cat() {
    happy = true;
    name = "DefaultCat"; 
    cout << "Constructing cat " << this->name << ": " << this << endl;
}

// Cat::Cat(string name, bool happy) {
//     this->happy = happy;
//     this->name = name;
//     cout << "Constructing cat " << this->name << ": " << this << endl;
// }

Cat::Cat(string name, bool happy): name(name), happy(happy) {
    cout << "Constructing cat " << name << ": " << this << endl;
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

void Cat::set_name(string name) {
    this->name = name;

}

void Cat::speak() {
    if(happy) {
        cout << "*purr*" << endl;
    } else {
        cout << "Mew :(" << endl;
    }
}

string Cat::stringify() {
    stringstream ss;

    ss << "Name: " << name << "\nHappy?: ";
    if(happy) {
        ss << "Yes";
    } else {
        ss << "No";
    }

    return ss.str();
}

Cat::~Cat() {
    cout << "Cat " << name << " deconstructed :( :( " << endl;
}