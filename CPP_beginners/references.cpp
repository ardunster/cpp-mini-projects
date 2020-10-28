#include <iostream>

using namespace std;

void make_pi(double &in_value) {
    cout << "Make pie! Mmmm, pie." << endl;
    in_value = 3.14159265;
}

int main() {

    int value1 = 8;
    int value2 = value1;
    int &value3 = value1;

    value2 = 10;

    cout << "value1: " << value1 << "\nvalue2: " << value2 << "\nvalue3: " <<
    value3 << endl;
    cout << "&value1: " << &value1 << "\n&value2: " << &value2 << "\n&value3: "
    << &value3 << endl;

    double some_val = 4.321;

    cout << "some_val: " << some_val << endl;
    make_pi(some_val);

    cout << "some_val: " << some_val << endl;

    return 0;
}