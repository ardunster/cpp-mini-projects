#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <stdlib.h>

class Particle {
public:
    double m_x;
    double m_y;
    double speed;
    double xspeed;
    double yspeed;
    Particle();
    virtual ~Particle();
    void update();
};

#endif // !PARTICLE_HPP
