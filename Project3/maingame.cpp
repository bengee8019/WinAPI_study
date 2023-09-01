#include "Stdafx.h"
#include "maingame.h"
//#include "TileMap.h"
#include "ShootingScene.h"
#include "TestScene.h"



HRESULT maingame::init()
{
	GameNode::init(true);
	SOUNDMANAGER->init();
	SOUNDMANAGER->addSound("테스트", "Resources/sound/title.mp3", true, true);
	SCENEMANAGER->addScene("슈팅", new ShootingScene);
	SCENEMANAGER->addScene("테스트", new TestScene);

	//================================================

	SCENEMANAGER->changeScene("테스트");
	//Json::Value
	return S_OK;
}

void maingame::update()
{
	GameNode::update();
	//TIMEMANAGER->update();
	if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
	{
		SOUNDMANAGER->play("테스트", 0.5);
	}
	SOUNDMANAGER->update();
	SCENEMANAGER->update();
	ini.update();

}

void maingame::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZE_X, WINSIZE_Y, 0);
//=====================================================

	TIMEMANAGER->render(getMemDC());
	SCENEMANAGER->render();

//=====================================================
	this->getBackBuffer()->render(getHDC());
}

void maingame::release()
{
	SOUNDMANAGER->release();
	//IMAGEMANAGER->deleteAll();

}
