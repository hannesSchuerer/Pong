#pragma once
#include <SFML/Graphics.hpp>

class Text 
{
public:
	Text(std::string fontFile, sf::Vector2f pos, int scale);
	~Text();

	void draw(sf::RenderWindow& target);
	void update(std::string text);

private:

	sf::Text m_text;
	sf::Font m_font;
};

