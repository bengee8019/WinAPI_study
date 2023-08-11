#pragma once
#include "GameNode.h"

struct tagTile
{
	int x;
	int y;
	int tWidth;
	int tHeight;
	int tNum;
	RECT tRC;

};

class TileMap : public GameNode
{
private:
	int _tileNum;
	int _mapWidth;
	int _mapHeight;

	RECT _mapRC;
	vector<tagTile> _vTiles;
	vector<tagTile>::iterator _viTiles;


public:
	HRESULT init();
	void update();
	void render();
	void release();

	void setNewTile(int tilenum);


};

