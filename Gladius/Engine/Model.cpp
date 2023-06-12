//#include "Global.h"
//#include "Model.h"
//
////3D���f���iFBX�t�@�C���j���Ǘ�����
//namespace Model
//{
//	//���[�h�ς݂̃��f���f�[�^�ꗗ
//	std::vector<ModelData*>	_datas;
//
//	//������
//	void Initialize()
//	{
//		AllRelease();
//	}
//
//	//���f�������[�h
//	int Load(std::string fileName)
//	{
//			ModelData* pData = new ModelData;
//
//
//			//�J�����t�@�C���ꗗ���瓯���t�@�C�����̂��̂��������T��
//			bool isExist = false;
//			for (int i = 0; i < _datas.size(); i++)
//			{
//				//���łɊJ���Ă���ꍇ
//				if (_datas[i] != nullptr && _datas[i]->fileName == fileName)
//				{
//					pData->pFbx = _datas[i]->pFbx;
//					isExist = true;
//					break;
//				}
//			}
//
//			//�V���Ƀt�@�C�����J��
//			if (isExist == false)
//			{
//				pData->pFbx = new Fbx;
//				if (FAILED(pData->pFbx->Load(fileName)))
//				{
//					//�J���Ȃ�����
//					SAFE_DELETE(pData->pFbx);
//					SAFE_DELETE(pData);
//					return -1;
//				}
//
//				//�����J����
//				pData->fileName = fileName;
//			}
//
//
//			//�g���ĂȂ��ԍ����������T��
//			for (int i = 0; i < _datas.size(); i++)
//			{
//				if (_datas[i] == nullptr)
//				{
//					_datas[i] = pData;
//					return i;
//				}
//			}
//
//			//�V���ɒǉ�
//			_datas.push_back(pData);
//			return (int)_datas.size() - 1;
//	}
//
//
//
//	//�`��
//	void Draw(int handle)
//	{
//		if (handle < 0 || handle >= _datas.size() || _datas[handle] == nullptr)
//		{
//			return;
//		}
//
//		//�A�j���[�V������i�߂�
//		_datas[handle]->nowFrame += _datas[handle]->animSpeed;
//
//		//�Ō�܂ŃA�j���[�V����������߂�
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
//	//�C�ӂ̃��f�����J��
//	void Release(int handle)
//	{
//		if (handle < 0 || handle >= _datas.size() || _datas[handle] == nullptr)
//		{
//			return;
//		}
//
//		//�������f���𑼂ł��g���Ă��Ȃ���
//		bool isExist = false;
//		for (int i = 0; i < _datas.size(); i++)
//		{
//			//���łɊJ���Ă���ꍇ
//			if (_datas[i] != nullptr && i != handle && _datas[i]->pFbx == _datas[handle]->pFbx)
//			{
//				isExist = true;
//				break;
//			}
//		}
//
//		//�g���ĂȂ���΃��f�����
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
//	//�S�Ẵ��f�������
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
//	//�A�j���[�V�����̃t���[�������Z�b�g
//	void SetAnimFrame(int handle, int startFrame, int endFrame, float animSpeed)
//	{
//		_datas[handle]->SetAnimFrame(startFrame, endFrame, animSpeed);
//	}
//
//
//	//���݂̃A�j���[�V�����̃t���[�����擾
//	int GetAnimFrame(int handle)
//	{
//		return (int)_datas[handle]->nowFrame;
//	}
//
//
//	//�C�ӂ̃{�[���̈ʒu���擾
//	XMFLOAT3 GetBonePosition(int handle, std::string boneName)
//	{
//		XMFLOAT3 pos = _datas[handle]->pFbx->GetBonePosition(boneName);
//		XMVECTOR vec = XMVector3TransformCoord(XMLoadFloat3(&pos), _datas[handle]->transform.GetWorldMatrix());
//		XMStoreFloat3(&pos, vec);
//		return pos;
//	}
//
//
//	//���[���h�s���ݒ�
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
//	//���[���h�s��̎擾
//	XMMATRIX GetMatrix(int handle)
//	{
//		return _datas[handle]->transform.GetWorldMatrix();
//	}
//
//
//	//���C�L���X�g�i���C���΂��ē����蔻��j
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

//���[�h
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


//�g�����X�t�H�[�����Z�b�g
void Model::SetTransform(int hModel, Transform transform)
{
	models[hModel]->transform = transform;
}


//�`��
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