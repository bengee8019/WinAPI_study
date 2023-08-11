#pragma once
#include "SingletonBase.h"

class RandomFunction : public SingletonBase <RandomFunction>
{
public:
	RandomFunction()
	{	
		//GetTickCount() : API �����Լ�
		//�� API �Լ��� OS�� ���õ� ���� ��� �Ⱓ�� üũ�� �ش�.
		//�� �и����� ������ üũ�� �����ϸ� �и����� ������ �ð����� ��ȯ�ϱ� ������
		//   �Ը� ũ�� �ʴ� ������ �����ϴ�.
		srand(GetTickCount()); //�����쿡 �ñ�ڴ� ����
	}
	~RandomFunction() {}

	inline int getInt(int num)
	{
		return rand() % num;
	}
	HRESULT init(void){ return S_OK; }
	// 0 �� ��������
	inline int getFromInTo(int fromNum, int toNum)
	{
		// if 
		return rand() % (toNum - fromNum + 1) + fromNum;
	}
	float getFloat(void)
	{
		return (float)rand() / (float)RAND_MAX;
	}

	float getFloat(float num)
	{
		return (float)rand() / RAND_MAX * num;
	}
	float getFromFloatTo(float fromNum, float toNum)
	{
		float rnd = (float)rand() / (float)RAND_MAX;
		return (rnd * (toNum - fromNum) + fromNum);
	}
	//void getShape(int x1, int y1,int x2, int y2)
	//{
	//	LineTo(hdc, x1, y1);
	//	MoveToEx(hdc, x2,y2,NULL);
	//	//��
	//	LineTo(hdc, x1, y1);
	//	MoveToEx(hdc, x2, y2, NULL);
	//	LineTo(hdc, x2, y2);
	//	MoveToEx(hdc, x1 + 50, y2, NULL);
	//	//�ﰢ��

	//	Rectangle(hdc,x1, y1, x2, y2);
	//	//�簢��
	//	Ellipse(hdc, x1, y1, x2, y2);
	//	//��
	//}
	
};