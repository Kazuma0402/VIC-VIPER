#include "Model.h"
#include <vector>
#include "Fbx.h"
#include "Direct3D.h"


//
namespace Model
{
	struct ModelData
	{
		Fbx* pFbx;
		Transform transform;
		std::string fileName;
	};

	std::vector<ModelData*>	models;
}

//ロード
int Model::Load(std::string fileName)
{
	ModelData* pData;
	pData = new ModelData;
	pData->fileName = fileName;

	pData->pFbx = nullptr;
	for (int i = 0; i < models.size(); i++)
	{
		if (models[i]->fileName == fileName)
		{
			pData->pFbx = models[i]->pFbx;
			break;
		}
	}

	if (pData->pFbx == nullptr)
	{
		pData->pFbx = new Fbx;
		pData->pFbx->Load(fileName);
	}

	models.push_back(pData);
	return models.size() - 1;
}


//トランスフォームをセット
void Model::SetTransform(int hModel, Transform transform)
{
	models[hModel]->transform = transform;
}


//描画
void Model::Draw(int hModel)
{
	models[hModel]->pFbx->Draw(models[hModel]->transform);
}


//
void Model::Release()
{
	for (int i = 0; i < models.size(); i++)
	{
		bool isExist = false;

		for (int j = i + 1; j < models.size(); j++)
		{
			if (models[i]->pFbx == models[j]->pFbx)
			{
				isExist = true;
				break;
			}
		}

		if (!isExist)
		{
			SAFE_DELETE(models[i]->pFbx);
		}

		SAFE_DELETE(models[i]);
	}

	models.clear();

}