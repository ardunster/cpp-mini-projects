#include <iostream>

using namespace std;

// void manipulate(double value) {
//     cout << "initial value of double in manipulate: " << value << endl;
//     value = 10.0;
//     cout << "final value of double in manipulate: " << value << endl;
// };

// not ambiguous
void manipulate(double* value) {
    cout << "initial value of double in manipulate: " << *value << endl;
    *value = 10.0;
    cout << "final value of double in manipulate: " << *value << endl;
};

// ambiguous
void manipulate(double &value) {
    cout << "initial value of double in manipulate: " << value << endl;
    value = 10.0;
    cout << "final value of double in manipulate: " << value << endl;
};

int main() {

    int n_value = 8;

    int* p_n_value = &n_value;

    cout << "int value: " << n_value << endl;
    cout << "pointer value:" << p_n_value << endl;
    cout << "dereferenced pointer: " << *p_n_value << endl;
    cout << "address of int: " << &n_value << endl;

    cout << "=======" << endl;

    double d_value = 123.4;

    cout << "d value: " << d_value << endl;
    manipulate(d_value);
    cout << "d value: " << d_value << endl;

    double* p_d_value = &d_value;

    manipulate(p_d_value);
    cout << "final d value: " << d_value << endl;

    return 0;
}