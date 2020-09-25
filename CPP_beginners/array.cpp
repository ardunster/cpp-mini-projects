#include <iostream>

using namespace std;

int main() {

    int values[3];

    values[0] = 75;

    values[1] = 12;

    values[2] = 9837;

    cout << values[2] << endl;

    double doublevalues[5] = {12, 17.5, 18, 42.67, 238};

    for(int i=0; i<5; i++)
    {
        cout << doublevalues[i];
        if(i==4) {
            cout << flush;
            break;
        }
        cout << ", " << flush;
    } cout << endl;

    int starts_empty[8] = {};

    for(int i=0; i<8; i++)
    {
        cout << starts_empty[i];
        if(i==7) {
            cout << flush;
            break;
        }
        cout << ", " << flush;
    } cout << endl;

    string froo_its[] = {"Steve", "Joe", "Fred", "George"};

    for(int i=0; i<4; i++)
    {
        cout << froo_its[i];
        if(i==3) {
            cout << flush;
            break;
        }
        cout << ", " << flush;
    } cout << endl;


    return 0;
}