#include <math.h>

#include "particle.hpp"
#include "swarm.hpp"
#include "window.hpp"

int main () {

    srand(time(NULL));

    Window mainwindow;

    if (!mainwindow.init()) {
        std::cout << "You broke it." << std::endl;
    }

    Swarm swarm;
    const int CURR_WIDTH = Window::WINDOW_WIDTH/2;
    const int CURR_HEIGHT = Window::WINDOW_HEIGHT/2;

    while (true) {
        // Update color
        int elapsed = SDL_GetTicks();

        // mainwindow.clear();
        swarm.update(elapsed);

        // std::cout << sin(elapsed) << std::endl;

        unsigned char red = ((1 + sin(elapsed * 0.0008)) * 78) + 100;
        unsigned char green = ((1 + sin(elapsed * 0.0009)) * 78) + 100;
        unsigned char blue = ((1 + sin(elapsed * 0.0007)) * 78) + 100;
        

        // unsigned char red = ((1 + sin(elapsed * 0.0008)) * 128);
        // unsigned char green = ((1 + sin(elapsed * 0.0009)) * 128);
        // unsigned char blue = ((1 + sin(elapsed * 0.0007)) * 128);

        // Draw particles
        const Particle *const p_particles = swarm.particles();

        for(int i=0; i < Swarm::NPARTICLES; i++) {
            Particle particle = p_particles[i];
            int x = (particle.m_x * CURR_WIDTH);
            int y = (((particle.m_y - 1) * CURR_WIDTH) + CURR_HEIGHT);
            // if (i == 0) {
            // if (x <= -1 || x>= 800 || y <= -1 || y >= 600) {
            //     std::cout << "m_x: " << particle.m_x << " m_y: " << particle.m_y << " x: " << x << " y: " << y << std::endl;
            // }
            mainwindow.set_pixel(x, y, red, green, blue);
        }

        mainwindow.box_blur();

        // Update screen
        mainwindow.screen_update();

        // Check for messages/events
        if (mainwindow.process_events() == false){
            break;
        }
    }

    mainwindow.close();

    return 0;
}