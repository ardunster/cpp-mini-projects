#include <math.h>

#include "window.hpp"

int main () {

    Window mainwindow;

    if (!mainwindow.init()) {
        std::cout << "You broke it." << std::endl;
    }

    while (true) {
        // Update particles
        // Draw particles
        int elapsed = SDL_GetTicks();

        unsigned char red = (1 + sin(elapsed * 0.0008)) * 128;
        unsigned char green = (1 + sin(elapsed * 0.0008)) * 128;
        unsigned char blue = (1 + sin(elapsed * 0.0008)) * 128;

        for(int y=0; y < Window::WINDOW_HEIGHT; y++) {
            for(int x=0; x < Window::WINDOW_WIDTH; x++) {
                mainwindow.set_pixel(x, y, red, green, blue);
            }
        }

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