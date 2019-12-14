#pragma once
#include "Scene.hpp"
#include "PvPScene.hpp"
#include "Text.hpp"

class MenueScene : public Scene
{
public:
	MenueScene(SceneData* sceneData);
	~MenueScene();

	// Geerbt über Scene
	virtual void update(const float & dt) override;
	virtual void draw() override;

private:

	Text* m_text;

};

