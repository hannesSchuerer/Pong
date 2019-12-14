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
	PvPScene(SceneData* sceneData);
	~PvPScene();

	void draw() override;
	void update(const float& dt) override;


private:
	void initScene();

	float m_startTime;

	bool m_firstStart = true;

	Text* m_scorePlayerOne;
	Text* m_scorePlayerTwo;

	Background* m_background = nullptr;
	Player* m_playerOne = nullptr;
	Player* m_playerTwo = nullptr;
	Ball* m_ball = nullptr;
};

