#ifndef LIGHTS_HPP
#define LIGHTS_HPP

namespace Lights
{
/** Light class in Lights */
class Light {
private:
    int id;
public:
    Light();
    Light(int id);
    ~Light();
    void turn_on();
    void get_info();
};
/** Lamp class in Lights */ 
class Lamp: public Light {
public:
    Lamp();
    Lamp(int id);
    virtual ~Lamp();
    void turn_on();
};

class DeskLamp: public Lamp {
public: 
    DeskLamp();
    ~DeskLamp();

};

} /* namespace Lights */

#endif // !LIGHTS_HPP