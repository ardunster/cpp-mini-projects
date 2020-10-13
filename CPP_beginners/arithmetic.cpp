#include <iostream>

using namespace std;

/*
 * +
 * -
 * *
 * /
 * +=
 * -=
 * /=
 * *=
 * %
 * %=
 * precedence
 */

void print_val(string name, double value) {
    cout << name << ": " << value << endl;
}

int main() {

    int value1 = 7/2;

    double seven = 7.0;
    double two = 2.0;

    // double value2 = seven/two;
    double value2 = double(7)/2;

    print_val("value1", value1);
    print_val("value1", value1);

    int value3 = 8;
    value3 += 2;

    print_val("value3", value3);
    value3++;
    print_val("value3", value3);

    value3 *= 3;

    print_val("value3", value3);

    value3 /= 3;

    print_val("value3", value3);

    int value5 = 12%5;

    print_val("value5", value5);

    int value6 = 13;

    value6 %= 5;

    print_val("value6", value6);

    double equation = 5.3/4+2*6; // = (5.3/4) + (2*6)

    // Much better to use parenthesis to define order of operations,
    // although c++ does have regular precedence.

    print_val("equation", equation);

    // Take some large number of seconds and convert to hours, minutes, seconds

    int total_seconds = 2903840;

    int seconds = total_seconds % 60;

    print_val("seconds", seconds);

    int total_minutes = total_seconds / 60;
    int minutes = total_minutes % 60;

    print_val("minutes", minutes);

    int hours = total_minutes / 60;

    print_val("hours", hours);

    cout << "Let's verify:\nHours * 60 = " << hours * 60 << "\nMinutes * 60 = " 
    << minutes * 60 << "\nTotal of (hours * 60 * 60) + (minutes * 60) + (seconds) = " 
    << (hours * 60 * 60) + (minutes * 60) + (seconds) << "\nTotal seconds: " <<
    total_seconds << endl;

    // Write a for loop that iterates 10,000 times, but outputs a . to the line 
    // every 100th iteration.

    for(int i=1; i<10001; i++)
    {
        if((i % 100 == 0) && (i % 1000 == 0)) {
            cout << "." << i << endl;
        } else if(i % 100 == 0)
        {
            cout << "." << flush;
        } 
    }
    cout << "Done." << endl;


    return 0;
}