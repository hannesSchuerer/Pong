#include "Scene.hpp"

Scene::Scene(SceneData * sceneData)
{
	this->window = sceneData->window;
	this->scene = sceneData->scene;
	this->sceneData = sceneData;
}
