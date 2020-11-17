#include <iostream>
#include <SDL.h>

int main () {

    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL Init Failed" << std::endl;
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Particle Fire Dance", 
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
        WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == NULL) {
        std::cout << "Failed to create window, error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 2;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

    if (renderer == NULL) {
        std::cout << "Failed to create renderer, error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 3;
    }

    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STATIC, WINDOW_WIDTH, WINDOW_HEIGHT);

    if (texture == NULL) {
        std::cout << "Failed to create texture, error: " << SDL_GetError() << std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 4;
    }

    bool quit = false;

    Uint32 * buffer = new Uint32[WINDOW_HEIGHT * WINDOW_WIDTH];

    memset(buffer, 0xFF, WINDOW_WIDTH * WINDOW_HEIGHT * sizeof(Uint32));
    SDL_UpdateTexture(texture, NULL, buffer, WINDOW_WIDTH * sizeof(Uint32));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

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

    delete [] buffer;
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}