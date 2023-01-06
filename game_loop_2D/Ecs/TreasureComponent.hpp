#pragma once

#include "ECS.hpp"
#include "Components.h"
#include "../Vector2D.hpp"

class TreasureComponent : public Component
{
public:
    TreasureComponent(int x, int y)
    {
        posX = x;
        posY = y;
    }
    ~TreasureComponent()
    {
        
    }
    void init() override
    {
        sprite = &entity->getComponent<SpriteComponent>();
    }
    void update() override
    {
        sprite->Play("Coin");
    }
    SpriteComponent *sprite;
private:
    
    int posX;
    int posY;
    
};
