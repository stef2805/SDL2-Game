#include "textureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* fileName )
{
    SDL_Surface* tmpSurface = IMG_Load(fileName);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer , tmpSurface);
    SDL_FreeSurface(tmpSurface);
    
    return tex;
}


void TextureManager::draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest, SDL_RendererFlip flip)
{
    SDL_RenderCopyEx(Game::renderer, tex, &src, &dest, NULL, NULL, flip);
}