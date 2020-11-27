#include <iostream>
#include <iomanip>

using namespace std;

void colorprint(unsigned int color) {
    cout << setfill('0') << setw(8) << hex << color << endl;
}

int main() {

    // 0xFF123456

    unsigned char alpha = 0xFF;
    unsigned char red = 0x12;
    unsigned char green = 0x34;
    unsigned char blue = 0x56;

    unsigned int color = 0;

    colorprint(color);

    color += alpha;
    colorprint(color);

    color <<= 8;
    color += red;
    colorprint(color);

    color <<= 8;
    color += green;
    colorprint(color);

    color <<= 8;
    color += blue;
    colorprint(color);
    



    return 0;
}