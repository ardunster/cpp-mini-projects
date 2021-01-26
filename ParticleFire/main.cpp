#include <math.h>

#include "particle.hpp"
#include "swarm.hpp"
#include "window.hpp"

// Global variable defaults
const int NPARTICLES = 3000;
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const float RED_SPEED_FACTOR = 0.0008;
const float GREEN_SPEED_FACTOR = 0.0009;
const float BLUE_SPEED_FACTOR = 0.0007;

unsigned char update_color(int elapsed, float color_speed_factor) {
    return ((1 + sin(elapsed * color_speed_factor)) * 78) + 100;
}

int main () {

    srand(time(NULL));

    Window mainwindow(WINDOW_WIDTH, WINDOW_HEIGHT);

    if (!mainwindow.init()) {
        std::cout << "You broke it." << std::endl;
    }

    Swarm swarm(NPARTICLES);
    const int CURR_WIDTH = mainwindow.window_width/2;
    const int CURR_HEIGHT = mainwindow.window_height/2;

    unsigned char red;
    unsigned char green;
    unsigned char blue;

    while (true) {
        // Update color
        int elapsed = SDL_GetTicks();

        // If we blur here, individual particles are more clear.
        mainwindow.box_blur();

        // Clear the main window if not using blur.
        // mainwindow.clear();

        // We pass elapsed to update in order to generate an interval to 
        // normalize speeds.
        swarm.update(elapsed);

        // Shift colors
        red = update_color(elapsed, RED_SPEED_FACTOR);
        green = update_color(elapsed, GREEN_SPEED_FACTOR);
        blue = update_color(elapsed, BLUE_SPEED_FACTOR);

        // Draw particles
        const Particle *const p_particles = swarm.particles();

        for(int i=0; i < swarm.nparticles; i++) {
            Particle particle = p_particles[i];
            int x = (particle.m_x * CURR_WIDTH);
            int y = (((particle.m_y - 1) * CURR_WIDTH) + CURR_HEIGHT);
            mainwindow.set_pixel(x, y, red, green, blue);
        }

        // If we blur here instead, individual particles are less clear.
        // mainwindow.box_blur();

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