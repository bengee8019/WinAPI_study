#pragma once



class SceneManager;

class Scene
{
	//◆ friend
	//복잡한 상속 구조에서 효율을 챙길때
	//수직(상속)과 수평(친구)의 관계
	//ㄴ private까지 접근이 가능하지만 잘써야한다.
	
	//클래스 , 함수
	//복잡한 구조에서는 사용할 기능의 함수만 friend로 지정해서 사용한다.
	//	friend는 단방향으로 적용된다.
	// friend 속성은 상속이 안된다.
	// 


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

