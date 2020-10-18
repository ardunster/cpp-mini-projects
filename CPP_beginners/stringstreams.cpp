// String Streams

#include <iostream>
#include <sstream>

using namespace std;

int main() {

    int age = 475;
    string name = "George";

    stringstream ss;

    ss << "Name: " << name << ", Age: " << age;

    cout << ss.str() << endl;

    ss << ", Favorite cat is Steve";

    string thing = ss.str();

    // ss << ", Does this work?"; // No it doesn't 

    cout << thing << endl;

    // Let's put reversing strings here because there's hardly anything in this file

    // Reversing Strings

    char stuff[] = "george";
    stringstream rev_stuff;

    // I try

    for (int i=(sizeof(stuff) - 1), j=0; i > -1; i--, j++) {
        cout << "i: " << i << ", j: " << j << endl;
        cout << "stuff[i]: " << stuff[i] << ", stuff[j]: " << stuff[j] << endl;
        if(!((int)stuff[i] == 0)) {
            rev_stuff << stuff[i];
        }
        cout << rev_stuff.str() << endl;
    }
    string ffuts = rev_stuff.str();

    cout << "ffuts: " << ffuts << endl;

    // I try again without stringstream

    char ffuts2[sizeof(stuff)];

    for (int i=(sizeof(stuff) - 1), j=0; i > -1; i--) {
        if(!((int)stuff[i] == 0)) {
            ffuts2[j] = stuff[i];
            j++;
        }
    }

    ffuts2[sizeof(stuff) - 1] = stuff[sizeof(stuff) - 1];

    cout << "ffuts2: " << ffuts2 << endl;

    // Lesson method w pointers 

    char text[] = "hello";
    int n_chars = sizeof(text) - 1;
    char* p_text_position = text;
    char* p_end = text + n_chars - 1;

    while(p_text_position < p_end) {

        char save = *p_text_position;

        *p_text_position = *p_end;

        *p_end = save;

        p_text_position++;
        p_end--;

    }

    cout << text << endl;



    return 0;
}

