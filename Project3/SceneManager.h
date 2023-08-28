#pragma once
#include "SingletonBase.h"
//���� �����Ҷ��� �ڷᱸ���� ���� �ȵȴ�
//	�� ���� ���� ����� �������� ������ ������.
//		1. �� �ε����� �����Ѵ�.
//		2. 
class GameNode;
//class Scene;

class SceneManager : public SingletonBase<SceneManager>
{
	//friend class SingletonBase<SceneManager>;
public:
	//������� ���� �����ϱ� ���� ->?
	// �ݹ����� �����ϰų�
	// ������� �����ϰų� -> �и��ؼ� ���ÿ� ó��(�ε����� ���)
	typedef map<string, GameNode*> mapSceneList;
	typedef map<string, GameNode*>::iterator mapSceneIter;


private:
	//map<int, Scene> _sceneList;
	static GameNode* _currentScene;
	static GameNode* _loadingScene;
	static GameNode* _readyScene;

	mapSceneList _mSceneList;

	//�����带 ���� ���ؼ�
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
	//api �� ���缭 lpvoid�� �޾��ִ� ����
	friend DWORD CALLBACK loadingThread(LPVOID prc);
	//

	//�̴ϼȶ����� ���Ⱑ �ָ��ϴ�
	SceneManager();
	~SceneManager();
};

//#define SCENEMANAGER SceneManager::getSingleton();
