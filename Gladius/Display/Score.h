#pragma once
#include "../Engine/GameObject.h"

class Score : public GameObject
{
	//ζpzρ
	int hPict_[11];
	int hScore_[6];

	//XRAΑZp
	int count = 0;

	//XRAΜΚ
	int Hundred;				//POOΜΚ
	int Thousand;				//POOOΜΚ
	int TenThousand;			//POOOOΜΚ
	int OneHundredThousand;		//POOOOOΜΚ

public:
	//RXgN^
	//ψFparent  eIuWFNg
	Score(GameObject* parent);

	//ϊ»
	void Initialize() override;

	//XV
	void Update() override;

	//`ζ
	void Draw() override;

	//Jϊ
	void Release() override;

	//XRAΜΑZ(+100)
	void Addition();

	//XRAΜΑZ(+1000)
	void Addition2();
};