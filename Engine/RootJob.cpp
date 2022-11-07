#include "RootJob.h"
#include "SceneManager.h"

RootJob::RootJob(GameObject* parent) : GameObject(parent, "Rootjob")
{
}

RootJob::~RootJob()
{
}

void RootJob::Initialize(void)
{
	Instantiate<SceneManager>(this);
}

void RootJob::Update()
{

}

void RootJob::Draw()
{
}

void RootJob::Release()
{
}