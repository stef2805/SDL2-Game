#pragma once

#include "ECS.hpp"
#include "Components.h"
#include "../Vector2D.hpp"

class ProjectileComponent : public Component
{
public:
    ProjectileComponent(int rng, int sp, Vector2D vel) : range(rng), speed(sp), velocity(vel)
    {}
    ~ProjectileComponent()
    {}
    
    void init() override
    {
        transform = &entity->getComponent<TransformComponent>();
        transform->velocity = velocity;
        transform->speed = speed;
    }
    
    void update() override
    {
        distanceX += velocity.x;
        distanceY += velocity.y;
        
        if (distanceX > range)
        {
            //std::cout << "Out of Range" << std::endl;
           // entity->destroy();
        }
        else if (transform->position.x > Game::camera.x + Game::camera.w ||
                 transform->position.x < Game::camera.x ||
                 transform->position.y > Game::camera.y + Game::camera.h ||
                 transform->position.y < Game::camera.y)
        {
            //std::cout << "Out of bounds!" << std::endl;
            //entity->destroy();
        }
        
        
        if(distanceX > range)
        {
            transform->velocity.x = -1;
            velocity.x = -1;
            SpriteComponent *sprite;
            sprite = &entity->getComponent<SpriteComponent>();
            sprite->spriteFlip = SDL_FLIP_HORIZONTAL;
        }
        if(distanceX < 0)
        {
            transform->velocity.x = 1;
            velocity.x = 1;
            SpriteComponent *sprite;
            sprite = &entity->getComponent<SpriteComponent>();
            sprite->spriteFlip = SDL_FLIP_NONE;
        }
        
        if(distanceY > range)
        {
            transform->velocity.y = -1;
            velocity.y = -1;
        }
        if(distanceY < 0)
        {
            transform->velocity.y = 1;
            velocity.y = 1;
        }
       
    }
    
    int distanceX, distanceY;
    int range = 0;
    Vector2D velocity;
    
private:
    
    TransformComponent* transform;
    int speed = 0;
    
};
