#pragma once

#include <SFML/Graphics.hpp>

class Game;

class ScoreHandler
{

public:

	ScoreHandler() = delete;
	ScoreHandler(Game* gamePtr);

	void addScore(int addition);

	void reset();
	void update();
	void draw(sf::RenderWindow& window);


private:

	int m_score = 0;
	sf::RectangleShape m_box;
	sf::Text m_infoText;
	sf::Text m_scoreText;
	Game* m_gamePtr;


};