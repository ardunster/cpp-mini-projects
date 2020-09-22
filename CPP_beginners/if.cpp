#include <iostream>

using namespace std;

int main() {

    string secret_word = "pistachio";

    cout << "What's the secret word? D: You better tell me the right secret word!"
    << endl;

    cout << "> " << flush;

    string user_input;
    cin >> user_input;

    if(user_input == secret_word) {
        cout << "Awesome, how did you guess? You couldn't possibly have known that."
        << endl;
    }

    if (user_input != secret_word) {
        cout << "You've done it now!" << endl;
    }

    int secret_number = 42;

    cout << "What's the secret number?" << endl;
    cout << "Hint: it's 6 * 7." << endl;
    cout << "> " << flush;

    int number_input;
    cin >> number_input;

    if (number_input == secret_number) {
        cout << "AWESOME!!!" << endl;
    }

    

    return 0;
}