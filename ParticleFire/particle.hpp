#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <stdlib.h>
#include <math.h>

class Particle {
public:
    double m_x;
    double m_y;
    double speed;
    // double xspeed;
    // double yspeed;
    double m_speed;
    double m_direction;
    Particle();
    virtual ~Particle();
    void update(int interval);
};

#endif // !PARTICLE_HPP
