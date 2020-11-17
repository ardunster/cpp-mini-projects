#include <iostream>
#include <SDL.h>

int main () {

    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;
    // std::cout << "File working" << std::endl;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL Init Failed" << std::endl;
        return 1;
    }

    // std::cout << "Successful Init" << std::endl;
    SDL_Window *window = SDL_CreateWindow("Particle Fire Test", 
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
        WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == NULL) {
        std::cout << "Failed to create window, error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 2;
    }

    bool quit = false;

    SDL_Event event;

    while(!quit) {
        // Update particles
        // Draw particles
        // Check for messages/events

        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                quit = true;
            }
        }
    }

    // SDL_Delay(4000);

    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}