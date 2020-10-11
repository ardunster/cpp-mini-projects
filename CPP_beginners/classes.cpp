// Classes
// Data members (instance variables)
// Constructor and destructor
// Getters and setters


#include <iostream>
#include "cat.hpp"

using namespace std;


int main () {
    cout << "If you weren't sure, we're starting the program here." << endl;

    Cat muffins;
    muffins.set_name("Muffins");

    muffins.no_luv();
    muffins.speak();
    cout << muffins.stringify() << endl;
    muffins.jump();
    muffins.luvvies();
    muffins.speak();
    cout << muffins.stringify() << endl;

    {
        Cat spud;
        spud.set_name("Spud");
        spud.speak();
        cout << spud.stringify() << endl;
    }

    cout << "Amazingly, we are now *ending* the program, too! who knew?" << endl;
    return 0;
}