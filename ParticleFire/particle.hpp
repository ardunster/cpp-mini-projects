#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <stdlib.h>

class Particle {
public:
    double m_x;
    double m_y;
    Particle();
    virtual ~Particle();
};

#endif // !PARTICLE_HPP
