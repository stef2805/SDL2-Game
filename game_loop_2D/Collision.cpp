#include "Collision.hpp"
#include "Ecs/ColliderComponent.hpp"

bool Collision::AABB(const SDL_Rect &recA, const SDL_Rect &recB)
{
    if(
       recA.x + recA.w >= recB.x + 50 &&
       recB.x + recB.w >= recA.x + 50 &&
       recA.y + recA.h >= recB.y + 30 &&
       recB.y + recB.h >= recA.y + 30
       )
        return true;
    return false;
}

bool Collision::AABB(const ColliderComponent& A, const ColliderComponent& B)
{
    if(AABB(A.collider, B.collider))
    {
        std::cout << A.tag << " hit " << B.tag << std::endl;
        return true;
    }
    return false;
}
