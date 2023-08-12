#include "Stdafx.h"
#include "TileMap.h"

HRESULT TileMap::init()
{
	//����Ÿ �Ϻη� ��µǵ���
	IMAGEMANAGER->addImage("�̹���","Resources/Rocket.bmp", 52, 64);

	//�� ũ�� ����
	_mapWidth = WINSIZE_Y;
	_mapHeight = WINSIZE_Y;

	//�� ��ġ ����
	_mapX = (WINSIZE_X - WINSIZE_Y) / 2;
	_mapY = 0;

	_onMouse = false;
	_inputSwitch = false;

	//���� �Է� ���ۿ� ��Ʈ��
	_intBuffer.empty();

	//�̹��� ����� 2���� Ÿ�� ��ȭ
	randomIndex1 = 0;
	randomIndex2 = 0;

	setNewTile(10);
	return S_OK;
}

void TileMap::update()
{
	if (_inputSwitch)
	{
		keyInput();
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			//â ����� �Է� �ޱ�
			if (_intBuffer != "")
			{
				//tilenum 2 �̸� ����ó�� 
				if (stoi(_intBuffer) >= 2)
				{
					_inputSwitch = false;
					_tileNum = stoi(_intBuffer);
					setNewTile(_tileNum);
				}
				_intBuffer = "";
			}
		}
	}
	else
	{
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			//â ����� �Է� �ޱ�
			_inputSwitch = true;
		}
	tileInteract();
	}
}

void TileMap::render()
{
	tileRender();
	if (_onMouse)
	{
		IMAGEMANAGER->render("�̹���", getMemDC(), _ptMouse.x - _tileWidth / 2, _ptMouse.y - _tileHeight / 2, _tileWidth, _tileHeight, 0, 0, 52, 64);
	}
	if (_inputSwitch)
	{
		RectangleMake(getMemDC(), WINSIZE_X / 2 - 100, WINSIZE_Y/2 - 50, 200, 100);
		TextOut(getMemDC(), WINSIZE_X / 2 - 50, WINSIZE_Y/2 - 10, _intBuffer.c_str(), strlen(_intBuffer.c_str()));
	}
}

void TileMap::release()
{
	//�̹��� ����
	IMAGEMANAGER->deleteImage("�̹���");
}

void TileMap::setNewTile(int tilenum)
{
	_tileNum = tilenum;

	//�� ���ڰ� �ٸ������� �ݺ��ؼ� �̱�
	do
	{
		randomIndex1 = RND->getInt(_tileNum * _tileNum);
		randomIndex2 = RND->getInt(_tileNum * _tileNum);
	} while (randomIndex1 == randomIndex2);

	//Ÿ�� ��, ���� ����
	_tileWidth = (float)_mapWidth / _tileNum;
	_tileHeight = (float)_mapHeight / _tileNum;

	//���� ����ְ�
	_vTiles.clear();
	//���� ä���
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
			IMAGEMANAGER->render("�̹���", getMemDC(), _viTiles->x, _viTiles->y, _tileWidth, _tileHeight, 0, 0, 52, 64);
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
				if (_viTiles->filled)
				{
					_onMouse = true;
					_viTiles->filled = false;
				}
			}
			if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
			{
				if (_onMouse)
				{
					_onMouse = false;
					_viTiles->filled = true;
				}
			}
		}
	}
}

void TileMap::keyInput()
{
	if (KEYMANAGER->isOnceKeyDown(0x30))
	{
		_intBuffer += "0";
	}
	if (KEYMANAGER->isOnceKeyDown(0x31))
	{
		_intBuffer += "1";
	}
	if (KEYMANAGER->isOnceKeyDown(0x32))
	{
		_intBuffer += "2";
	}
	if (KEYMANAGER->isOnceKeyDown(0x33))
	{
		_intBuffer += "3";
	}
	if (KEYMANAGER->isOnceKeyDown(0x34))
	{
		_intBuffer += "4";
	}
	if (KEYMANAGER->isOnceKeyDown(0x35))
	{
		_intBuffer += "5";
	}
	if (KEYMANAGER->isOnceKeyDown(0x36))
	{
		_intBuffer += "6";
	}
	if (KEYMANAGER->isOnceKeyDown(0x37))
	{
		_intBuffer += "7";
	}
	if (KEYMANAGER->isOnceKeyDown(0x38))
	{
		_intBuffer += "8";
	}
	if (KEYMANAGER->isOnceKeyDown(0x39))
	{
		_intBuffer += "9";
	}
}