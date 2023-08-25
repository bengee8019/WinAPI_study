#pragma once



class SceneManager;

class Scene
{
	friend SceneManager;

private:

	//void init(int a);
	//friend 키워드로 이런것도 가능하다 -> 다시 찾아보기



	virtual void init() = 0;
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void exit() = 0;

protected:


public:
	Scene();
	virtual ~Scene();
};

