#pragma once

#include <SFML/Graphics.hpp>

bool checkSpriteCollision(const sf::Sprite& sprite1, const sf::Sprite& sprite2);
bool checkRectCollision(const sf::RectangleShape& sprite1, const sf::RectangleShape& sprite2);
void drawHeaderText(sf::Font& font, sf::RenderWindow& window, std::string str);
void drawCenteredText(sf::Font& font, sf::RenderWindow& window, std::string str, float offset = 0);
void drawLowText(sf::Font& font, sf::RenderWindow& window, std::string str);
float randomFloat(float min, float max);