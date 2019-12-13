#include "Text.hpp"

Text::Text(std::string fontFile, sf::Vector2f pos, int scale)
{
	if (!m_font.loadFromFile(fontFile))
	{
		throw ("Can't load " + fontFile);
	}
	m_text.setCharacterSize(scale);
	m_text.setFont(m_font);
	m_text.setPosition(pos);
}

Text::~Text()
{
}

void Text::draw(sf::RenderWindow & target)
{
	target.draw(m_text);
}

void Text::update(std::string text)
{
	m_text.setString(text);
}
