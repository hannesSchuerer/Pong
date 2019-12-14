#include "MenueScene.hpp"

MenueScene::MenueScene(SceneData* sceneData)
	:Scene(sceneData)
{
	this->m_text = new Text("Fonts/Pixeled.ttf", sf::Vector2f(window->getSize().x/2.f, window->getSize().y / 2.f), 50);
}


MenueScene::~MenueScene()
{
	delete m_text;
}

void MenueScene::update(const float & dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		scene->push(new PvPScene(sceneData));
	}
	this->m_text->update("Pong");
}

void MenueScene::draw()
{
	this->m_text->draw(*window);
}
