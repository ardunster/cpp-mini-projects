#ifndef CAT
#define CAT

#include <iostream>

using namespace std;


class Cat {
private: 
    bool happy;
    string name;
public:
    Cat();
    void jump();
    void luvvies();
    void no_luv();
    void set_name(string new_name);
    void speak();
    string stringify();

    ~Cat();
};

#endif // !CAT
