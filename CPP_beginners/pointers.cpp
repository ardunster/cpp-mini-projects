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


    // Pointer Arithmetic

    const int ELEMENTS = 6;

    string text2[ELEMENTS] = {"uno", "dos", "tres", "quatro", "cinco", "seis"};

    string* p_text2 = text2;

    cout << "*p_text2: " << *p_text2 << endl;

    p_text2++;

    cout << "*p_text2++: " << *p_text2 << endl;

    p_text2 += 3;

    cout << "*p_text2 += 3: " << *p_text2 << endl;

    p_text2 -= 2;

    cout << "*p_text2 -= 2: " << *p_text2 << endl;

    //Reset
    p_text2 = text2;

    string* p_end2 = &text2[ELEMENTS-1];

    // Compare

    while (!(p_text2 > p_end2)) {
        cout << "*p_text2: " << *p_text2 << endl;
        p_text2++;
    }

    // Reset and compare again by pointing off the end of the array

    p_text2 = text2;

    p_end2 = &text2[ELEMENTS];

    // Compare

    while (p_text2 != p_end2) {
        cout << "*p_text2: " << *p_text2 << endl;
        p_text2++;
    }

    p_text2 = text2;

    // Subtraction

    int elements = p_end2 - p_text2;

    cout << "elements: " << elements << endl;

    // Middle of array

    p_text2 += ELEMENTS/2;

    cout << "*p_text2 after ELEMENTS/2: " << *p_text2 << endl;



    return 0;
}