#include <iostream>
#include "lamp.hpp"
#include "lights.hpp"

using namespace std;

int main() {

    Lamp light1;
    light1.turn_on();

    Lights::Lamp light2;
    light2.turn_on();


    return 0;
}