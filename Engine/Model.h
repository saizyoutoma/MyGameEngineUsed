#pragma once
#include <string>
#include <vector>
#include "FBX.h"

namespace Model
{
	struct ModelData
	{
		//FBX
		FBX* pFbx_;
		//Transform
		Transform transform_;
		//FileName
		std::string filename_;
		ModelData():pFbx_(nullptr), filename_(""){}
	};

	//���f���̈ꗗ��ۑ�����z��(Vector or List)
	int Load(std::string filename);
	void SetTransform(int hModel, Transform transform);
	void Draw(int hModel);
	void Release();
}
