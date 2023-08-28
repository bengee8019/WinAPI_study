#include "Stdafx.h"
#include "SceneManager.h"
//#include "Scene.h"
#include "GameNode.h"

//초기화만 -> 호출 여부에 관계없이 
GameNode* SceneManager::_currentScene = nullptr;
GameNode* SceneManager::_loadingScene = nullptr;
GameNode* SceneManager::_readyScene = nullptr;
//메모리의 4영역중 어디에 넣어줄지 정해주면 된다. 


DWORD CALLBACK loadingThread(LPVOID prc)
{
	// 교체될 씬의 함수 실행
	SceneManager::_readyScene->init();
	// 현재 씬을 교체될 씬으로 변경
	SceneManager::_currentScene = SceneManager::_readyScene;

	// 로딩 씬 해제
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
	//간결하고 문제 없어보인다. 그러나
	// C/C++ 에서는 싫어하는 형태 안전우선
	// 자동으로 맡기면 실수하기 딱좋다!
	//	연산이 필요없는 단순한 상황에서 사용하자
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

		//클래스 / 구조체
		//씬 전환시에도 데이터 유지를 해야되는 경우에는 여기서 빼주는 작업을 해주자.
		//static 추천 , 

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



