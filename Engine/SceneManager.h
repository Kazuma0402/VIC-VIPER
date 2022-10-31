#pragma once
#include "GameObject.h"

enum SCENE_ID
{
	SCENE_ID_PLAY = 0,
};


class SceneManager : public GameObject
{
	SCENE_ID currentSceneID_;	//���݂̃V�[��
	SCENE_ID nextSceneID_;		//���̃V�[��

public:

	SceneManager(GameObject* parent);
	~SceneManager();

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;

	void ChangeScene(SCENE_ID next);
};