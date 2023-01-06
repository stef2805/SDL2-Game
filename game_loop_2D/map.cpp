#include "map.hpp"
//#include "textureManager.h"
#include "game.hpp"
#include <fstream>
#include "Ecs/ECS.hpp"
#include "Ecs/Components.h"
extern Manager manager;


Map::Map(const char* mfp, int ms, int ts)
{
    mapFilePath = mfp;
    mapScale = ms;
    tileSize = ts;
}

Map::~Map()
{
    
}

void Map::AddTile(int srcX, int srcY, int xpos, int ypos)
{
    auto& tile(manager.addEntity());
    tile.addComponent<TileComponent>(srcX, srcY, xpos, ypos, tileSize, mapScale, mapFilePath);
    tile.addGroup(Game::groupMap);
}

void Map::LoadMap(std::string path, int sizeX, int sizeY)
{
    char tile;
    std::fstream mapFile;
    mapFile.open(path);
    
    int srcX, srcY;
    
    for (int y = 0; y < sizeY; y++)
    {
        for (int x = 0; x < sizeX; x++)
        {
            mapFile.get(tile);
            srcY = atoi(&tile) * tileSize;
            mapFile.get(tile);
            srcX = atoi(&tile) * tileSize;
            
            AddTile(srcX, srcY, x * (tileSize * mapScale), y * (tileSize * mapScale));
            mapFile.ignore(); // ","
        }
    }
    
    mapFile.ignore();
    char c;
    
    for (int y = 0; y < sizeY; y++)
    {
        for (int x = 0; x < sizeX; x++)
        {
            mapFile.get(c);
            if(c=='1')
            {
                auto&tcol(manager.addEntity());
                tcol.addComponent<ColliderComponent>("terrain", x*(tileSize*mapScale), y*(tileSize*mapScale), tileSize*mapScale);
                tcol.addGroup(Game::groupColliders);
            }
            mapFile.ignore();
        }
    }
    
    mapFile.close();
    
}

