// String Streams

#include <iostream>
#include <sstream>

using namespace std;

int main() {

    int age = 475;
    string name = "George";

    stringstream ss;

    ss << "Name: " << name << ", Age: " << age;

    cout << ss.str() << endl;

    ss << ", Favorite cat is Steve";

    string thing = ss.str();

    // ss << ", Does this work?"; // No it doesn't 

    cout << thing << endl;


    return 0;
}

