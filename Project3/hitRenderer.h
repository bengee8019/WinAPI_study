#pragma once
class hitRenderer
{
private:
	float _x, _y;
	int _nowFrame;
	int _frameCount;
	bool _nowAnimate;

public:
	HRESULT init(float x, float y);
	void update();
	void render(HDC hdc);
	void release();
	bool getNowAnimate() { return _nowAnimate; }
};

