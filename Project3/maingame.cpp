#include "Stdafx.h"
#include "maingame.h"
//#include "TileMap.h"

HRESULT maingame::init()
{
	GameNode::init(true);
	_rocket = new Rocket();
	_rocket->init();
	//_tileMap = new TileMap;
	//_tileMap->init();
	//_GN = new Rocket;
	//_GN->init();
	_em = new EnemyManager;
	_em->init();
	TIMEMANAGER->init();
	_as = new AniScene;
	_as->init();
	_x = _y = 0.0f;


	//std::shared_ptr<Rocket> PlayerA = std::make_shared<Rocket>();
	//std::shared_ptr<Rocket> PlayerB = PlayerA->get_shared_ptr();

	//PlayerA.use_count();

	IMAGEMANAGER->addImage("전장", "Resources/BattleField.bmp", WINSIZE_X, WINSIZE_Y);
	return S_OK;
}

void maingame::update()
{
	GameNode::update();
	TIMEMANAGER->update();

	//_rocket->update();
	_rocket->update();
	_em->update();
	_as->update();
	_y -= 2.0f;
	rc = RectMake(0, 0, WINSIZE_X, WINSIZE_Y);
	collision();
}

void maingame::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZE_X, WINSIZE_Y, 0);
//=====================================================

	IMAGEMANAGER->findImage("전장")->loopRender(getMemDC(),&rc, _x, _y);
	//_rocket->render();
	_rocket->render();
	_em->render();
	_as->render();
	TIMEMANAGER->render(getMemDC());

//=====================================================
	this->getBackBuffer()->render(getHDC());
}

void maingame::release()
{
	//_rocket->release();
	_rocket->release();
	_em->release();
	IMAGEMANAGER->deleteAll();
	_as->release();

}
