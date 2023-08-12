#include "Stdafx.h"
#include "TileMap.h"

HRESULT TileMap::init()
{
	//마젠타 일부러 출력되도록
	IMAGEMANAGER->addImage("이미지","Resources/Rocket.bmp", 52, 64);

	//맵 크기 설정
	_mapWidth = WINSIZE_Y;
	_mapHeight = WINSIZE_Y;

	//맵 위치 설정
	_mapX = (WINSIZE_X - WINSIZE_Y) / 2;
	_mapY = 0;

	_onMouse = false;
	_inputSwitch = false;

	//숫자 입력 버퍼용 스트링
	_intBuffer.empty();

	//이미지 출력할 2개의 타일 번화
	randomIndex1 = 0;
	randomIndex2 = 0;

	setNewTile(10);
	return S_OK;
}

void TileMap::update()
{
	//tilenum 2 미만 예외처리 
	//if (_tileNum < 2)
	//{
	//	setNewTile();
	//}

	if (_inputSwitch)
	{
		keyInput();
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			//창 띄워서 입력 받기
			if (_intBuffer != "")
			{
				_inputSwitch = false;
				_tileNum = stoi(_intBuffer);
				_intBuffer = "";
				setNewTile(_tileNum);
			}
		}
	}
	else
	{
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			//창 띄워서 입력 받기
			_inputSwitch = true;
		}
	tileInteract();
	}
	//마우스 상호작용
	//입력받은값으로 setNewTile()실행, 
}

void TileMap::render()
{
	tileRender();
	if (_onMouse)
	{
		IMAGEMANAGER->render("이미지", getMemDC(), _ptMouse.x - _tileWidth / 2, _ptMouse.y - _tileHeight / 2, _tileWidth, _tileHeight, 0, 0, 52, 64);
	}
	if (_inputSwitch)
	{
		RectangleMake(getMemDC(), WINSIZE_X / 2 - 100, WINSIZE_Y/2 - 50, 200, 100);
		TextOut(getMemDC(), WINSIZE_X / 2 - 50, WINSIZE_Y/2 - 10, _intBuffer.c_str(), strlen(_intBuffer.c_str()));
	}
}

void TileMap::release()
{
	//이미지 삭제
	IMAGEMANAGER->deleteImage("이미지");
}

void TileMap::setNewTile(int tilenum)
{
	_tileNum = tilenum;

	//두 숫자가 다를때까지 반복해서 뽑기
	do
	{
		randomIndex1 = RND->getInt(_tileNum * _tileNum);
		randomIndex2 = RND->getInt(_tileNum * _tileNum);
	} while (randomIndex1 == randomIndex2);

	//타일 폭, 높이 설정
	_tileWidth = (float)_mapWidth / _tileNum;
	_tileHeight = (float)_mapHeight / _tileNum;

	//벡터 비워주고
	_vTiles.clear();
	//벡터 채우기
	TileMaker();
}

void TileMap::TileMaker()
{
	for (int i = 0; i < _tileNum * _tileNum; i++)
	{
		tagTile tmptile;
		tmptile.x = _mapX + (i % _tileNum) * _tileWidth;
		tmptile.y = _mapY + (i / _tileNum) * _tileHeight;
		if (i == randomIndex1 || i == randomIndex2)
		{
			tmptile.filled = true;
		}
		else
		{
			tmptile.filled = false;
		}
		tmptile.tRC = RectMake(tmptile.x, tmptile.y, _tileWidth, _tileHeight);
		_vTiles.push_back(tmptile);
	}
}

void TileMap::tileRender()
{
	for (_viTiles = _vTiles.begin(); _viTiles != _vTiles.end(); ++_viTiles)
	{
		DrawRectMake(getMemDC(), _viTiles->tRC);
		if (_viTiles->filled)
		{
			IMAGEMANAGER->render("이미지", getMemDC(), _viTiles->x, _viTiles->y, _tileWidth, _tileHeight, 0, 0, 52, 64);
		}
	}
}

void TileMap::tileInteract()
{
	for (_viTiles = _vTiles.begin(); _viTiles != _vTiles.end(); ++_viTiles)
	{
		if (PtInRect(&(_viTiles->tRC), _ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_onMouse = true;
				_viTiles->filled = false;
			}
			if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
			{
				_onMouse = false;
				_viTiles->filled = true;
			}
		}
	}
}

void TileMap::keyInput()
{
	if (KEYMANAGER->isOnceKeyDown(0x30))// || 0x60))
	{
		_intBuffer += "0";
	}
	if (KEYMANAGER->isOnceKeyDown(0x31))// || 0x61))
	{
		_intBuffer += "1";
	}
	if (KEYMANAGER->isOnceKeyDown(0x32))// || 0x62))
	{
		_intBuffer += "2";
	}
	if (KEYMANAGER->isOnceKeyDown(0x33))// || 0x63))
	{
		_intBuffer += "3";
	}
	if (KEYMANAGER->isOnceKeyDown(0x34))// || 0x64))
	{
		_intBuffer += "4";
	}
	if (KEYMANAGER->isOnceKeyDown(0x35))// || 0x65))
	{
		_intBuffer += "5";
	}
	if (KEYMANAGER->isOnceKeyDown(0x36))// || 0x66))
	{
		_intBuffer += "6";
	}
	if (KEYMANAGER->isOnceKeyDown(0x37))// || 0x67))
	{
		_intBuffer += "7";
	}
	if (KEYMANAGER->isOnceKeyDown(0x38))// || 0x68))
	{
		_intBuffer += "8";
	}
	if (KEYMANAGER->isOnceKeyDown(0x39))// || 0x69))
	{
		_intBuffer += "9";
	}
}


//클릭시 이미지 출력 X;
//isKeyStay 마우스 위치 따라오는 렉트 , isKeyOnceUp일때 해당 위치에 이미지 채워넣기;
//