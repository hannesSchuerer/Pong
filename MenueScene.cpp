#include "MenueScene.hpp"

MenueScene::MenueScene(SceneData* sceneData)
	:Scene(sceneData)
{
	this->m_textGameName = new Text("Fonts/Pixeled.ttf", sf::Vector2f(window->getSize().x/2.f, window->getSize().y / 2.f), 50);
	this->m_textPlayPvP = new Text("Fonts/Pixeled.ttf", sf::Vector2f(window->getSize().x / 2.f, (window->getSize().y / 2.f)+100), 50);
}


MenueScene::~MenueScene()
{
	delete m_textGameName;
}

void MenueScene::update(const float & dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		scene->push(new PvPScene(sceneData));
	}
	this->m_textGameName->update("Pong");
	this->m_textPlayPvP->update("(P) PVP");
}

void MenueScene::draw()
{
	this->m_textGameName->draw(*window);
	this->m_textPlayPvP->draw(*window);
}


