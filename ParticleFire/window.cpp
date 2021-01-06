#include "window.hpp"


Window::Window(): window(NULL),
                  renderer(NULL),
                  texture(NULL),
                  buffer(NULL),
                  buffer_blur(NULL)
                  {}

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
   buffer_blur = new Uint32[WINDOW_HEIGHT * WINDOW_WIDTH];


    memset(buffer, 0, WINDOW_WIDTH * WINDOW_HEIGHT * sizeof(Uint32));
    memset(buffer_blur, 0, WINDOW_WIDTH * WINDOW_HEIGHT * sizeof(Uint32));


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
    memset(buffer_blur, 0, WINDOW_WIDTH * WINDOW_HEIGHT * sizeof(Uint32));

}

void Window::box_blur() {
    // Swap buffers, so information is in blur buffer and we are painting to original
    Uint32 *temp = buffer;
    buffer = buffer_blur;
    buffer_blur = temp;



    for(int y = 0; y < WINDOW_HEIGHT; y++) {
        for(int x = 0; x < WINDOW_WIDTH; x++) {

            int red_total = 0;
            int green_total = 0;
            int blue_total = 0;
            int count = 0;

            // For each pixel, average surrounding pixels.
            for(int row = -1; row <= 1; row++) {
                for(int col = -1; col <= 1; col++) {
                    int currentx = x + col;
                    int currenty = y + row;

                    if(currentx >= 0 && currentx < WINDOW_WIDTH && currenty >= 0 && currenty < WINDOW_HEIGHT) {
                        Uint32 color = buffer_blur[(currenty * WINDOW_WIDTH) + currentx];
                        Uint8 red = color >> 24;
                        Uint8 green = color >> 16;
                        Uint8 blue = color >> 8;

                        red_total += red;
                        green_total += green;
                        blue_total += blue;

                        ++count;
                    }
                }
            }

            Uint8 red = red_total/count;
            Uint8 green = green_total/count;
            Uint8 blue = blue_total/count;

            set_pixel(x, y, red, green, blue);
        }
    }
}

void Window::set_pixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {

    // Prevent pixel draw off edge of window
    if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT) {
        // std::cout << "Pixel out of range: x: " << x << " y: " << y << std::endl;
        x = 0;
        y = 0;
        // return;
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
    delete [] buffer_blur;
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
}

