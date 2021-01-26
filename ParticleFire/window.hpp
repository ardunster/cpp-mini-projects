#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <iostream>
#include <SDL.h>

class Window {
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    Uint32 *buffer;
    Uint32 *buffer_blur;

public:
    const int window_width;
    const int window_height;

    Window(int width, int height);
    bool init();
    void screen_update();
    void clear();
    void box_blur();
    void set_pixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
    bool process_events();
    void close();

};

#endif // !WINDOW_HPP
