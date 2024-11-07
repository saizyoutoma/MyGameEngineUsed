#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "ChildOden.h"
#include "Engine/SphereCollider.h"

Player::Player(GameObject* parent)
	:GameObject(parent,"Player"),pModel_(-1)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
	//���f���̃��[�h
	pModel_ = Model::Load("Assets/Model/oden.fbx");
	assert(pModel_ >= 0);
	transform_.rotate_.x = 90;
	transform_.scale_ = { 2.0,2.0,2.0 };
	transform_.position_.y += 0.5;
	SphereCollider* col = new SphereCollider(0.8f);
	this->AddCollider(col);
}

void Player::Update()
{
	//A����������E�ɐi��
	if (Input::IsKey(DIK_A)) {
		if (transform_.position_.x >= -4.0f) {
			transform_.position_.x -= 0.1f;
		}
	}
	//D���������獶�ɐi��
	if (Input::IsKey(DIK_D)) {
		if (transform_.position_.x <= 4.0f) {
			transform_.position_.x += 0.1f;
		}
	}

	if (Input::IsKeyDown(DIK_E)) {
		ChildOden* cOden = Instantiate<ChildOden>(this);
		Transform tmp = transform_;
		tmp.position_.z += 2.0f;
		cOden->SetPosition(tmp.position_);
		cOden->SetScale(0.5, 0.5, 0.5);
	}
}

void Player::Draw()
{
	//���f���̕`��
	Model::SetTransform(pModel_, transform_);
	Model::Draw(pModel_);
}

void Player::Release()
{
}

void Player::OnCollision(GameObject* pTarget)
{
	//�����������̏���
	KillMe();
	pTarget->KillMe();
}
