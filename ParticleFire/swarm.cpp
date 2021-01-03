#include "swarm.hpp"

Swarm::Swarm(): last_time(0) {
    m_particles = new Particle[NPARTICLES];
}

void Swarm::update(int elapsed) {
    int interval = elapsed - last_time;

    for (int i=0; i < NPARTICLES; i++)
    {
        m_particles[i].update(interval);
    }

    last_time = elapsed;
}


Swarm::~Swarm() {
    delete [] m_particles;
}
