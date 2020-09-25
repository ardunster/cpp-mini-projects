#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << "Welcome to Hogwash's Baloney Menu!\nPlease select from the following nonsense options:" << endl;
    cout << "1. New pistachio" << endl;
    cout << "2. Delete garbage" << endl;
    cout << "3. View frog" << endl;
    cout << "4. Search for waffles" << endl;
    cout << "5. You can never escape" << endl;

    cout << "Pick your poison!\n> " << flush;

    int user_selection;
    // cin >> user_selection;
    user_selection = 3;

    if(user_selection == 1) {
        cout << "New pistachio in progress, please wait seven to ten years. "
        "Hope your climate is good for it!" << endl;
    }
    else if(user_selection == 2) {
        cout << "Garbage deleted. What do you mean that wasn't garbage?" << endl;
    }
    else if(user_selection == 3) {
        cout << "Viewing frog. :heart eyes:" << endl;
    }
    else if(user_selection == 4) {
        cout << "Searching....\nSearching....\nSearching....\n"
        "Sorry, no waffles were found. :(" << endl;
    }
    else if(user_selection == 5) {
        cout << "But why would you want to escape? <3" << endl;
    }
    else {
        cout << "There's no escape here!" << endl;
    }

    // Floats

    float value1 = 1.1;

    if(value1 == 1.1) {
        cout << "yep" << endl;
    } 
    else {
        cout << "nup " << setprecision(10) << value1 << endl;
    }

    int numero_uno = 5;
    int numero_dos = 10;

    // bitwise and
    if(numero_uno == 5 && numero_dos <= 11) {
        cout << "Yep" << endl;
    } 
    else {
        cout << "Nup" << endl;
    }

    // bitwise or
    if(numero_uno == 3 || numero_dos >= 10) {
        cout << "Yep" << endl;
    } 
    else {
        cout << "Nup" << endl;
    }

    bool condition_uno = (numero_uno < 2) && (numero_dos == 10);
    cout << condition_uno << endl;
    bool condition_dos = (numero_uno == 7) || (numero_dos > 3);
    cout << condition_dos << endl;
    bool condition_tres = (numero_uno == 5) && (numero_dos > 3);
    // Accidentally set numero_uno = 7 instead of numero_uno == 7 oops
    // cout << "a: " << bool (numero_uno == 5) << endl;
    // cout << "numero uno: " << setprecision(10) << numero_uno << endl;
    // cout << "b: " << bool (numero_dos > 3) << endl;
    cout << condition_tres << endl;
    cout << "Total conditions: " << (condition_uno + condition_dos + condition_tres)
    << endl;

    string name1 = "fred";
    string name2 = "george";

    if(name1 == "Fred") {
        cout << "Hi frederick" << endl;
    }
    else {
        cout << "hi " << name2 << endl;
    }


    return 0;
}