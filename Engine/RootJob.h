#pragma once

#include "GameObject.h"

class RootJob : public GameObject
{
public:
	RootJob(GameObject* parente);
	~RootJob();

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
};

