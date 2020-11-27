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

public:
    const static int WINDOW_WIDTH = 800;
    const static int WINDOW_HEIGHT = 600;

    Window();
    bool init();
    void screen_update();
    void set_pixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
    bool process_events();
    void close();

};

#endif // !WINDOW_HPP
