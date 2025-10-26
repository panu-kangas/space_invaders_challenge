#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>

#include "Player.hpp"
#include "Enemy.hpp"
#include "ScoreHandler.hpp"
#include "IGameState.hpp"
#include "ControlBox.hpp"

enum eGameState
{
	START,
	GAME,
	END
};

class Game {

public:

    Game();

    void run();
    void processEvents();
    void update();
    void render();

	sf::Font& getMainFont() { return m_mainFont; };
	sf::RenderWindow& getGameWindow() { return m_window; };
	sf::Texture& getEnemyText() { return m_alienTexture; };

	void playShootSound() { m_shootSound->play(); };
	void playAlienSound() { m_alienSound->play(); };

private:

    sf::RenderWindow m_window;
    sf::Clock clock;
	sf::Font m_mainFont;

    std::unique_ptr<IGameState> m_curStatePtr;
	eGameState m_state{START};
	
//	ControlBox m_controlBox;

	sf::Texture m_alienTexture;
	sf::Texture m_bgTexture;
	sf::RectangleShape m_bgShape;

	sf::SoundBuffer m_bgMusicBuf;
	sf::SoundBuffer m_shootBuf;
	sf::SoundBuffer m_alienBuf;

	std::unique_ptr<sf::Sound> m_bgSoundPtr;
	std::unique_ptr<sf::Sound> m_shootSound;
	std::unique_ptr<sf::Sound> m_alienSound;


};