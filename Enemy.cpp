#include "Enemy.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent,"Enemy"),eModel_(-1),speed_(0)
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	//‚Æ‚è‚ ‚¦‚¸
	eModel_ = Model::Load("Assets/Model/enemy.fbx");
	assert(eModel_ >= 0);
	transform_.position_.y = 2.0f;
	transform_.scale_ = { 0.1f,0.1f,0.1f };
	SphereCollider* col = new SphereCollider(0.1f);
	this->AddCollider(col);
	speed_ = 0.08f;
}

void Enemy::Update()
{

	if (FindObject("Player")) {
		transform_.position_.z -= speed_;
		if (transform_.position_.z < 0.0f) {
			KillMe();
		}
	}
}

void Enemy::Draw()
{
	Model::SetTransform(eModel_, transform_);
	Model::Draw(eModel_);
}

void Enemy::Release()
{
}
