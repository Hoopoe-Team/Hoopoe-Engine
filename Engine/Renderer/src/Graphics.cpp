#include "../include/Graphics.h"

namespace Hoopoe 
{

Graphics::Graphics() 
{
    SCREEN_WIDTH = 640;
    SCREEN_HEIGHT = 480;
    TILE = 40;
    window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

Graphics::~Graphics() 
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}

SDL_Window *Graphics::get_window() { return window; }
SDL_Renderer *Graphics::get_renderer() { return renderer; }
int Graphics::get_TILE() { return TILE; }
int Graphics::get_SCREEN_WIDTH() { return SCREEN_WIDTH; }
int Graphics::get_SCREEN_HEIGHT() { return SCREEN_HEIGHT; }

void Graphics::renderTexture(SDL_Texture *texture, int x, int y, int w, int h) 
{
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    dst.w = w;
    dst.h = h;
    SDL_RenderCopy(renderer, texture, NULL, &dst);
}

void Graphics::renderTexture(SDL_Texture *texture, int x, int y) 
{
    int w, h;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    renderTexture(texture, x, y, w, h);
}

SDL_Texture *Graphics::loadTexture(const string file) 
{
    SDL_Texture *texture = IMG_LoadTexture(renderer, file.c_str());
    if(texture == nullptr)
        cout << SDL_GetError() << " - loadTexture()" << endl;

    return texture;
}

void Graphics::renderBackground(SDL_Texture *texture) 
{
    for(int i = 0; i < SCREEN_HEIGHT / TILE; ++i) {
        for(int j = 0; j < SCREEN_WIDTH / TILE; ++j) {
            renderTexture(texture, j*TILE, i*TILE, TILE, TILE);
        }
    }
}
    
}