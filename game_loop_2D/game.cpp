#include "game.hpp"
#include "textureManager.h"
//#include "GameObject.hpp"
#include "map.hpp"
#include "Ecs/Components.h"
#include "Vector2D.hpp"
#include "Collision.hpp"
#include "Animation.hpp"
#include <map>

SDL_Renderer* Game::renderer = nullptr;

Manager manager;
SDL_Event Game::event;

auto& Player(manager.addEntity());



auto& Projectile(manager.addEntity());
auto& Projectile2(manager.addEntity());
auto& Projectile3(manager.addEntity());
auto& Projectile4(manager.addEntity());
auto& Projectile5(manager.addEntity());
auto& Projectile6(manager.addEntity());
auto& Projectile7(manager.addEntity());
auto& Projectile8(manager.addEntity());
auto& Projectile9(manager.addEntity());
auto& Projectile10(manager.addEntity());
auto& Projectile11(manager.addEntity());
auto& Projectile12(manager.addEntity());

auto& Treasure(manager.addEntity());
auto& Treasure1(manager.addEntity());
auto& Treasure2(manager.addEntity());
auto& Treasure3(manager.addEntity());
auto& Treasure4(manager.addEntity());

//const char* mapFile= "imagini/terrain_ss.png";

bool Game::isRunning = false;

SDL_Rect Game::camera = {0, 0 , 1600, 1280};

int noOfLives = 2;          //cate bombe poti atinge fara sa mori
int noOfTreasures = 0;
int noOfReqTreasures = 5;   //are nevoie de 5 comori pt a castiga




//std::vector<ColliderComponent*> Game::colliders;

Game::Game()
{
    
}
Game::~Game()
{
    
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        cout << "Subsystems initialised\n";
        
        window = SDL_CreateWindow(title,xpos, ypos, width, height, flags);
        if(window)
        {
            cout << "Window created!\n";
        }
        
        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            cout << "Rendere created!\n";
        }
        isRunning = true;
    }
    else
    {
        isRunning = false;
    }
    
    Map* map = new Map("imagini/terrain_ss.png", 3, 32);
    
    //ecs
    
    map->LoadMap("imagini/map.map.txt", 25, 20);
    
    Player.addComponent<TransformComponent>(200, 1600, 32 , 32, 3);
    Player.addComponent<SpriteComponent>("imagini/player_anims.png", true);
    Player.addComponent<KeyboardController>();
    Player.addComponent<ColliderComponent>("player");
    Player.addGroup(groupPlayers);
    
    
    Projectile.addComponent<TransformComponent>(900,700,32,32,2);
    Projectile.addComponent<SpriteComponent>("imagini/projectile.png", false);
    Projectile.addComponent<ProjectileComponent>(40, 3, Vector2D(1,0));
    Projectile.addComponent<ColliderComponent>("projectile");
    Projectile.addGroup(groupProjectiles);
    //Projectile.getComponent<TransformComponent>().velocity.x = 1;
    
    Projectile2.addComponent<TransformComponent>(700,1050, 32, 32, 2);
    Projectile2.addComponent<SpriteComponent>("imagini/projectile.png", false);
    Projectile2.addComponent<ProjectileComponent>(160, 10, Vector2D(1,0));
    Projectile2.addComponent<ColliderComponent>("projectile");
    Projectile2.addGroup(groupProjectiles);
    
    Projectile3.addComponent<TransformComponent>(50,1200, 32, 32, 2);
    Projectile3.addComponent<SpriteComponent>("imagini/projectile.png", false);
    Projectile3.addComponent<ProjectileComponent>(100, 2, Vector2D(1,0));
    Projectile3.addComponent<ColliderComponent>("projectile");
    Projectile3.addGroup(groupProjectiles);
    
    Projectile4.addComponent<TransformComponent>(50,900, 32, 32, 2);
    Projectile4.addComponent<SpriteComponent>("imagini/projectile.png", false);
    Projectile4.addComponent<ProjectileComponent>(100, 2, Vector2D(1,0));
    Projectile4.addComponent<ColliderComponent>("projectile");
    Projectile4.addGroup(groupProjectiles);
    
    Projectile5.addComponent<TransformComponent>(650,500,32,32,2);
    Projectile5.addComponent<SpriteComponent>("imagini/projectile.png", false);
    Projectile5.addComponent<ProjectileComponent>(100, 3, Vector2D(0,1));
    Projectile5.addComponent<ColliderComponent>("projectile");
    Projectile5.addGroup(groupProjectiles);
    
    Projectile6.addComponent<TransformComponent>(900,700,32,32,2);
    Projectile6.addComponent<SpriteComponent>("imagini/projectile.png", false);
    Projectile6.addComponent<ProjectileComponent>(150, 3, Vector2D(0,1));
    Projectile6.addComponent<ColliderComponent>("projectile");
    Projectile6.addGroup(groupProjectiles);
    
    Projectile7.addComponent<TransformComponent>(1600,700,32,32,2);
    Projectile7.addComponent<SpriteComponent>("imagini/projectile.png", false);
    Projectile7.addComponent<ProjectileComponent>(70, 3, Vector2D(0,1));
    Projectile7.addComponent<ColliderComponent>("projectile");
    Projectile7.addGroup(groupProjectiles);
    
    Projectile8.addComponent<TransformComponent>(1600,100,32,32,2);
    Projectile8.addComponent<SpriteComponent>("imagini/projectile.png", false);
    Projectile8.addComponent<ProjectileComponent>(70, 3, Vector2D(0,1));
    Projectile8.addComponent<ColliderComponent>("projectile");
    Projectile8.addGroup(groupProjectiles);
    
    Projectile9.addComponent<TransformComponent>(500,500,32,32,2);
    Projectile9.addComponent<SpriteComponent>("imagini/projectile.png", false);
    Projectile9.addComponent<ProjectileComponent>(70, 5, Vector2D(0,1));
    Projectile9.addComponent<ColliderComponent>("projectile");
    Projectile9.addGroup(groupProjectiles);
    
    Projectile10.addComponent<TransformComponent>(1100,400,32,32,2);
    Projectile10.addComponent<SpriteComponent>("imagini/projectile.png", false);
    Projectile10.addComponent<ProjectileComponent>(70, 3, Vector2D(1,0));
    Projectile10.addComponent<ColliderComponent>("projectile");
    Projectile10.addGroup(groupProjectiles);
    
    Projectile11.addComponent<TransformComponent>(1600,1000,32,32,2);
    Projectile11.addComponent<SpriteComponent>("imagini/projectile.png", false);
    Projectile11.addComponent<ProjectileComponent>(80, 3, Vector2D(0,1));
    Projectile11.addComponent<ColliderComponent>("projectile");
    Projectile11.addGroup(groupProjectiles);
    
    Projectile12.addComponent<TransformComponent>(1975,850,32,32,2);
    Projectile12.addComponent<SpriteComponent>("imagini/projectile.png", false);
    Projectile12.addComponent<ProjectileComponent>(70, 3, Vector2D(1,0));
    Projectile12.addComponent<ColliderComponent>("projectile");
    Projectile12.addGroup(groupProjectiles);
    
    
    
    
    
    
    Treasure.addComponent<TransformComponent>(270, 1600, 32 , 32, 1);
    Treasure.addComponent<SpriteComponent>("imagini/coinAnimFull.png", true);
    Treasure.addComponent<TreasureComponent>(200, 1600);
    Treasure.addComponent<ColliderComponent>("treasure");
    Treasure.addGroup(groupTreasures);
    
    Treasure1.addComponent<TransformComponent>(1700, 800, 32 , 32, 1);
    Treasure1.addComponent<SpriteComponent>("imagini/coinAnimFull.png", true);
    Treasure1.addComponent<TreasureComponent>(200, 1600);
    Treasure1.addComponent<ColliderComponent>("treasure");
    Treasure1.addGroup(groupTreasures);
    
    Treasure2.addComponent<TransformComponent>(2125, 1175, 32 , 32, 1);
    Treasure2.addComponent<SpriteComponent>("imagini/coinAnimFull.png", true);
    Treasure2.addComponent<TreasureComponent>(200, 1600);
    Treasure2.addComponent<ColliderComponent>("treasure");
    Treasure2.addGroup(groupTreasures);
    
    Treasure3.addComponent<TransformComponent>(2100, 750, 32 , 32, 1);
    Treasure3.addComponent<SpriteComponent>("imagini/coinAnimFull.png", true);
    Treasure3.addComponent<TreasureComponent>(200, 1600);
    Treasure3.addComponent<ColliderComponent>("treasure");
    Treasure3.addGroup(groupTreasures);
    
    Treasure4.addComponent<TransformComponent>(2050, 300, 32 , 32, 1);
    Treasure4.addComponent<SpriteComponent>("imagini/coinAnimFull.png", true);
    Treasure4.addComponent<TreasureComponent>(200, 1600);
    Treasure4.addComponent<ColliderComponent>("treasure");
    Treasure4.addGroup(groupTreasures);
    
    
}


auto& tiles(manager.getGroup(Game::groupMap));
auto& players(manager.getGroup(Game::groupPlayers));
auto& colliders(manager.getGroup(Game::groupColliders));
auto& projectiles(manager.getGroup(Game::groupProjectiles));
auto& treasures(manager.getGroup(Game::groupTreasures));


void Game::handleEvents()
{
    
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning=false;
            break;
            
        default:
            break;
    }
}

void Game::update()
{
    SDL_Rect playerCol = Player.getComponent<ColliderComponent>().collider;
    Vector2D playerPos = Player.getComponent<TransformComponent>().position;
    
    manager.refresh();
    manager.update();
    
    for(auto& c: colliders)
    {
        SDL_Rect cCol = c->getComponent<ColliderComponent>().collider;
        if(Collision::AABB(cCol, playerCol))
        {
            Player.getComponent<TransformComponent>().position = playerPos;
        }
        
    }
    
    for(auto& p: projectiles)
    {
        if(Collision::AABB(Player.getComponent<ColliderComponent>().collider, p->getComponent<ColliderComponent>().collider))
        {
            std::cout<<"Projectile hit player"<<std::endl;
            
            noOfLives--;
            
            p->getComponent<SpriteComponent>().setTex("imagini/boom.png");
            p->draw();
            
            render();
            
            SDL_Delay(1000);
            
            
            if(noOfLives == 0)
            {
                isRunning = 0;
            }
            
            p->destroy();
            
        }
    }
    
    for(auto& t: treasures)
    {
        if(Collision::AABB(Player.getComponent<ColliderComponent>().collider, t->getComponent<ColliderComponent>().collider))
        {
            std::cout<<"Treasure touched"<<std::endl;
            
            
            noOfTreasures++ ;
            
            t->destroy();
            
            if(noOfTreasures == noOfReqTreasures)
            {
                static int ticks1 = SDL_GetTicks();
                int ticks2 = SDL_GetTicks();
                while(ticks2 <= ticks1 + 3000)
                {
                    ticks2 = SDL_GetTicks();
                }
                
                isRunning = 0;
            }
            
        }
    }
    
    
    camera.x = static_cast<int>(Player.getComponent<TransformComponent>().position.x - 400);
    camera.y = static_cast<int>(Player.getComponent<TransformComponent>().position.y - 320);
    
    if (camera.x<0)
    {
        camera.x = 0;
    }
    
    if(camera.y < 0)
    {
        camera.y = 0;
    }
    
    if (camera.x > camera.w)
    {
        camera.x = camera.w;
    }
    
    if(camera.y > camera.h)
    {
        camera.y = camera.h;
    }
}



void Game::render()
{
    SDL_RenderClear(renderer);
    
    for(auto& t: tiles)
    {
        t->draw();
    }
    
    //for(auto& c : colliders)
    //{
    //    c->draw();                //deseneaza cu galben colliders
    //}
    
    for(auto& t: treasures)
    {
        t->draw();
    }
    
    for(auto& p: players)
    {
        p->draw();
    }
    
    for(auto& p: projectiles)
    {
        p->draw();
    }
    
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout<<"Game cleaned!\n";
}



bool Game::running()
{
    return isRunning;
}
