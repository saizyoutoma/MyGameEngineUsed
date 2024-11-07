#pragma once
#include "Engine/GameObject.h"
class PlayScene :
    public GameObject
{
public:
	//コンストラクタ
	PlayScene(GameObject* parent);
	
	//デストラクタ
	~PlayScene();

	//初期化
	void Initialize() override;
	
	//更新
	void Update() override;
	
	//描画
	void Draw() override;
	
	//開放
	void Release() override;

private:
	float eTime_;
	int hImage_;
	float timer_;
	float spTimer_;
	float eSpeed_;
};

