#include "utils.hpp"

bool checkSpriteCollision(const sf::Sprite& sprite1, const sf::Sprite& sprite2) {
    sf::FloatRect rect1 = sprite1.getGlobalBounds();
    sf::FloatRect rect2 = sprite2.getGlobalBounds();

    sf::Vector2f pos1 = rect1.position;
    sf::Vector2f size1 = rect1.size;
    sf::Vector2f pos2 = rect2.position;
    sf::Vector2f size2 = rect2.size;

    return !(pos1.x + size1.x < pos2.x ||
             pos2.x + size2.x < pos1.x ||
             pos1.y + size1.y < pos2.y ||
             pos2.y + size2.y < pos1.y);
}


bool checkRectCollision(const sf::RectangleShape& sprite1, const sf::RectangleShape& sprite2) {
    sf::FloatRect rect1 = sprite1.getGlobalBounds();
    sf::FloatRect rect2 = sprite2.getGlobalBounds();

    sf::Vector2f pos1 = rect1.position;
    sf::Vector2f size1 = rect1.size;
    sf::Vector2f pos2 = rect2.position;
    sf::Vector2f size2 = rect2.size;

    return !(pos1.x + size1.x < pos2.x ||
             pos2.x + size2.x < pos1.x ||
             pos1.y + size1.y < pos2.y ||
             pos2.y + size2.y < pos1.y);
}