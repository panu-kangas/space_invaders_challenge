#include "Player.hpp"

Player::Player(float x, float y)
{
    shape.setSize({50.0f, 20.0f});
    shape.setFillColor(sf::Color::Green);
    shape.setPosition({x, y});
}

void Player::update(float dt, sf::RenderWindow& window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        shape.move({-speed * dt, 0});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        shape.move({speed * dt, 0});
    }

    if (shape.getPosition().x < 0)
        shape.setPosition({0, shape.getPosition().y});
    if (shape.getPosition().x + shape.getSize().x > window.getSize().x)
        shape.setPosition({window.getSize().x - shape.getSize().x, shape.getPosition().y});

    timeSinceLastShot += dt;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && timeSinceLastShot >= shootCooldown) {
        shoot();
        timeSinceLastShot = 0.0f;
    }

    for (auto& p : projectiles)
        p.update(dt);

	int i = 0;
	while (i < projectiles.size())
	{
		if (projectiles[i].isOffScreen(window))
		{
			std::swap(projectiles[i], projectiles.back());
            projectiles.pop_back();
            continue;
		}
		i++;
	}

}

void Player::draw(sf::RenderWindow& window)
{
    window.draw(shape);
    for (auto& p : projectiles)
        p.draw(window);
}

void Player::shoot()
{
    sf::Vector2f pos = shape.getPosition();
    pos.x += shape.getSize().x / 2.0f - 2.5f;
    pos.y -= 10.0f;
    projectiles.emplace_back(pos);
}
