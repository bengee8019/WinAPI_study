#include "Stdafx.h"
#include "maingame.h"



HRESULT maingame::init()
{
	GameNode::init(true);
	_rocket = new Rocket();
	_rocket->init();

	//std::shared_ptr<Rocket> PlayerA = std::make_shared<Rocket>();
	//std::shared_ptr<Rocket> PlayerB = PlayerA->get_shared_ptr();

	//PlayerA.use_count();



	IMAGEMANAGER->addImage("½´ÆÃ ¸Ê", "Resources/ShootingBG.bmp", WINSIZE_X, WINSIZE_Y);
	return S_OK;
}

void maingame::update()
{
	GameNode::update();
	_rocket->update();
}

void maingame::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZE_X, WINSIZE_Y, 0);
//=====================================================

	IMAGEMANAGER->render("½´ÆÃ ¸Ê", getMemDC());
	_rocket->render();
	

//=====================================================
	this->getBackBuffer()->render(getHDC());
}

void maingame::release()
{
	_rocket->release();
}
