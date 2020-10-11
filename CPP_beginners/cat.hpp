#ifndef CAT
#define CAT

#include <iostream>
#include <sstream>

using namespace std;


class Cat {
private: 
    bool happy;
    string name;
public:
    Cat();
    Cat(string name, bool happy);
    void jump();
    void luvvies();
    void no_luv();
    void set_name(string name);
    void speak();
    string stringify();

    ~Cat();
};

#endif // !CAT
