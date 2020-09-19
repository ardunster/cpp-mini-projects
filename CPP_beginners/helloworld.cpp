#include <iostream>
#include <limits>
using namespace std;

int main() {

    int number_cats;
    int number_dogs;
    int total_animals;
    string name;

    cout << INT_MAX << endl;

    cout << "Enter your name: " << flush;

    cin >> name;

    cout << "Number of cats: " << flush;

    cin >> number_cats;

    cout << "Number of dogs: " << flush;

    cin >> number_dogs;

    total_animals = number_cats + number_dogs;

    cout << "Total animals: " << total_animals << endl;

    cout << "Several dogs found new homes." << endl;

    number_dogs = number_dogs - 14;

    cout << "New number of dogs: " << number_dogs << endl;

    total_animals = number_cats + number_dogs;

    cout << "Congratulations, " << name << ", you now have " << total_animals
    << " animals!" << endl;

    return 0;
}