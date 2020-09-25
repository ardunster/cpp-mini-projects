#include <iostream>

using namespace std;

int main()
{
    int i = 0;

    while(i < 5)
    {
        cout << "Oye" << endl;
        i++;
    }

    int george = 8;

    do {
        cout << "Some stuff " << ++george << endl;
        // george++;

    } while(george < 10);
    // do while will always run at least once even if condition is true.

    const string password = "Steve";
    string user_input;

    // do {
    //     cout << "Enter the password: " << flush;
    //     cin >> user_input;

    //     if(user_input != password){
    //         cout << "Incorrect." << endl;
    // }
    // }
    // while(user_input != password);

    // cout << "Aight you win." << endl;

    // do {
    //     cout << "Enter the password: " << flush;
    //     cin >> user_input;

    //     if(user_input == password){
    //         cout << "Aight you win." << endl;
    //         break;
    //     }

    //     cout << "Incorrect." << endl;
    // }
    // while(user_input != password);


    do {
        cout << "Enter the password: " << flush;
        cin >> user_input;

        if(user_input == password){
            continue;
        }

        cout << "Incorrect." << endl;
    }
    while(user_input != password);

    cout << "Aight you win." << endl;

    return 0;
}