#include "game.hpp"



Game *game = nullptr;

int main(void)
{
    
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    
    Uint32 frameStart;
    int frameTime;
    
    game = new Game();
    game->init("primul joc", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
    
    
    while(game->running())
    {
        frameStart = SDL_GetTicks();
        frameTime = SDL_GetTicks() - frameStart;
        
        game->handleEvents();
        game->update();
        game->render();
        
        if(frameDelay>frameTime)
        {
            SDL_Delay(frameDelay-frameTime);
        }
    }
    
    game->clean();
    
    
    
    return 0;
}
