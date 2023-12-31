#include "player.hpp"
#include "map.hpp"
#include "bat.hpp"
#include <SFML/Window.hpp>
#include <cstdlib>

int main(int ac, char **av)
{
    if (ac != 3)
    {
        std::cout << "correct way = ./TheGame YourScreenWidth YourScreenHeight" << std::endl;
        return -1;
    }
    unsigned int screenWidth = std::strtoul(av[1], nullptr, 10);
    unsigned int screenHeight = std::strtoul(av[2], nullptr, 10);
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Vampire Survivor Ripoff");
    Player player;
    Map map;
    std::vector<Enemy *> enemies;
    sf::Clock clock;
    map._screenWidth = screenWidth;
    map._screenHeight = screenHeight;
    map._tileWidth = 16;
    map._tileHeight = 16;
    map.setTilesTextures({
                             "/Users/tristanus/PersonalProject/VampireSurvivorRipOff/assets/Sprite sheet/tile000.png",
                             "/Users/tristanus/PersonalProject/VampireSurvivorRipOff/assets/Sprite sheet/tile001.png",
                             "/Users/tristanus/PersonalProject/VampireSurvivorRipOff/assets/Sprite sheet/tile002.png",
                             "/Users/tristanus/PersonalProject/VampireSurvivorRipOff/assets/Sprite sheet/tile012.png",
                             "/Users/tristanus/PersonalProject/VampireSurvivorRipOff/assets/Sprite sheet/tile248.png",
                             "/Users/tristanus/PersonalProject/VampireSurvivorRipOff/assets/Sprite sheet/tile250.png",
                         },
                         screenWidth, screenHeight);
    player.setPlayerSprite("/Users/tristanus/PersonalProject/VampireSurvivorRipOff/assets/Float Mage/idle/player_idle0.png", window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Time deltaTime = clock.restart();
        sf::Vector2f movement(0, 0);

        if (sf::Keyboard::isKeyPressed(player.leftKey))
        {
            movement.x -= player.speed;
        }
        if (sf::Keyboard::isKeyPressed(player.rightKey))
        {
            movement.x += player.speed;
        }
        if (sf::Keyboard::isKeyPressed(player.upKey))
        {
            movement.y -= player.speed;
        }
        if (sf::Keyboard::isKeyPressed(player.downKey))
        {
            movement.y += player.speed;
        }

        player.sprite.move(movement * deltaTime.asSeconds());

        window.clear();

        map.draw(window);
        player.draw(window);

        window.display();
    }

    return 0;
}
