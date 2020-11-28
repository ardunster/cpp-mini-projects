#include "particle.hpp"

Particle::Particle() {

    m_x = ((2.0 * rand())/RAND_MAX);
    m_y = ((2.0 * rand())/RAND_MAX);

    speed = (rand() % 10 + 1) * 0.001;
    xspeed = speed * ((2.0 * rand())/RAND_MAX - 1);
    yspeed = speed * ((2.0 * rand())/RAND_MAX - 1);

}

void Particle::update() {
    m_x += xspeed;
    m_y += yspeed;

    if (m_x <= 0.01 || m_x >= 1.99) {
        // xspeed = -xspeed;
        // m_x += (2*xspeed);
        m_x = 1.0;
    }

    if (m_y <= 0.01 || m_y >= 1.99) {
        // yspeed = -yspeed;
        // m_y += (2*yspeed);
        m_y = 1.0;
    }

}

Particle::~Particle() {}