#pragma once
#include "GameNode.h"
#include "Flame.h"

#define ROCKET_SPEED 3.0f

#pragma region ����Ʈ������
/*

- auto_ptr�� ��ü�ϱ� ���� ���� ����(C++11������ �����Ǿ���.)
�� ������ auto_ptr - �ڷ����� ���ؼ� �ڵ����� �����͸� ����� ��� -> �������� �������� ������ ���Ҵ�.

- ����Ʈ������ �޸� ���� �����ϰ� ������ Ȯ���� ���� ����Ѵ�.
�� ������ó�� �����ϴ� Ŭ���� ���ø�
�� ����� ���� �޸𸮸� �ڵ����� �����Ѵ�.

- ����ϱ� ������ <memory>����� �ʿ��ϰ� �⺻������ ���� �����Ͱ� ���� �޸𸮸� ����Ű�� �ϰ�
	�⺻ �����͸� ����Ʈ �����Ϳ� �����ϴ� �������� ���� ����Ѵ�.

- new(���� �Ҵ�)
�� �ѹ��� ��Ƽ� ó���ϴ� ����� �� ȿ�����̴�.
�� ����Ʈ �����͸� ���ÿ� �׻� ���� �����ϱ⶧���� ������ �޸𸮴� ��� �ӵ��� ì����.



�� ����

1. unique_ptr
�� ���� ��ü(��ü�� ���� �������� �����ϰ�(�ܺο��� ���� �Ұ���))
	�����Ͱ� ����Ǵ°��� ���� �� �ִ�. 


2. shared_ptr
�� �Ϲ������� ���� ��ü���� �ϳ��� ��ü�� ����ϰ� ���� �� �����Ѵ�
�� ����Ƚ���� ������� ����, �� �����ʹ� ��ü�� �������� ������ �� ����ϸ� ����.


3. weak_ptr
�� �ܵ� ���� �Ұ�
�� shared_ptr�� ������ ��ü�� ���� ������ ����� �� ����Ѵ�.
	
	1) ���ΰ� ���θ� �����ϴ� ��쿡 
		���� Ƚ���� ������Ű�� �ʱ� ������ (��ȯ ���� ������ ���� �� �ִ�.)

	2) �޸𸮿� ���� �ʰ� �Ѵ�. ( �������� �ʴ´� )





*/
#pragma endregion


// enable_shared_from_this: ��ü�� ���� �� �Ҹ꿡 ���� ���� ������ �ذ��Ѵ�.
// ������ ��ü���� �������� �ο��Ѵ�.

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
	//�����͸� �����Ѵ� -> ������ ���� �߻��� �� �ִ�. 
	//�迭 ���·� �����Ͱ� �������ٵ� 1�� �����Ϳ� �������� ������.
	//������ �������� �ο����ش�.
	/*std::shared_ptr<Rocket> get_shared_ptr()
	{
		return shared_from_this();
	}*/

	Rocket() { }//objectData = new GImage[10]; }
	~Rocket() {}
};

