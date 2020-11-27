#include "window.hpp"

int main () {

    Window mainwindow;

    if (!mainwindow.init()) {
        std::cout << "You broke it." << std::endl;
    }

    while (true) {
        // Update particles
        // Draw particles

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