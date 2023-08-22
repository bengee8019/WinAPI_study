#include "Stdafx.h"
#include "AniScene.h"

HRESULT AniScene::init(void)
{
	_image = IMAGEMANAGER->addImage("ÄÚ³¢¸®","Resources/elephant.bmp",660,268,true,RGB(255,0,255));
	_animationA = new Animation;
	_animationA->init(_image->getwidth(), _image->getheight(), 110, 67);
	_animationA->setDefPlayFrame(false, true);
	_animationA->setFPS(12);

	return S_OK;
}

void AniScene::release(void)
{
	_animationA->release();
	SAFE_DELETE(_animationA);
}

void AniScene::update(void)
{
	if (KEYMANAGER->isOnceKeyDown('B'))
	{
		_animationA->AniStart();
	}
	//????
	_animationA->frameUpdate(TIMEMANAGER->getElapsedTime() * 1);
}

void AniScene::render(void)
{
	_image->aniRender(getMemDC(), WINSIZE_X / 2 - 50, WINSIZE_Y / 2, _animationA);
}

AniScene::AniScene()
{
}

AniScene::~AniScene()
{
}
