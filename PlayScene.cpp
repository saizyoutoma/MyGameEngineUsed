#include "PlayScene.h"
#include "Player.h"
#include "Enemy.h"
#include <random>
#include "Engine/Image.h"
#include "Engine/SceneManager.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene"), eTime_(0.0f), hImage_(-1),
	timer_(2.0f), spTimer_(3.0f), eSpeed_(0.08)
{
}

PlayScene::~PlayScene()
{
}

void PlayScene::Initialize()
{
	Instantiate<Player>(this);
	//hImage_ = Image::Load("Assets/Image/finger.png");
}

void PlayScene::Update()
{
	srand((unsigned int)time(NULL));
	if (eTime_ <= 0.0f) {
		Enemy* e = Instantiate<Enemy>(this);
		if (spTimer_ <= 0.0f) {
			eSpeed_ += 0.05f;
			e->SetSpeed(eSpeed_);
		}
		int tmp = rand() % 2;
		if (tmp == 0) {
			tmp = -(rand() % 3);
		}
		else {
			tmp = rand() % 3;
		}
		e->SetPosition(2 * tmp, 0, 30);
		tmp = rand() % 201 + 100;
		eTime_ = (float)(tmp / 100);
	}
	eTime_ -= 1.0f / 60.0f;
	spTimer_ -= 1.0f / 60.0f;

	if (FindObject("Player") == nullptr) {
		if (timer_ <= 0.0f) {
			SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
			pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
		}
		timer_ -= 1.0f / 60.0f;
	}
}

void PlayScene::Draw()
{
	Transform tmp;
	tmp.scale_ = { 0.2,0.2,0.2 };
	//Image::SetTransform(hImage_, tmp);
	//Image::Draw(hImage_);
}

void PlayScene::Release()
{
}
