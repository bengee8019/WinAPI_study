#pragma once
#include "SingletonBase.h"
//���� �����Ҷ��� �ڷᱸ���� ���� �ȵȴ�
//	�� ���� ���� ����� �������� ������ ������.
//		1. �� �ε����� �����Ѵ�.
//		2. 
class GameNode;
class Scene;

class SceneManager : public SingletonBase<SceneManager>
{
	friend class SingletonBase<SceneManager>;
private:
	//map<int, Scene> _sceneList;

public:
	SceneManager();
	~SceneManager();

};

#define SCENEMANAGER SceneManager::getSingleton();
