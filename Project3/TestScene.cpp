#include "Stdafx.h"
#include "TestScene.h"

HRESULT TestScene::init(void)
{
	//IMAGEMANAGER->addImage("��ưX", "Resources/Images/btn_close.bmp", 116, 132, true, RGB(255, 0, 255));

	_bgImg = IMAGEMANAGER->addImage("����̹���", "Resources/MiniHealerBG.bmp", WINSIZE_X, WINSIZE_Y);

	return S_OK;
}

void TestScene::release(void)
{
	SAFE_DELETE(_bgImg);
}

void TestScene::update(void)
{
	if (KEYMANAGER->isOnceKeyDown(VK_F12))
	{
		SCENEMANAGER->changeScene("����");
	}
}

void TestScene::render(void)
{
	_bgImg->render(getMemDC());

	//IMAGEMANAGER->findImage("��ưX")->render(getMemDC(), 500, 500);
}
