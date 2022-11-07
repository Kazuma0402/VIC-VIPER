#pragma once
#include "GameObject.h"

enum SCENE_ID
{
	SCENE_ID_PLAY = 0,
	SCENE_ID_EDIT,
};


class SceneManager : public GameObject
{
	SCENE_ID currentSceneID_;	//現在のシーン
	SCENE_ID nextSceneID_;		//次のシーン

public:

	SceneManager(GameObject* parent);
	~SceneManager();

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;

	void ChangeScene(SCENE_ID next);
};
