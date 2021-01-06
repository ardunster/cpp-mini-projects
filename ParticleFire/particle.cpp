#include "particle.hpp"

Particle::Particle() : m_x(1.0), m_y(1.0) {

    // m_x = ((2.0 * rand())/RAND_MAX);
    // m_y = ((2.0 * rand())/RAND_MAX);

    speed = (rand() % 10 + 1) * 0.000055;
    // xspeed = speed * ((2.0 * rand())/RAND_MAX - 1);
    // yspeed = speed * ((2.0 * rand())/RAND_MAX - 1);

    m_direction = ((2 * M_PI * rand())/RAND_MAX);
    m_speed  = ((speed * rand())/RAND_MAX);
    // m_speed = ((0.001 * rand())/RAND_MAX);

}

void Particle::update(int interval) {

    m_direction += interval * 0.0004;

    double xspeed = m_speed * cos(m_direction);
    double yspeed = m_speed * sin(m_direction);

    m_x += xspeed * interval;
    m_y += yspeed * interval;

    if (m_x <= 0 || m_x >= 2) {
        // xspeed = -xspeed;
        // m_x += (2*xspeed);
        m_x = 1.0;
        m_y = 1.0;
    }

    if (m_y <= 0 || m_y >= 2) {
        // yspeed = -yspeed;
        // m_y += (2*yspeed);
        m_y = 1.0;
        m_x = 1.0;
    }

}

Particle::~Particle() {}