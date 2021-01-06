#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <stdlib.h>
#include <math.h>

class Particle {
private:
    double speed;
    double m_speed;
    double m_direction;
    void init();
public:
    double m_x;
    double m_y;
    Particle();
    virtual ~Particle();
    void update(int interval);
};

#endif // !PARTICLE_HPP
