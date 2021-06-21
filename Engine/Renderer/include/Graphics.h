#ifndef __ENGINE_RENDERER_GRAPHICS_H__
#define __ENGINE_RENDERER_GRAPHICS_H__

#include <iostream>
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

namespace Hoopoe 
{

class Graphics 
{
public:
    Graphics();

    SDL_Window *get_window();
    SDL_Renderer *get_renderer();
    int get_TILE();
    int get_SCREEN_WIDTH();
    int get_SCREEN_HEIGHT();

    void renderTexture(SDL_Texture *texture, int x, int y, int w, int h);
    void renderTexture(SDL_Texture *texture, int x, int y);
    SDL_Texture *loadTexture(const string file);

    void renderBackground(SDL_Texture *texture);

    ~Graphics();
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    int TILE;
    int SCREEN_WIDTH;
    int SCREEN_HEIGHT;
};

}

#endif
