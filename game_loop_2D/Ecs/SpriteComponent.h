#pragma once
#include "Components.h"
#include "SDL2/SDL.h"
#include "../textureManager.h"
#include "Animation.hpp"
#include <map>
#include "../game.hpp"


class SpriteComponent : public Component{
    
public:
    
    int animIndex = 0;
    SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;
    
    std::map<const char*, Animation> animations;
    
    SpriteComponent() = default;
    
    SpriteComponent(const char* path)
    {
        setTex(path);
    }
   
    SpriteComponent(const char* path, bool isAnimated)
    {
        animated = isAnimated;
        
        Animation idle = Animation(0, 3, 100);
        Animation walk = Animation(1, 8, 100);
        
        Animation coin = Animation(0, 6, 150);
        
        animations.emplace("Idle", idle);
        animations.emplace("Walk", walk);
        //animations.emplace("Boom", boom);
        animations.emplace("Coin", coin);
        
        Play("idle");
        setTex(path);
    }
    ~SpriteComponent()
    {
        SDL_DestroyTexture(texture);
    }
    
    void setTex(const char* path)
    {
        texture = TextureManager::LoadTexture(path);
    }
    
    void init() override
    {
        transform = &entity->getComponent<TransformComponent>();
        
        srcRect.x = srcRect.y = 0;
        srcRect.w = transform->width;
        srcRect.h = transform->height;
        
    }
    
    void update() override
    {
        if(animated)
        {
            srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
        }
        
        srcRect.y = animIndex * transform->height;
        
        destRect.x = static_cast<int>(transform->position.x - Game::camera.x);
        destRect.y = static_cast<int>(transform->position.y - Game::camera.y);
        destRect.w = transform->width * transform->scale;
        destRect.h = transform->height * transform->scale;
    }
    
    void draw() override
    {
        TextureManager::draw(texture, srcRect, destRect, spriteFlip);
    }
    
    void Play(const char* animName)
    {
        frames = animations[animName].frames;
        animIndex = animations[animName].index;
        speed = animations[animName].speed;
    }
    
    bool animated = false;
    
private:
    TransformComponent *transform;
    SDL_Texture *texture;
    SDL_Rect srcRect, destRect;
    
    
    int frames = 0;
    int speed = 100;
};


