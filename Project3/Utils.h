#pragma once

//��ƿ��Ƽ ���
//���ӽ����̽��� ��! �� Ȱ���غ���
//
#define DEG_TO_RAD	0.017453f
#define PI			3.141592653f
#define PI_2		6.283185308f

#define FLPAT_EPSILON		0.001f
//�ݿø� ���� (Rounding Error)
// ���������� ������ ����ĥ �� �ִ�. �̶� ���Ƿ��� ���� ���ϸ� ���밪�̱⶧���� ������ �ɸ���.
// �ε��Ҽ��� �⺻������ �Ǽ��� ��Ȯ�ϰ� ǥ���ϴ°� �Ұ����ϴ�.
/*
������ �Ǽ��� ������ ��Ʈ�� ǥ���ϴµ� �Ѱ谡 �ֱ� ����.
��¿�� ���� �ٻ簪���� ó���� �Ѵ�.

�Ǽ��� �������� ���·� ����, ��Ȯ�� ����� ���ؼ��� ������� �ʿ��ϴ�.
3D�� �Ѿ�� ü���� Ȯ ���� �κ�.
*/

//�Ǽ�->����
#define FLOAT_TO_INT(f1)	static_cast<int>(f1+FLOAT_EPSILON)
/*
	ĳ���� ������
	1. static_cast
	2. dynamic_cast
	3. const_cast
	4. reinterpret_cast
	�� �����Ͱ� �޸𸮻� �迭�Ǵ� ������ �������� ���� �� �ִ�.
	�� �����
*/

//�� �Ǽ��� ������ ��
// 
#define FLOAT_EQUAL(f1,f2)	(fabs(f1-f2) <= FLOAT_EPSILON)



namespace MY_UTIL
{
	//�� �� ������ �Ÿ��� ��ȯ
	float getDistance(float startX, float startY, float endX, float endY);

	//�� �� ������ ������ �������� ��ȯ
	float getAngle(float startX, float startY, float endX, float endY);

}

