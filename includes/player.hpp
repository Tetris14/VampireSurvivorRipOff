#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
public:
    // methods
    Player();
    Player(Player &&) = default;
    Player(const Player &) = default;
    Player &operator=(Player &&) = default;
    Player &operator=(const Player &) = default;
    void update();
    void draw(sf::RenderWindow &window);
    void setPlayerSprite(std::string texturePath, sf::RenderWindow &window);
    ~Player();
    // variables
    std::string name = "PlayerName";
    int health = 100;
    int level = 1;
    int experience = 0;
    float speed = 200.0f;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Keyboard::Key upKey = sf::Keyboard::Up;
    sf::Keyboard::Key downKey = sf::Keyboard::Down;
    sf::Keyboard::Key leftKey = sf::Keyboard::Left;
    sf::Keyboard::Key rightKey = sf::Keyboard::Right;
    float _xPos = 0;
    float _yPos = 0;
};

Player::Player()
{
}

Player::~Player()
{
}

void Player::setPlayerSprite(std::string texturePath, sf::RenderWindow &window)
{
    if (!texture.loadFromFile(texturePath))
    {
        std::cout << "Error loading texture" << std::endl;
    }
    sprite.setTexture(texture);
    sf::Vector2u windowSize = window.getSize();

    // Get sprite size
    sf::FloatRect spriteSize = sprite.getGlobalBounds();

    // Calculate position to center the sprite
    float xPosition = (windowSize.x - spriteSize.width) / 2.0f;
    float yPosition = (windowSize.y - spriteSize.height) / 2.0f;

    // Set sprite position
    _xPos = xPosition;
    _yPos = yPosition;
    sprite.setPosition(xPosition, yPosition);
}

void Player::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}

void Player::update()
{
    return;
}