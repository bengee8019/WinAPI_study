#pragma once
#include "GameNode.h"

struct tagTile
{
	int x;
	int y;
	bool filled;
	RECT tRC;
};

class TileMap : public GameNode
{
private:
	int _tileNum;
	float _tileWidth;
	float _tileHeight;
	int _mapWidth;
	int _mapHeight;
	int _mapX;
	int _mapY;

	bool _onMouse;
	bool _inputSwitch;

	string _intBuffer;

	int randomIndex1;
	int randomIndex2;
	RECT _mapRC;
	vector<tagTile> _vTiles;
	vector<tagTile>::iterator _viTiles;


public:
	HRESULT init();
	void update();
	void render();
	void release();

	void setNewTile(int tilenum);
	void TileMaker();
	void tileRender();
	void tileInteract();
	void keyInput();
};

