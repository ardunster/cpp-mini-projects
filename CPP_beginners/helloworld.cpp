#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

// Commented code lines are left for reference, but things I don't want running
// in my code during play time. This is a learning file, afterall!

int main() {

    int number_cats;
    int number_dogs;
    int total_animals;
    // float food_in_storage;
    double food_in_storage;
    string name;
    bool have_food = true;

    // cout << INT_MAX << endl;

    cout << "Enter your name: " << flush;
    name = "Pistachio Steve";
    cout << name << endl;
    // cin >> name;

    cout << "Number of cats: " << flush;
    number_cats = 3;
    cout << number_cats << endl;
    // cin >> number_cats;

    cout << "Number of dogs: " << flush;
    number_dogs = 15;
    cout << number_dogs << endl;
    // cin >> number_dogs;

    total_animals = number_cats + number_dogs;
    cout << "Total animals: " << total_animals << endl;

    cout << "Several (14) dogs found new homes." << endl;
    number_dogs = number_dogs - 14;

    cout << "New number of dogs: " << number_dogs << endl;
    total_animals = number_cats + number_dogs;

    cout << "Congratulations, " << name << ", you now have " << total_animals
    << " animals!" << endl;

    // cout << "Size of total animals variable: " << sizeof(total_animals) << endl;

    // cout << "Size of name variable: " << sizeof(name) << endl;

    food_in_storage = 12.7;

    cout << "You have " << setprecision(20) << fixed << food_in_storage << " lbs of animal food available." << endl;

    // cout << "Float: " << sizeof(float) << endl;
    // cout << "Double: " << sizeof(double) << endl;
    // cout << "Long Double: " << sizeof(long double) << endl;

    // cout << have_food << endl;

    char charry = 55;

    cout << "Char is 7: " << charry << endl;
    cout << "Value in char variable: " << (int)charry << endl;
    cout << "Size of char: " << sizeof(char) << endl;

    return 0;
}