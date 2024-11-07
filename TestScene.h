#pragma once
#include "Engine/GameObject.h"
#include "Engine/Sprite.h"

class TestScene :
    public GameObject
{
public:
	//�R���X�g���N�^
	//���� : parent  �e�I�u�W�F�N�g(SceneManager)
	TestScene(GameObject* parent);

	//������
	void Initialize() override;
	
	//�X�V
	void Update() override;
	
	//�`��
	void Draw() override;
	
	//�J��
	void Release() override;
};

