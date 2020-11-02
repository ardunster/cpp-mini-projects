#include <iostream>

#include "lights.hpp"

namespace Lights 
{

Light::Light(): id(0) {
    std::cout << "Procured a Light." << std::endl;
}

Light::Light(int id): id(id) {
    std::cout << "Procured a Specific Light: " << id << std::endl;
}

Light::~Light() {
    std::cout << "Removed a Light." << std::endl;
}

void Light::turn_on() {
    std::cout << "Turned on a Light." << std::endl;
}

void Light::get_info() {
    std::cout << "Light ID: " << id << std::endl;
}

Lamp::Lamp() {
    std::cout << "Done built an illuminatory." << std::endl;
}

Lamp::Lamp(int id): Light(id) {
    std::cout << "Done built an illuminatory." << std::endl;
}

Lamp::~Lamp() {
    std::cout << "Done broke down an illuminatory." << std::endl;
}

void Lamp::turn_on() {
    std::cout << "Ahhhh, light." << std::endl;
}

DeskLamp::DeskLamp() {
    std::cout << "Put a Lamp on the Desk." << std::endl;
}

DeskLamp::~DeskLamp() {
    std::cout << "Took a Lamp off the Desk." << std::endl;
}
} /* namespace Lights */