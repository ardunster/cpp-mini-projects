#include <iostream>

using namespace std;

/** Ribbity class of classiness */
class Frog {
private: 
    string name;

public: 
    Frog() {
        name = "<unnamed>";
        cout << "Creating Frog " << name << endl;
    }
    Frog(string name): name(name) {
        cout << "Creating Frog " << name << endl;
    }
    Frog(const Frog& original): name(original.name) {
        cout << "Copying Frog..." << endl; 
    }

    ~Frog() {
        cout << "DESTROYING FROG " << name << " D:< " << endl;
    }
    void set_name(string name) {
        this->name = name;
    };
    void speak() const {
        cout << "This frog's name is " << name << endl;
    }
};

/** This is a terrible idea in modern C++ and relies on the user to know they 
 * have to delete this object! D: */
Frog *spawn_frog() 
{
    Frog *spawned = new Frog();
    spawned->set_name("frogspawn");
    return spawned;
}

int main() {

    Frog froggy("froggy");
    Frog froggit = froggy;
    froggit.speak();
    froggit.set_name("steve");

    froggy.speak();
    froggit.speak();

    Frog frog = Frog("george");
    frog.speak();

    Frog frog1;
    frog1.speak();
    frog1 = Frog("stevella");
    frog1.speak();


    // New operator

    Frog *pfrog1 = new Frog;

    pfrog1->set_name("pointy");
    pfrog1->speak();

    delete pfrog1;

    // Returning objects from functions

    Frog *spawned_frog = spawn_frog();

    spawned_frog->speak();

    delete spawned_frog;

    return 0;
}