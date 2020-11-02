#include <iostream>

#include "lamp.hpp"

Lamp::Lamp() {
    std::cout << "Done built a lamp." << std::endl;
}

Lamp::~Lamp() {
    std::cout << "Done broke down a lamp." << std::endl;
}

void Lamp::turn_on() {
    std::cout << "Ahhhh, illumination." << std::endl;
}