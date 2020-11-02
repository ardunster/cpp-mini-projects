#include <iostream>
#include "lamp.hpp"
#include "lights.hpp"

using namespace std;

int main() {

    {
    Lamp light1;
    light1.turn_on();
    }
    Lights::Lamp light2;
    light2.turn_on();


    // Inheritance 
    // Constructor Inheritance

    std::cout << "==============" << std::endl;

    Lights::Light light;
    light.get_info();
    Lights::Light light42(42);
    light42.get_info();

    light2.get_info();

    Lights::DeskLamp desklamp;
    
    Lights::Lamp lamp70(70);
    lamp70.get_info();


    return 0;
}