#include <iostream>

using namespace std;

// Using book as reference to work on understanding of pointers

// Best quote about pointers, seen on stackexchange: "We use pointers
// because it's easier to give someone an address to your home than to
// give a copy of your home to everyone." -- Rishi Dua

int i = 15, j, *p, *q;
int a[5], *y;

// I made these functions though, copy pasting too may couts :0
void print_values() {
    cout << "=================" << endl;
    cout << "i: " << i << endl;
    cout << "p: " << p << endl;
    cout << "j: " << j << endl;
    cout << "q: " << q << endl;
    cout << "=================" << endl;
}

void print_values_2() {
    cout << "=================" << endl;
    cout << "a: " << a << endl;
    cout << "y: " << y << endl;
    cout << "a[0]: " << a[0] << "\na[1]: " << a[1] << "\na[2]: " << a[2] 
    << "\na[3]: " << a[3] << "\na[4]: " << a[4] << endl;
    cout << "=================" << endl;
}


int main() 
{


    p = &i;

    print_values();


    cout << "*p = 20;" << endl;
    *p = 20;

    print_values();

    cout << "j = 2 * *p;\nq = &i;\n*p = *q - 1;" << endl;
    j = 2 * *p;
    q = &i;
    *p = *q - 1;

    print_values();

    cout << "q = &j;\n*p = *q - 1;" << endl;
    q = &j;
    *p = *q - 1;

    print_values();

    cout << "p = new int;" << endl;
    p = new int;
    
    print_values();

    cout << "delete p;" << endl;
    delete p;

    print_values();

    cout << "p = 0;" << endl;
    p = 0;

    print_values();

    cout << "Arrays." << endl;

    print_values_2();

    // a = y;
    // a++;

    for (int i = 1; i < sizeof(a)/sizeof(int); i++)
    {
        a[i] = i;
    }

    print_values_2();

    {
    int sum;

    cout << "using array notation: " << endl;
    for (sum = a[0], i = 1; i < 5; i++)
    {
        // cout << "sum: " << sum << "\ni: " << i << endl;
        sum += a[i];
    }
    
    cout << sum << endl;
    }

    {
    int sum;

    cout << "using pointer notation: " << endl;
    for (sum = *a, i = 1; i <5; i++)
    {
        // cout << "sum: " << sum << "\ni: " << i << endl;
        sum += *(a + i);
    }
    cout << sum << endl;
    }

    {
    int sum;

    cout << "alternate pointer notation: " << endl;
    for (sum = *a, y = a+1; y < a+5; y++)
    {
        cout << "sum: " << sum << "\ny: " << y << endl;
        sum += *y;
    }
    cout << sum << endl;
    }

    char b[5] = {'a', 'b', 'c', 'd', 'e'};

    cout << "b: " << b << "&b: " << &b << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "b[i]: " << b[i] << "\n&b[i]: " << &b[i] << flush;
    }

    char c = 'f';
    cout << "c: " << c << "\n&c: " << &c << endl;

    int d = 1;
    cout << "d: " << d << "\n&d: " << &d << endl;

    // All of this didn't work how I wanted because I didn't understand char:
    // char *x;

    // for (int i = 0; i < 5; i++)
    // {
    //     b[i] = 'f';
    //     // cout << "b[i]: " << b[i] << endl;
    // }
    // cout << x << endl; // segfault, lol

    // for (char thing = *b, x = &b+1; x < b+5; x++)
    // {
    //     cout << "thing: " << thing << "x: " << x << endl;
    // }

    string e = b;

    cout << "e: " << e << "&e: " << &e << endl;

    char **x;
    cout << "x: " << x << endl;
    ++x;
    cout << "x++ x: " << x << endl;


    return 0;
}