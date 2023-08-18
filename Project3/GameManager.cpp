#include "Stdafx.h"
#include "GameManager.h"

HRESULT GameManager::init(void)
{
	GameNode::init(true);
	//_GN = new Rocket;
	//_GN->init();
	_rocket = new Rocket;
	_rocket->init();
	_em = new EnemyManager;
	_em->init();
	TIMEMANAGER->init();
	IMAGEMANAGER->addImage("½´ÆÃ ¸Ê", "Resources/ShootingBG.bmp", WINSIZE_X, WINSIZE_Y);

	return S_OK;
}

void GameManager::release(void)
{
	GameNode::release();
	//_GN->release();
	_rocket->release();
	_em->release();
}

void GameManager::update(void)
{
	GameNode::update();
	TIMEMANAGER->update();

	//_rocket->update();
	//_GN->update();
	_rocket->update();
	_em->update();
	collision();
}

void GameManager::render()
{
	GameNode::render();
	PatBlt(getMemDC(), 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);
	// ========================================================
	IMAGEMANAGER->render("½´ÆÃ ¸Ê", getMemDC());
	
	//_GN->render();
	_rocket->render();
	_em->render();
	TIMEMANAGER->render(getMemDC());
	// ========================================================
	this->getBackBuffer()->render(this->getHDC(), 0, 0);
}
