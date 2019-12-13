#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.hpp"
#include "Background.hpp"
#include "Player.hpp"
#include "Ball.hpp"
#include "Text.hpp"

class PvPScene : public Scene
{
public:
	PvPScene(sf::VideoMode videoMode);
	~PvPScene();

	void draw(sf::RenderWindow& target) override;
	void update(const float& dt) override;
	ID getId();

	ID id = Scene::PvP;

private:
	void initScene();

	float m_startTime;

	bool m_firstStart = true;

	Text* m_scorePlayerOne;
	Text* m_scorePlayerTwo;

	sf::VideoMode m_videoMode;
	Background* m_background = nullptr;
	Player* m_playerOne = nullptr;
	Player* m_playerTwo = nullptr;
	Ball* m_ball = nullptr;
};

