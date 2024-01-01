#include <SFML/Graphics.hpp>
#include <utility>
#include <random>

class Enemy
{
public:
    Enemy(int hp, std::string name, int dmg, float speed, std::string texturePath, int screenWidth, int screenHeight);
    ~Enemy();
    void animSprite(int frameWidth, int frameHeight, int frameCount, float frameDuration);
    void move(sf::Vector2f playerPos);
    void draw(sf::RenderWindow &Window);
    int _hp;
    std::string _name;
    int _dmg;
    float _speed;
    sf::Texture _texture;
    sf::Sprite _sprite;
    sf::Clock _animClock;
    sf::Clock _moveClock;

private:
    int _currentFrame = 0;
};

Enemy::Enemy(int hp, std::string name, int dmg, float speed, std::string texturePath, int screenWidth, int screenHeight)
{
    _hp = hp;
    _name = name;
    _speed = speed;
    _dmg = dmg;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> xRdm(0, screenWidth);
    std::uniform_int_distribution<> yRdm(0, screenHeight);
    std::uniform_int_distribution<> spawnSpot(0, 3);
    int sp = spawnSpot(gen);
    sf::Vector2i pos;
    if (!_texture.loadFromFile(texturePath))
    {
        std::cout << "error texture loading : " << texturePath << std::endl;
    }
    _sprite.setTexture(_texture);
    if (sp == 0)
    {
        pos.x = xRdm(gen);
        pos.y = 0;
    }
    else if (sp == 1)
    {
        pos.x = 0;
        pos.y = yRdm(gen);
    }
    else if (sp == 2)
    {
        pos.x = screenWidth;
        pos.y = yRdm(gen);
    }
    else if (sp == 3)
    {
        pos.x = xRdm(gen);
        pos.y = screenHeight;
    }
    _sprite.setPosition(pos.x, pos.y);
}

void Enemy::move(sf::Vector2f playerPos)
{
    sf::Time deltaTime = _moveClock.restart();

    sf::Vector2f direction(playerPos.x - _sprite.getPosition().x, playerPos.y - _sprite.getPosition().y);

    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    if (length != 0)
    {
        direction.x /= length;
        direction.y /= length;
    }

    sf::Vector2f movement = direction * _speed * deltaTime.asSeconds();

    _sprite.move(movement);
}

void Enemy::animSprite(int frameWidth, int frameHeight, int frameCount, float frameDuration)
{
    if (_animClock.getElapsedTime().asSeconds() > frameDuration)
    {
        _currentFrame = (_currentFrame + 1) % frameCount;
        _sprite.setTextureRect(sf::IntRect(frameWidth * _currentFrame, 0, frameWidth, frameHeight));
        _animClock.restart();
    }
}

void Enemy::draw(sf::RenderWindow &window)
{
    window.draw(_sprite);
}