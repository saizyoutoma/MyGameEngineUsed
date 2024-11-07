#include "ChildOden.h"
#include "Engine/FBX.h"
#include "Engine/SphereCollider.h"
#include "Player.h"

ChildOden::ChildOden(GameObject* parent)
	:GameObject(parent,"ChildOden"),hModel_(-1)
{
}

ChildOden::~ChildOden()
{
}

void ChildOden::Initialize()
{
	hModel_ = Model::Load("Assets/Model/oden.fbx");
	assert(hModel_ >= 0);
	transform_.rotate_.x = 90;
	SphereCollider* col = new SphereCollider(0.5f);
	this->AddCollider(col);

}

void ChildOden::Update()
{
	//transform_.rotate_.y++;
	transform_.position_.z += 0.1f;
	if (transform_.position_.z > 30.0f) {
		KillMe();
	}
}

void ChildOden::Draw()
{
	//pFbx->Draw(transform_);
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void ChildOden::Release()
{
}

void ChildOden::OnCollision(GameObject* pTarget)
{
	//“–‚½‚Á‚½Žž‚Ìˆ—
	KillMe();
	pTarget->KillMe();
}
