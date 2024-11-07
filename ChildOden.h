#pragma once
#include "Engine/GameObject.h"
#include "Engine/Model.h"

class FBX;

class ChildOden :
	public GameObject
{
	//FBX* pFbx;
	int hModel_;
public:
	//コンストラクタ
	//引数:parent
	ChildOden(GameObject* parent);
	~ChildOden();

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;

	void OnCollision(GameObject* pTarget) override;
};

