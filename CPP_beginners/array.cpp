#include <iostream>
#include <iomanip>

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

    // Multi dimensional array

    string animals[2][3] = {
        {"fox", "dog", "cat"},
        {"mouse", "squirrel", "parrot"}
    };

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout << "For i: " << i << ", j: " << j << ": " << animals[i][j] << endl;
        }
    }

    const int sizeoftimestable = 15;

    int timestable[sizeoftimestable][sizeoftimestable] = {};

    for(int i=0; i<sizeoftimestable; i++)
    {
        for(int j=0; j<sizeoftimestable; j++)
        {
            if(i == 0)
            {
                timestable[i][j] = j + 1;
            } else if(j == 0)
            {
                timestable[i][j] = i + 1;
            } else
            {
                timestable[i][j] = (i + 1) * (j + 1);
            }
        }
    }

    for (int i=0; i<sizeoftimestable; i++)
    {
        for(int j=0; j<sizeoftimestable; j++)
        {
            cout << setw(3) << timestable[i][j] << " " << flush;
        }
        cout << endl;
    }

    // Sizeof

    cout << "total entries: " << sizeof(timestable)/sizeof(int) << endl;
    cout << "size of table: " << sizeof(timestable[0])/sizeof(int) << endl;
    cout << "or..? " << sizeof(timestable)/sizeof(timestable[0]) << endl;

    cout << "But with animals!\n" << 
    "rows: " << sizeof(animals)/sizeof(animals[0]) << endl;
    cout << "cols: " << sizeof(animals[0])/sizeof(string) << endl;

    return 0;
}