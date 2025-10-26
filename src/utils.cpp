#include "utils.hpp"
#include "Constants.hpp"
#include <random>


bool checkSpriteCollision(const sf::Sprite& sprite1, const sf::Sprite& sprite2) 
{
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


void drawHeaderText(sf::Font& font, sf::RenderWindow& window, std::string str)
{
	sf::Text text(font, str);

	text.setFillColor(sf::Color::Red);
	text.setCharacterSize(HeaderTextSize);

	float textX = ScreenWidth / 2 - text.getLocalBounds().size.x / 2;
	float textY = 40.f; 
	text.setPosition({textX, textY});

	window.draw(text);
}

void drawCenteredText(sf::Font& font, sf::RenderWindow& window, std::string str, float offset)
{
	sf::Text text(font, str);

	text.setFillColor(sf::Color::White);
	text.setCharacterSize(RegularTextSize);

	float textX = ScreenWidth / 2 - text.getLocalBounds().size.x / 2;
	float textY = ScreenHeight / 2 - text.getLocalBounds().size.y / 2 + offset;
	text.setPosition({textX, textY});

	window.draw(text);
}

void drawLowText(sf::Font& font, sf::RenderWindow& window, std::string str)
{
	sf::Text text(font, str);

	text.setFillColor(sf::Color::White);
	text.setCharacterSize(RegularTextSize - 10.f);

	float textX = ScreenWidth / 2 - text.getLocalBounds().size.x / 2;
	float textY = ScreenHeight * 0.8;
	text.setPosition({textX, textY});

	window.draw(text);
}

float randomFloat(float min, float max)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<float> distrib(min, max);
    return distrib(gen);
}