#include "Background.hpp"

Background::Background()
{
	if (!m_texture.loadFromFile("Sprites/PongBackground.png"))
	{
		std::cerr << "Cant load background" << std::endl;
	}
	else
	{
		m_sprite.setTexture(m_texture);
	}
}

Background::~Background()
{

}

void Background::draw(sf::RenderWindow& target)
{
	target.draw(m_sprite);
}

