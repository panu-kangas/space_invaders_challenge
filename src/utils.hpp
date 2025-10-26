#pragma once

#include <SFML/Graphics.hpp>

bool checkSpriteCollision(const sf::Sprite& sprite1, const sf::Sprite& sprite2);
bool checkRectCollision(const sf::RectangleShape& sprite1, const sf::RectangleShape& sprite2);