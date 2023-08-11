#pragma once
#include "GameNode.h"
#include "Flame.h"

#define ROCKET_SPEED 3.0f

#pragma region 스마트포인터
/*

- auto_ptr을 대체하기 위해 나온 문법(C++11에서는 삭제되었다.)
ㄴ 기존의 auto_ptr - 자료형에 대해서 자동으로 포인터를 만드는 기능 -> 가독성이 떨어지고 문제가 많았다.

- 스마트포인터 메모리 릭을 방지하고 안정성 확보를 위해 사용한다.
ㄴ 포인터처럼 동작하는 클래스 템플릿
ㄴ 사용이 끝난 메모리를 자동으로 해제한다.

- 사용하기 전에는 <memory>헤더가 필요하고 기본적으로 원시 포인터가 실제 메모리를 가리키게 하고
	기본 포인터를 스마트 포인터에 대입하는 형식으로 많이 사용한다.

- new(동적 할당)
ㄴ 한번에 모아서 처리하는 방식이 더 효율적이다.
ㄴ 스마트 포인터를 사용시에 항상 같이 등장하기때문에 웬만한 메모리는 묶어서 속도를 챙기자.



▷ 종류

1. unique_ptr
ㄴ 유일 객체(객체에 대한 소유권을 유일하게(외부에서 삭제 불가능))
	데이터가 변경되는것을 막을 수 있다. 


2. shared_ptr
ㄴ 일반적으로 여러 객체에서 하나의 객체를 사용하고 싶을 때 적용한다
ㄴ 참조횟수를 기반으로 동작, 이 포인터는 객체간 소유권을 분할할 때 사용하면 좋다.


3. weak_ptr
ㄴ 단독 실행 불가
ㄴ shared_ptr이 소유한 객체에 대한 접근을 허용할 때 사용한다.
	
	1) 서로가 서로를 참조하는 경우에 
		참조 횟수를 증가시키지 않기 때문에 (순환 참조 오류를 막을 수 있다.)

	2) 메모리에 들어가지 않게 한다. ( 터지지는 않는다 )





*/
#pragma endregion


// enable_shared_from_this: 객체의 생성 및 소멸에 의한 참조 문제를 해결한다.
// 각각의 객체에게 소유권을 부여한다.

class Rocket : public GameNode//, public std::enable_shared_from_this<Rocket>
{
private:
	GImage* _image;
	Flame* _flame;

	//GImage* objectData;
	//Flame* (*pfFlame) (void);
	//Flame( int& xpos,  int& ypos);

	RECT _rc;
	float _x, _y;

	//vector<std::shared_ptr<Rocket>> spRocket;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
	//POINT* 
	//포인터를 공유한다 -> 소유권 문제 발생할 수 있다. 
	//배열 형태로 포인터가 관리될텐데 1번 포인터에 소유권이 있을것.
	//각각에 소유권을 부여해준다.
	/*std::shared_ptr<Rocket> get_shared_ptr()
	{
		return shared_from_this();
	}*/

	Rocket() { }//objectData = new GImage[10]; }
	~Rocket() {}
};

