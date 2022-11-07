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
	std::vector<ModelData*>	modelList;
}

//ロード
int Model::Load(std::string fileName)
{
	ModelData* pData;
	pData = new ModelData;
	pData->fileName = fileName;

	pData->pFbx = nullptr;
	for (int i = 0; i < modelList.size(); i++)
	{
		if (modelList[i]->fileName == fileName)
		{
			pData->pFbx = modelList[i]->pFbx;
			break;
		}
	}

	if (pData->pFbx == nullptr)
	{
		pData->pFbx = new Fbx;
		pData->pFbx->Load(fileName);
	}

	modelList.push_back(pData);
	return modelList.size() - 1;
}


//トランスフォームをセット
void Model::SetTransform(int hModel, Transform transform)
{
	modelList[hModel]->transform = transform;
}


//描画
void Model::Draw(int hModel)
{
	modelList[hModel]->pFbx->Draw(modelList[hModel]->transform);
}


//
void Model::Release()
{
	for (int i = 0; i < modelList.size(); i++)
	{
		bool isExist = false;

		for (int j = i + 1; j < modelList.size(); j++)
		{
			if (modelList[i]->pFbx == modelList[j]->pFbx)
			{
				isExist = true;
				break;
			}
		}

		if (!isExist)
		{
			SAFE_DELETE(modelList[i]->pFbx);
		}

		SAFE_DELETE(modelList[i]);
	}

	modelList.clear();
}

void Model::RayCast(int hModel_, RayCastData& rayData)
{
	XMFLOAT3 TarGet = { rayData.start.x + rayData.dir.x , rayData.start.y + rayData.dir.y, rayData.start.z + rayData.dir.z };
	XMMATRIX matInv = XMMatrixInverse(nullptr, modelList[hModel_]->transform.GetWorldMatrix()); //引数のモデルのワールド行列の逆行列
	XMVECTOR moveStart = XMLoadFloat3(&rayData.start);
	XMVECTOR InvDir = XMLoadFloat3(&rayData.dir);

	moveStart = XMVector3TransformCoord(moveStart, matInv);
	InvDir = XMVector3TransformCoord(InvDir, matInv);
	InvDir = InvDir - moveStart;
	XMStoreFloat3(&rayData.start, moveStart);
	XMStoreFloat3(&rayData.dir, InvDir);
	modelList[hModel_]->pFbx->RayCast(rayData);
}
