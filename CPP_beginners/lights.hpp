#ifndef LIGHTS_HPP
#define LIGHTS_HPP

namespace Lights
{
/** Lamp class in Lights */ 
class Lamp {
public:
    Lamp();
    virtual ~Lamp();
    void turn_on();
};

} /* namespace Lights */

#endif // !LIGHTS_HPP