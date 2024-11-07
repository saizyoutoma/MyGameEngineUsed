#pragma once
#include "Engine/GameObject.h"

class TitleScene :
    public GameObject
{
public:
	//�R���X�g���N�^
	TitleScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
private:
	int tPict_; //�^�C�g����ʂ̉摜
	int select_; //�I���
	bool prevUpKey_;
	bool prevDownKey_;
};

