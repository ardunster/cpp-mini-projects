#include "particle.hpp"

Particle::Particle() {

    m_x = ((2.0 * rand())/RAND_MAX);
    m_y = ((2.0 * rand())/RAND_MAX);

}

Particle::~Particle() {}