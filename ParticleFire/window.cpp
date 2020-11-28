#include "window.hpp"


Window::Window(): window(NULL), renderer(NULL), texture(NULL), buffer(NULL) {}

bool Window::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL Init Failed" << std::endl;
        return false;
    }
    
    window = SDL_CreateWindow("Particle Fire Dance",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == NULL) {
        std::cout << "Failed to create window, error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

    if (renderer == NULL) {
        std::cout << "Failed to create renderer, error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }

    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
        SDL_TEXTUREACCESS_STATIC, WINDOW_WIDTH, WINDOW_HEIGHT);

    if (texture == NULL) {
        std::cout << "Failed to create texture, error: " << SDL_GetError() << std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }

   buffer = new Uint32[WINDOW_HEIGHT * WINDOW_WIDTH];

    memset(buffer, 0, WINDOW_WIDTH * WINDOW_HEIGHT * sizeof(Uint32));

    return true;
}

void Window::screen_update() {
    SDL_UpdateTexture(texture, NULL, buffer, WINDOW_WIDTH * sizeof(Uint32));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}

void Window::clear() {
    memset(buffer, 0, WINDOW_WIDTH * WINDOW_HEIGHT * sizeof(Uint32));
}

void Window::set_pixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {

    // Prevent pixel draw off edge of window
    if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT) {
        std::cout << "Pixel out of range: x: " << x << " y: " << y << std::endl;
        return;
    }

    Uint32 color = 0;

    color += red;
    color <<= 8;
    color += green;
    color <<= 8;
    color += blue;
    color <<= 8;
    color += 0xFF;
    
    buffer[(y * WINDOW_WIDTH) + x] = color;
}

bool Window::process_events() {
    SDL_Event event;

    while(SDL_PollEvent(&event)) {
        if(event.type == SDL_QUIT) {
            return false;
        }
    }
    return true;
}

void Window::close() {

    delete [] buffer;
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
}

