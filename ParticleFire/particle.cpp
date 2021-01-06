#include "particle.hpp"

Particle::Particle() {
    init();
}

void Particle::init() {
    m_x = 1.0;
    m_y = 1.0;
    speed = (rand() % 10 + 1) * 0.000055;
    // Experimental speed modifier used with very small swarms.
    // speed = (rand() % 10 + 1) * 0.0004;

    // Generate random speed and direction for each particle.
    m_direction = ((2 * M_PI * rand())/RAND_MAX);
    m_speed  = ((speed * rand())/RAND_MAX);
}

void Particle::update(int interval) {
    // Introduce constant curve to path of particles.
    m_direction += interval * 0.0004;

    // Calculate direction of particles from speed and direction variables,
    // update particle positions in a field from 0 to 2, (1,1) being center.
    double xspeed = m_speed * cos(m_direction);
    double yspeed = m_speed * sin(m_direction);

    m_x += xspeed * interval;
    m_y += yspeed * interval;

    // If particle goes out of bounds, reset to center. 
    // if (m_x <= 0 || m_x >= 2) {
    //     m_x = 1.0;
    //     m_y = 1.0;
    // }

    // if (m_y <= 0 || m_y >= 2) {
    //     m_y = 1.0;
    //     m_x = 1.0;
    // }

    // Alternatively, if particle goes out of bounds, reinitialize.
    if(m_x <= 0 || m_x >= 2 || m_y <= 0 || m_y >= 2) {
        init();
    }

    // Randomly reinitialize some portion of particles.
    if(rand() < RAND_MAX/100) {
        init();
    }
}

Particle::~Particle() {}