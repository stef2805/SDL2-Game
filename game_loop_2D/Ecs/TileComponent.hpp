#pragma once

#include "ECS.hpp"
#include "SDL2/SDL.h"
#include "Components.h"
#include "../game.hpp"

class TileComponent : public Component{
  
public:
    
    SDL_Texture* texture;
    SDL_Rect srcRect, destRect;
    Vector2D position;
    
    TileComponent() = default;
    ~TileComponent()
    {
        SDL_DestroyTexture(texture);
    }
    
    TileComponent(int srcX, int srcY, int xpos, int ypos, int tSize, int tscale, const char* path)
    {
        texture = TextureManager::LoadTexture(path);
        position.x = xpos;
        position.y = ypos;
        srcRect.x = srcX;
        srcRect.y = srcY;
        srcRect.w = srcRect.h = tSize;
        
        destRect.x = xpos;
        destRect.y = ypos;
        destRect.w = destRect.h = tSize * tscale;
    }
    
    void update() override
    {
        destRect.x = position.x - Game::camera.x;
        destRect.y = position.y - Game::camera.y;
    }
    void draw() override
    {
        TextureManager::draw(texture, srcRect, destRect, SDL_FLIP_NONE);
    }

    
};
