#include "Stdafx.h"
#include "TestScene.h"

HRESULT TestScene::init(void)
{
	//IMAGEMANAGER->addImage("버튼X", "Resources/Images/btn_close.bmp", 116, 132, true, RGB(255, 0, 255));

	_bgImg = IMAGEMANAGER->addImage("배경이미지", "Resources/MiniHealerBG.bmp", WINSIZE_X, WINSIZE_Y);

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
		SCENEMANAGER->changeScene("슈팅");
	}
}

void TestScene::render(void)
{
	_bgImg->render(getMemDC());

	//IMAGEMANAGER->findImage("버튼X")->render(getMemDC(), 500, 500);
}
