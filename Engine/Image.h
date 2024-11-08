#pragma once
#include <string>
#include <vector>
#include "Sprite.h"

namespace Image
{
	struct ImageData
	{
		//Sprite
		Sprite* pSprite_;
		//Transform
		Transform transform_;
		//FileName
		std::string filename_;
		ImageData() :pSprite_(nullptr), filename_("") {}
	};

	//モデルの一覧を保存する配列(Vector or List)
	int Load(std::string filename);
	void SetTransform(int hModel, Transform transform);
	void Draw(int hModel);
	void Release();
}