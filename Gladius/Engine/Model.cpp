//#include "Global.h"
//#include "Model.h"
//
////3Dモデル（FBXファイル）を管理する
//namespace Model
//{
//	//ロード済みのモデルデータ一覧
//	std::vector<ModelData*>	_datas;
//
//	//初期化
//	void Initialize()
//	{
//		AllRelease();
//	}
//
//	//モデルをロード
//	int Load(std::string fileName)
//	{
//			ModelData* pData = new ModelData;
//
//
//			//開いたファイル一覧から同じファイル名のものが無いか探す
//			bool isExist = false;
//			for (int i = 0; i < _datas.size(); i++)
//			{
//				//すでに開いている場合
//				if (_datas[i] != nullptr && _datas[i]->fileName == fileName)
//				{
//					pData->pFbx = _datas[i]->pFbx;
//					isExist = true;
//					break;
//				}
//			}
//
//			//新たにファイルを開く
//			if (isExist == false)
//			{
//				pData->pFbx = new Fbx;
//				if (FAILED(pData->pFbx->Load(fileName)))
//				{
//					//開けなかった
//					SAFE_DELETE(pData->pFbx);
//					SAFE_DELETE(pData);
//					return -1;
//				}
//
//				//無事開けた
//				pData->fileName = fileName;
//			}
//
//
//			//使ってない番号が無いか探す
//			for (int i = 0; i < _datas.size(); i++)
//			{
//				if (_datas[i] == nullptr)
//				{
//					_datas[i] = pData;
//					return i;
//				}
//			}
//
//			//新たに追加
//			_datas.push_back(pData);
//			return (int)_datas.size() - 1;
//	}
//
//
//
//	//描画
//	void Draw(int handle)
//	{
//		if (handle < 0 || handle >= _datas.size() || _datas[handle] == nullptr)
//		{
//			return;
//		}
//
//		//アニメーションを進める
//		_datas[handle]->nowFrame += _datas[handle]->animSpeed;
//
//		//最後までアニメーションしたら戻す
//		if (_datas[handle]->nowFrame > (float)_datas[handle]->endFrame)
//			_datas[handle]->nowFrame = (float)_datas[handle]->startFrame;
//
//
//
//		if (_datas[handle]->pFbx)
//		{
//			_datas[handle]->pFbx->Draw(_datas[handle]->transform, (int)_datas[handle]->nowFrame);
//		}
//	}
//
//
//	//任意のモデルを開放
//	void Release(int handle)
//	{
//		if (handle < 0 || handle >= _datas.size() || _datas[handle] == nullptr)
//		{
//			return;
//		}
//
//		//同じモデルを他でも使っていないか
//		bool isExist = false;
//		for (int i = 0; i < _datas.size(); i++)
//		{
//			//すでに開いている場合
//			if (_datas[i] != nullptr && i != handle && _datas[i]->pFbx == _datas[handle]->pFbx)
//			{
//				isExist = true;
//				break;
//			}
//		}
//
//		//使ってなければモデル解放
//		if (isExist == false )
//		{
//			SAFE_DELETE(_datas[handle]->pFbx);
//		}
//
//
//		SAFE_DELETE(_datas[handle]);
//	}
//
//
//	//全てのモデルを解放
//	void AllRelease()
//	{
//		for (int i = 0; i < _datas.size(); i++)
//		{
//			if (_datas[i] != nullptr)
//			{
//				Release(i);
//			}
//		}
//		_datas.clear();
//	}
//
//
//	//アニメーションのフレーム数をセット
//	void SetAnimFrame(int handle, int startFrame, int endFrame, float animSpeed)
//	{
//		_datas[handle]->SetAnimFrame(startFrame, endFrame, animSpeed);
//	}
//
//
//	//現在のアニメーションのフレームを取得
//	int GetAnimFrame(int handle)
//	{
//		return (int)_datas[handle]->nowFrame;
//	}
//
//
//	//任意のボーンの位置を取得
//	XMFLOAT3 GetBonePosition(int handle, std::string boneName)
//	{
//		XMFLOAT3 pos = _datas[handle]->pFbx->GetBonePosition(boneName);
//		XMVECTOR vec = XMVector3TransformCoord(XMLoadFloat3(&pos), _datas[handle]->transform.GetWorldMatrix());
//		XMStoreFloat3(&pos, vec);
//		return pos;
//	}
//
//
//	//ワールド行列を設定
//	void SetTransform(int handle, Transform & transform)
//	{
//		if (handle < 0 || handle >= _datas.size())
//		{
//			return;
//		}
//
//		_datas[handle]->transform = transform;
//	}
//
//
//	//ワールド行列の取得
//	XMMATRIX GetMatrix(int handle)
//	{
//		return _datas[handle]->transform.GetWorldMatrix();
//	}
//
//
//	//レイキャスト（レイを飛ばして当たり判定）
//	void RayCast(int handle, RayCastData *data)
//	{
//			XMFLOAT3 target = Transform::Float3Add(data->start, data->dir);
//			XMMATRIX matInv = XMMatrixInverse(nullptr, _datas[handle]->transform.GetWorldMatrix());
//			XMVECTOR vecStart = XMVector3TransformCoord(XMLoadFloat3(&data->start), matInv);
//			XMVECTOR vecTarget = XMVector3TransformCoord(XMLoadFloat3(&target), matInv);
//			XMVECTOR vecDir = vecTarget - vecStart;
//
//			XMStoreFloat3(&data->start, vecStart);
//			XMStoreFloat3(&data->dir, vecDir);
//
//			_datas[handle]->pFbx->RayCast(data); 
//	}
//}
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
	models[hModel]->pFbx->Draw(models[hModel]->transform, hModel);
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