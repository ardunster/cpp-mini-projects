#ifndef SWARM_HPP
#define SWARM_HPP

#include "particle.hpp"

class Swarm {
private:
    Particle *m_particles;
public:
    const static int NPARTICLES = 5000;
    Swarm();
    virtual ~Swarm();
    const Particle *const particles() {return m_particles;};
};

#endif // !SWARM_HPP
