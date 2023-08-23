#pragma once
#include "GameNode.h"
#include "Flame.h"
#include "Bullets.h"
#include "ProgressBar.h"

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

class EnemyManager;

// enable_shared_from_this: ��ü�� ���� �� �Ҹ꿡 ���� ���� ������ �ذ��Ѵ�.
// ������ ��ü���� �������� �ο��Ѵ�.

enum EWeapon
{
	MISSILE, BEAM
};

class Rocket : public GameNode//, public std::enable_shared_from_this<Rocket>
{
private:
	GImage* _image;
	Flame* _flame;
	MissileM1* _Weapon;
	MissileM1* _missileM1;
	MissileM1* _spreadMissile;
	MissileM1* _miniRocket;
	Beam* _beam;
	EWeapon _setWeapon;
	ProgressBar* _hpBar;
	EnemyManager* _Em;
	//GImage* objectData;
	//Flame* (*pfFlame) (void);
	//Flame( int& xpos,  int& ypos);

	RECT _rc;
	float _x, _y;
	bool _beamIrradiation;

	float _currentHp;
	float _maxHp;
	//vector<std::shared_ptr<Rocket>> spRocket;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	void collision(void);
	void setEnemyManagerMemoryAddress(EnemyManager* em) { _Em = em; }

	void removeMissile(int arrNum);

	MissileM1* getMissile(void) { return _Weapon; }
	Beam* getBeam(void) { return _beam; }
	RECT getRect(void) { return _rc; }

	POINT getPosition(void) { return PointMake((int)_x, (int)_y); }
	inline void hitDamage(float damage)
	{
		if (_currentHp <= 0)
		{
			_currentHp = 0;

		}
		else
		{
			_currentHp += damage;
		}
	}
	void WeaponChange();
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

