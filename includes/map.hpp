#include <random>

int getTileCountFromScreen(int width, int height, int tileWidth, int tileHeight)
{
    return ((width / tileWidth) * (height / tileHeight));
}

class Map
{
public:
    Map();
    ~Map();
    void draw(sf::RenderWindow &window);
    void setTilesTextures(std::vector<std::string> _texturesPaths, unsigned int screenWidth, unsigned int screenHeight);
    std::vector<sf::Texture> _textures;
    std::vector<sf::Sprite> _sprites;
    unsigned int _screenWidth;
    unsigned int _screenHeight;
    unsigned int _tileWidth;
    unsigned int _tileHeight;
};

Map::Map()
{
}

Map::~Map()
{
}

void Map::setTilesTextures(std::vector<std::string> _texturesPaths, unsigned int screenWidth, unsigned int screenHeight)
{
    sf::Texture texture;
    sf::Sprite sprite;
    std::random_device rd;
    std::mt19937 gen(rd());
    sf::Vector2i tilePos;
    tilePos.x = 0;
    tilePos.y = 0;
    int maxTileX = screenWidth / _tileWidth;
    int maxTileY = screenHeight / _tileHeight;
    for (std::string txtPath : _texturesPaths)
    {
        if (!texture.loadFromFile(txtPath))
        {
            std::cout << "Error loading texture : " << txtPath << std::endl;
        }
        _textures.push_back(texture);
    }
    std::uniform_int_distribution<> distr(0, (_textures.size() - 1));
    for (int y = 0; y < maxTileY; y += 1)
    {
        for (int x = 0; x < maxTileX; x += 1)
        {
            sprite.setTexture(_textures.at(distr(gen)));
            sprite.setPosition(tilePos.x, tilePos.y);
            tilePos.x += 16;
            _sprites.push_back(sprite);
        }
        tilePos.x = 0;
        tilePos.y += 16;
        _sprites.push_back(sprite);
    }
}

void Map::draw(sf::RenderWindow &window)
{
    for (sf::Sprite sprt : _sprites)
    {
        window.draw(sprt);
    }
}