#include "window.hpp"


Window::Window(int width, int height):
                  window_width(width),
                  window_height(height),
                  window(NULL),
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
        window_width, window_height, SDL_WINDOW_SHOWN);

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
        SDL_TEXTUREACCESS_STATIC, window_width, window_height);

    if (texture == NULL) {
        std::cout << "Failed to create texture, error: " << SDL_GetError() << std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }

   buffer = new Uint32[window_height * window_width];
   buffer_blur = new Uint32[window_height * window_width];


    memset(buffer, 0, window_width * window_height * sizeof(Uint32));
    memset(buffer_blur, 0, window_width * window_height * sizeof(Uint32));


    return true;
}

void Window::screen_update() {
    SDL_UpdateTexture(texture, NULL, buffer, window_width * sizeof(Uint32));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}

void Window::clear() {
    memset(buffer, 0, window_width * window_height * sizeof(Uint32));
    memset(buffer_blur, 0, window_width * window_height * sizeof(Uint32));

}

void Window::box_blur() {
    // Swap buffers, so information is in blur buffer and we are painting to original
    Uint32 *temp = buffer;
    buffer = buffer_blur;
    buffer_blur = temp;



    for(int y = 0; y < window_height; y++) {
        for(int x = 0; x < window_width; x++) {

            int red_total = 0;
            int green_total = 0;
            int blue_total = 0;
            int count = 0;

            // For each pixel, average surrounding pixels in source buffer.
            for(int row = -1; row <= 1; row++) {
                for(int col = -1; col <= 1; col++) {
                    int currentx = x + col;
                    int currenty = y + row;

                    // Skip pixels off edge of screen.
                    if(currentx >= 0 && currentx < window_width && currenty >= 0 && currenty < window_height) {
                        Uint32 color = buffer_blur[(currenty * window_width) + currentx];
                        Uint8 red = color >> 24;
                        Uint8 green = color >> 16;
                        Uint8 blue = color >> 8;

                        red_total += red;
                        green_total += green;
                        blue_total += blue;

                        // Add to count which will be used for average.
                        ++count;
                    }
                }
            }

            // Average color channels.
            Uint8 red = red_total/count;
            Uint8 green = green_total/count;
            Uint8 blue = blue_total/count;

            // Update the pixel in active buffer with the average.
            set_pixel(x, y, red, green, blue);
        }
    }
}

void Window::set_pixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {

    // Prevent pixel draw off edge of window
    if (x < 0 || x >= window_width || y < 0 || y >= window_height) {
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
    
    buffer[(y * window_width) + x] = color;
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

