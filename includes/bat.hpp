#include "enemy.hpp"

class Bat : public Enemy
{
public:
    Bat(int hp, std::string name, int dmg, float speed, std::string texturePath, int screenWidth, int screenHeight)
        : Enemy(hp, name, dmg, speed, texturePath, screenWidth, screenHeight) {}
};
