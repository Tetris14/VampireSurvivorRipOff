#include "enemy.hpp"

class Bat : public Enemy
{
private:
    /* data */
public:
    Bat(int hp, std::string name, int dmg, float speed, std::string texturePath, int screenWidth, int screenHeight) {}
    ~Bat();
};
