#include <iostream>

using namespace std;

class Frog {
private: 
    string name;

public: 
    Frog() {
        name = "<unnamed>";
    }
    Frog(string name): name(name) {}
    void set_name(string name) {
        this->name = name;
    };
    void speak() const {
        cout << "This frog's name is " << name << endl;
        // this->name = "george"; // no viable overload o.o
    }
};

int main () {

    const double PI = 3.14159265;
    int value = 7;

    value = 17;

    cout << "value: " << value << "\nPie: " << PI << " Mmmm, pie." << endl;

    Frog frog;

    frog.speak();
    frog.set_name("James");
    frog.speak();

    int value2 = 8;
    int *p_value2 = &value2;

    cout << "p_value2: " << p_value2 << "\n*p_value2: " << *p_value2 << endl;

    int number = 11;
    p_value2 = &number;

    cout << "p_value2: " << p_value2 << "\n*p_value2: " << *p_value2 << endl;

    *p_value2 = 12;

    cout << "p_value2: " << p_value2 << "\n*p_value2: " << *p_value2 << endl;

    cout << "number: " << number << endl;

    // const pointer

    int value3 = 4;
    int * const p_value3 = &value3;

    cout << "p_value3: " << p_value3 << "\n*p_value3: " << *p_value3 << endl;

    int number2 = 47;
    // p_value3 = &number2; // can't do with int * const p_value3 = &value3;

    cout << "p_value3: " << p_value3 << "\n*p_value3: " << *p_value3 << endl;

    *p_value3 = 12; // can't do with const int *p_value3 = &value3;

    cout << "p_value3: " << p_value3 << "\n*p_value3: " << *p_value3 << endl;

    cout << "number2: " << number2 << endl;

    return 0;
}