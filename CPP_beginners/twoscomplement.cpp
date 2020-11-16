#include <iostream>
using namespace std;

// Static:

// header
class Test {
private:
    static int count;
    int id;

public:
    //prefix increment to start at 1 :) 
    Test() { id = ++count; }
    static void show_count() {
        cout << "Count: " << count << endl;
    }
    void show_id() {
        cout << "ID: " << id << endl;
    }
    // Initialization of const must be done at declaration
    static int const MAX = 999;
};

// source
int Test::count = 0;

int main() {
    char value = 127;

    cout << (int)value << endl;
    cout << value << endl;

    value++;

    cout << (int)value << endl;
    // cout << value << endl;

    // cout << Test::count << endl;
    Test::show_count();
    cout << Test::MAX << endl;

    Test test1;
    Test test2;

    Test::show_count();

    Test test3;


    test3.show_count();
    test3.show_id();

    test1.show_count();
    test1.show_id();

    return 0;
}