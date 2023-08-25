#pragma once



class SceneManager;

class Scene
{
	friend SceneManager;

private:

	//void init(int a);
	//friend Ű����� �̷��͵� �����ϴ� -> �ٽ� ã�ƺ���



	virtual void init() = 0;
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void exit() = 0;

protected:


public:
	Scene();
	virtual ~Scene();
};

