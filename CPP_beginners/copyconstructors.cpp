#include <iostream>

using namespace std;


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
    void set_name(string name) {
        this->name = name;
    };
    void speak() const {
        cout << "This frog's name is " << name << endl;
    }
};

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
    return 0;
}