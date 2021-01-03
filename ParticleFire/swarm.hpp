#ifndef SWARM_HPP
#define SWARM_HPP

#include "particle.hpp"

class Swarm {
private:
    Particle *m_particles;
    int last_time;
public:
    const static int NPARTICLES = 10000;
    Swarm();
    virtual ~Swarm();
    const Particle *const particles() {return m_particles;};
    void update(int elapsed);
};

#endif // !SWARM_HPP
