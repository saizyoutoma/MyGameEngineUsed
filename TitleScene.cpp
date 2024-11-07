#include "TitleScene.h"
#include "Engine/SceneManager.h"
#include "Engine/Image.h"
#include "Engine/Input.h"

TitleScene::TitleScene(GameObject* parent)
	:GameObject(parent,"TitleScene"),tPict_(-1),select_(0)
{
	prevUpKey_ = false;
	prevDownKey_ = false;
}

void TitleScene::Initialize()
{
	//タイトル画像のロード
	tPict_ = Image::Load("Assets/Image/Title.png");
	assert(tPict_ >= 0);
}

void TitleScene::Update()
{
	//エンターで決定
	if (Input::IsKeyDown(DIK_RETURN)) {
			SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
			pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

void TitleScene::Draw()
{
	//タイトル画像の描画
	Image::SetTransform(tPict_, transform_);
	Image::Draw(tPict_);
}

void TitleScene::Release()
{
}
