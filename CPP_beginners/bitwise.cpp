#include <iostream>

using namespace std;

int main() {
    int color = 0x123456;

    unsigned char red = (color & 0xFF0000) >> 16;
    unsigned char green = (color & 0x00FF00) >> 8;
    unsigned char blue = color & 0x0000FF;

    cout << hex << (int)red << endl;
    cout << hex << (int)green << endl;
    cout << hex << (int)blue << endl;

    unsigned char red2 = color >> 16;
    unsigned char green2 = color >> 8;
    unsigned char blue2 = color;

    cout << hex << (int)red2 << endl;
    cout << hex << (int)green2 << endl;
    cout << hex << (int)blue2 << endl;

    // Bitwise AND will set the bit to 1 if BOTH values are 1, otherwise 0.
    // Bitwise OR will set the bit to 1 if EITHER value is 1, otherwise 0.

    return 0;
}