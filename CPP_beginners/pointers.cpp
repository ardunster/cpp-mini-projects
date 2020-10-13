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

    // Pointers and arrays

    string texts[] = {"one", "two", "three", "four"};

    cout << sizeof(texts)/sizeof(string) << endl;


    // Looping through array without pointer
    for(int i=0; i<sizeof(texts)/sizeof(string); i++) {
        cout << "i: " << i << ", texts[i]: " << texts[i] << ", " << flush;
    } cout << endl;


    // Looping through array using pointer and array element reference syntax
    string* p_texts = texts;

    for(int i=0; i<sizeof(texts)/sizeof(string); i++) {
        cout << "i: " << i << ", p_texts[i]: " << p_texts[i] << ", " << flush;
    } cout << endl;


    // Looping through array by incrementing pointer
    for(int i=0; i<sizeof(texts)/sizeof(string); i++, p_texts++) {
        cout << "p_texts: " << p_texts << ", *p_texts: " << *p_texts << ", " << flush;
    } cout << endl;


    // Looping through array by comparing pointers
    string* p_element = &texts[0];
    string* p_end = &texts[(sizeof(texts)/sizeof(string)) - 1];

    while(true) {
        cout << "p_element: " << p_element << ", *p_element: " << *p_element << ", " << flush;
        if(p_element == p_end) {
            break;
        }
        p_element++;
        
    } cout << endl;



    return 0;
}