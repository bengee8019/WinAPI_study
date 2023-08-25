#pragma once
#include "SingletonBase.h"
//씬을 관리할때는 자료구조를 쓰면 안된다
//	ㄴ 앞의 씬을 지우는 과정에서 참조가 깨진다.
//		1. 씬 인덱스로 관리한다.
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
