#include "GameOverScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

GameOverScene::GameOverScene(GameObject* parent)
	:GameObject(parent, "GameOverScene"), gPict_(-1)
{
}

void GameOverScene::Initialize()
{
	gPict_ = Image::Load("Assets/Image/GameOver.png");
	assert(gPict_ >= 0);
}

void GameOverScene::Update()
{
	//ƒGƒ“ƒ^[‚ÅŒˆ’è
	if (Input::IsKeyDown(DIK_T)) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TITLE);
	}

	if (Input::IsKeyDown(DIK_R)) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

void GameOverScene::Draw()
{
	Image::SetTransform(gPict_, transform_);
	Image::Draw(gPict_);
}

void GameOverScene::Release()
{
}
