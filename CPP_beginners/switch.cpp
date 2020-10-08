#include <iostream>
#include <limits>

using namespace std;

int get_input() 
{
    int user_input = 0;
    while (user_input == 0) {
    
    cout << "\nPlease choose from one of the following meaningless options:\n" <<
    "1: Absolutely nothing useful\n" << 
    "2: I'm getting some practice here, okay?\n" <<
    "3: Self talk is important to success\n" <<
    "4: So you should try to talk nice to yourself\n" <<
    "5: I mean it.\n" <<
    "6: exit :(\n"
    "> " << flush;

    cin >> user_input;

    if(cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        user_input = 0;
    }
    }
    return user_input;
}

int select(int user_input)
{
    switch (user_input) 
    {
    case 1: 
        cout << "Are you sure??" << endl;
        user_input = 0;
        break;
    case 2: 
        cout << "YES PRACTICE, Good, do it! :chaos:" << endl;
        user_input = 0;
        break;
    case 3: 
        cout << "Super important, yes" << endl;
        user_input = 0;
        break;
    case 4:
        cout << "But, but..... it's hard!" << endl;
        user_input = 0;
        break;
    case 5:
        cout << ":gasp: okay I'll be good D: " << endl;
        user_input = 0;
        break;
    case 6:
        cout << "Goodbye :sob:" << endl;
        break;
    default:
        cout << "You have to pick a number on the list or it doesn't work :(\n" << endl;
        user_input = 0;
    
    }
    return user_input;
}

int main()
{
    int user_input = 0;

    cout << "Bogus menu!!!" << endl;

    while (user_input == 0) {
    user_input = get_input();

    user_input = select(user_input);

    }
    return 0;
}