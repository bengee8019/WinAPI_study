#include "Stdafx.h"
#include "SceneManager.h"
//#include "Scene.h"
#include "GameNode.h"

//�ʱ�ȭ�� -> ȣ�� ���ο� ������� 
GameNode* SceneManager::_currentScene = nullptr;
GameNode* SceneManager::_loadingScene = nullptr;
GameNode* SceneManager::_readyScene = nullptr;
//�޸��� 4������ ��� �־����� �����ָ� �ȴ�. 


DWORD CALLBACK loadingThread(LPVOID prc)
{
	// ��ü�� ���� �Լ� ����
	SceneManager::_readyScene->init();
	// ���� ���� ��ü�� ������ ����
	SceneManager::_currentScene = SceneManager::_readyScene;

	// �ε� �� ����
	SceneManager::_loadingScene->release();
	SceneManager::_loadingScene = nullptr;
	SceneManager::_readyScene = nullptr;

	return 0;
}

HRESULT SceneManager::init(void)
{
	_currentScene = nullptr;
	_loadingScene = nullptr;
	_readyScene = nullptr;
	return S_OK;
}

void SceneManager::release(void)
{
	//�����ϰ� ���� ����δ�. �׷���
	// C/C++ ������ �Ⱦ��ϴ� ���� �����켱
	// �ڵ����� �ñ�� �Ǽ��ϱ� ������!
	//	������ �ʿ���� �ܼ��� ��Ȳ���� �������
	/*for each (auto scene in _mSceneList)
	{
		SAFE_DELETE(scene.second);
	}*/

	mapSceneIter _miSceneList = _mSceneList.begin();

	for (; _miSceneList != _mSceneList.end();)
	{
		if (_miSceneList->second != nullptr)
		{
			if (_miSceneList->second == _currentScene)
			{
				_miSceneList->second->release();
			}
			SAFE_DELETE(_miSceneList->second);
			_miSceneList = _mSceneList.erase(_miSceneList);
		}
		else
		{
			++_miSceneList;
		}
	}
	_mSceneList.clear();
}

void SceneManager::update(void)
{
	if (_currentScene) _currentScene->update();
}

void SceneManager::render(void)
{
	if (_currentScene) _currentScene->render();
}

GameNode* SceneManager::addScene(string sceneName, GameNode* scene)
{
	if (!scene)	return nullptr;

	_mSceneList.insert(make_pair(sceneName, scene));
	
	return scene;
}

GameNode* SceneManager::addLoadingScene(string loadingSceneName, GameNode* scene)
{
	if (!scene)	return nullptr;

	_mSceneList.insert(make_pair(loadingSceneName, scene));

	return scene;
}

HRESULT SceneManager::changeScene(string sceneName)
{
	mapSceneIter find = _mSceneList.find(sceneName);

	if (find == _mSceneList.end()) return E_FAIL;
	if (find->second == _currentScene) return S_OK;

	if (SUCCEEDED(find->second->init()))
	{
		_currentScene = find->second;

		//Ŭ���� / ����ü
		//�� ��ȯ�ÿ��� ������ ������ �ؾߵǴ� ��쿡�� ���⼭ ���ִ� �۾��� ������.
		//static ��õ , 

		return S_OK;
	}

	return E_FAIL;
}

bool SceneManager::findScene(string sceneName)
{
	mapSceneIter find = _mSceneList.find(sceneName);

	if (find == _mSceneList.end()) return E_FAIL;
	if (find->second == _currentScene) return E_FAIL;

	return S_OK;

}

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}



