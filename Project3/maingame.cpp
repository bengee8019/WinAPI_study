#include "Stdafx.h"
#include "maingame.h"
//#include "TileMap.h"
#include "ShootingScene.h"
#include "TestScene.h"


HRESULT maingame::init()
{
	GameNode::init(true);

	SCENEMANAGER->addScene("����", new ShootingScene);
	SCENEMANAGER->addScene("�׽�Ʈ", new TestScene);

	//================================================

	SCENEMANAGER->changeScene("�׽�Ʈ");

	return S_OK;
}

void maingame::update()
{
	GameNode::update();
	//TIMEMANAGER->update();
	SCENEMANAGER->update();


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
	//IMAGEMANAGER->deleteAll();

}
