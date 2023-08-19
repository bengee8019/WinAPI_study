#include "Stdafx.h"
#include "maingame.h"
//#include "TileMap.h"



HRESULT maingame::init()
{
	GameNode::init(true);
	//_rocket = new Rocket();
	//_rocket->init();
	//_tileMap = new TileMap;
	//_tileMap->init();
	_GN = new Rocket;
	_GN->init();
	_em = new EnemyManager;
	_em->init();
	TIMEMANAGER->init();

	//std::shared_ptr<Rocket> PlayerA = std::make_shared<Rocket>();
	//std::shared_ptr<Rocket> PlayerB = PlayerA->get_shared_ptr();

	//PlayerA.use_count();

	IMAGEMANAGER->addImage("½´ÆÃ ¸Ê", "Resources/ShootingBG.bmp", WINSIZE_X, WINSIZE_Y);
	return S_OK;
}

void maingame::update()
{
	GameNode::update();
	TIMEMANAGER->update();

	//_rocket->update();
	_GN->update();
	_em->update();
	collision();
}

void maingame::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZE_X, WINSIZE_Y, 0);
//=====================================================

	IMAGEMANAGER->render("½´ÆÃ ¸Ê", getMemDC());
	//_rocket->render();
	_GN->render();
	_em->render();
	TIMEMANAGER->render(getMemDC());

//=====================================================
	this->getBackBuffer()->render(getHDC());
}

void maingame::release()
{
	//_rocket->release();
	_GN->release();
	_em->release();
	IMAGEMANAGER->deleteAll();
}
