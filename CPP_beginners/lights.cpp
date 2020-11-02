#include <iostream>

#include "lights.hpp"

namespace Lights 
{
Lamp::Lamp() {
    std::cout << "Done built an illuminatory." << std::endl;
}

Lamp::~Lamp() {
    std::cout << "Done broke down an illuminatory." << std::endl;
}

void Lamp::turn_on() {
    std::cout << "Ahhhh, light." << std::endl;
}
} /* namespace Lights */