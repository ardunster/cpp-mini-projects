#include "swarm.hpp"

Swarm::Swarm(int nparticles): nparticles(nparticles), last_time(0) {
    m_particles = new Particle[nparticles];
}

void Swarm::update(int elapsed) {
    int interval = elapsed - last_time;

    for (int i=0; i < nparticles; i++)
    {
        m_particles[i].update(interval);
    }

    last_time = elapsed;
}


Swarm::~Swarm() {
    delete [] m_particles;
}
