#include "GameObject.hpp"
#include "textureManager.h"


GameObject::GameObject(const char* textureSheet, int x, int y)
{
    objTexture = TextureManager::LoadTexture(textureSheet);
    
    xpos = x;
    ypos = y;
}
 
GameObject::~GameObject()
{
    
}

void GameObject::Update()
{
    xpos++;
    ypos++;
    
    srcRect.w = 389;
    srcRect.h = 642;
    srcRect.x = 0;
    srcRect.y = 0;
    
    destRect.h  = srcRect.h * 0.1;
    destRect.w = srcRect.w * 0.1;
    destRect.x = xpos;
    destRect.y = ypos;
    
    
}
void GameObject::Render()
{
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}
