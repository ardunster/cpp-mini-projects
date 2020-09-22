#include <iostream>

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
    cin >> user_selection;

    if(user_selection == 1) {
        cout << "New pistachio in progress, please wait seven to ten years. "
        "Hope your climate is good for it!" << endl;
    }
    if(user_selection == 2) {
        cout << "Garbage deleted. What do you mean that wasn't garbage?" << endl;
    }
    if(user_selection == 3) {
        cout << "Viewing frog. :heart eyes:" << endl;
    }
    if(user_selection == 4) {
        cout << "Searching....\nSearching....\nSearching....\n"
        "Sorry, no waffles were found. :(" << endl;
    }
    if(user_selection == 5) {
        cout << "But why would you want to? <3" << endl;
    }
    else {
        cout << "There's no escape here!" << endl;
    }
    return 0;
}