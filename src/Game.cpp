#include "Game.hpp"
#include "Constants.hpp"
#include "Projectile.hpp"
#include "GameState.hpp"
#include "StartState.hpp"
#include "EndState.hpp"

#include <iostream>

Game::Game() :
	m_window(sf::VideoMode({ScreenWidth, ScreenHeight}), "Space Invaders - game by Panu Kangas")
{
	if (!m_mainFont.openFromFile("assets/mainFont.ttf"))
	{
		std::cout << "Font download failed!\nExiting program...\n";
		exit(1);
	}
	if (!m_alienTexture.loadFromFile("assets/alien.png"))
	{
		std::cout << "Alien download failed!\nExiting program...\n";
		exit(1);
	}
	if (!m_bgTexture.loadFromFile("assets/background.png"))
	{
		std::cout << "Alien download failed!\nExiting program...\n";
		exit(1);
	}
	if (!m_bgMusicBuf.loadFromFile("assets/bg_music.ogg")) 
	{
  		std::cout << "BG music download failed!\nExiting program...\n";
		exit(1);
	}
	if (!m_shootBuf.loadFromFile("assets/shoot.wav")) 
	{
  		std::cout << "Shoot SFX download failed!\nExiting program...\n";
		exit(1);
	}
	if (!m_alienBuf.loadFromFile("assets/enemy_hit.ogg")) 
	{
  		std::cout << "Enemy hit SFX download failed!\nExiting program...\n";
		exit(1);
	}

	m_curStatePtr = std::make_unique<StartState>(this);

	m_bgShape.setSize({ScreenWidth, ScreenHeight});
	m_bgShape.setTexture(&m_bgTexture);

	m_bgSoundPtr = std::make_unique<sf::Sound>(m_bgMusicBuf);
	m_shootSound = std::make_unique<sf::Sound>(m_shootBuf);
	m_alienSound = std::make_unique<sf::Sound>(m_alienBuf);

	m_shootSound->setVolume(50.f);

	m_bgSoundPtr->play();
}

void Game::run()
{
	while (m_window.isOpen()) {
		processEvents();
		update();
		render();
	}
}

void Game::processEvents()
{
    while (auto event = m_window.pollEvent()) {
        if (event->is<sf::Event::Closed>())
            m_window.close();
    }
}

void Game::update()
{
	float dt = clock.restart().asSeconds();
	m_curStatePtr->update(dt);

	switch (m_state)
	{
		case START:
		{
			if (m_curStatePtr->isReady())
			{
				m_state = GAME;
				m_curStatePtr = std::make_unique<GameState>(this);
			}
			break ;
		}

		case GAME:
		{
			if (m_curStatePtr->isReady())
			{
				int score = m_curStatePtr->getScore();
				m_state = END;
				m_curStatePtr = std::make_unique<EndState>(this, score);
			}
			break ;
		}

		case END:
		{
			if (m_curStatePtr->isReady())
			{
				m_state = GAME;
				m_curStatePtr = std::make_unique<GameState>(this);
			}
			break ;
		}

		default:
		{
			break ;
		}
	}
}



void Game::render()
{
	m_window.clear(sf::Color::Black);

	m_window.draw(m_bgShape);

	m_curStatePtr->render(m_window);

//	m_controlBox.draw(m_window);

	m_window.display();
}