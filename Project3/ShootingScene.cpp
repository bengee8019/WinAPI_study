#include "Stdafx.h"
#include "ShootingScene.h"

HRESULT ShootingScene::init()
{
	_rocket = new Rocket();
	_rocket->init();
	//_tileMap = new TileMap;
	//_tileMap->init();
	//_GN = new Rocket;
	//_GN->init();
	_em = new EnemyManager;
	_em->init();
	_em->setRocketMemoryAddress(_rocket);
	_rocket->setEnemyManagerMemoryAddress(_em);

	//TIMEMANAGER->init();
	_x = _y = 0.0f;


	//std::shared_ptr<Rocket> PlayerA = std::make_shared<Rocket>();
	//std::shared_ptr<Rocket> PlayerB = PlayerA->get_shared_ptr();

	//PlayerA.use_count();

	IMAGEMANAGER->addImage("����", "Resources/BattleField.bmp", WINSIZE_X, WINSIZE_Y);
	return S_OK;
}

void ShootingScene::update()
{
	//TIMEMANAGER->update();
	if (KEYMANAGER->isOnceKeyDown(VK_F11))
	{
		SCENEMANAGER->changeScene("�׽�Ʈ");
	}
	_rocket->update();
	//_rocket->update();
	_em->update();
	_y -= 2.0f;
	rc = RectMake(0, 0, WINSIZE_X, WINSIZE_Y);
	//collision();
}

void ShootingScene::render()
{

	IMAGEMANAGER->findImage("����")->loopRender(getMemDC(), &rc, _x, _y);
	//_rocket->render();
	_rocket->render();
	_em->render();
	//_as->render();
	//TIMEMANAGER->render(getMemDC());

}

void ShootingScene::release()
{
	//_rocket->release();
	_rocket->release();
	_em->release();
	//IMAGEMANAGER->deleteAll();

}
