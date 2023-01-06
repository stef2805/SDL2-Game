#pragma once

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

class ColliderComponent;

class Game{
    
public:
    Game();
    ~Game();
    
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void update();
    void render();
    void clean();
    void handleEvents();
    bool running();
    
    enum groupLabels : std::size_t
    {
        groupMap,
        groupPlayers,
        groupProjectiles,
        groupColliders,
        groupTreasures
    };
    
    static void AddTile(int srcX, int srcY, int xpos, int ypos);
    static SDL_Event event;
    static SDL_Renderer* renderer;
    //static std::vector<ColliderComponent *> colliders;
    static bool isRunning;
    
    static SDL_Rect camera;
    
private:
    int count = 0;
    SDL_Window *window;
    
    
};
