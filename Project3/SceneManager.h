#pragma once
#include "SingletonBase.h"
//씬을 관리할때는 자료구조를 쓰면 안된다
//	ㄴ 앞의 씬을 지우는 과정에서 참조가 깨진다.
//		1. 씬 인덱스로 관리한다.
//		2. 
class GameNode;
//class Scene;

class SceneManager : public SingletonBase<SceneManager>
{
	//friend class SingletonBase<SceneManager>;
public:
	//쓰레드로 따로 관리하기 위함 ->?
	// 콜백으로 소통하거나
	// 쓰레드로 관리하거나 -> 분리해서 동시에 처리(로딩씬의 경우)
	typedef map<string, GameNode*> mapSceneList;
	typedef map<string, GameNode*>::iterator mapSceneIter;


private:
	//map<int, Scene> _sceneList;
	static GameNode* _currentScene;
	static GameNode* _loadingScene;
	static GameNode* _readyScene;

	mapSceneList _mSceneList;

	//쓰레드를 쓰기 위해서
	mapSceneList _LoadingSceneList;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	GameNode* addScene(string sceneName, GameNode* scene);
	GameNode* addLoadingScene(string loadingSceneName, GameNode* scene);

	HRESULT changeScene(string sceneName);
	bool findScene(string sceneName);
	//api 에 맞춰서 lpvoid로 받아주는 형태
	friend DWORD CALLBACK loadingThread(LPVOID prc);
	//

	//이니셜라이저 쓰기가 애매하다
	SceneManager();
	~SceneManager();
};

//#define SCENEMANAGER SceneManager::getSingleton();
