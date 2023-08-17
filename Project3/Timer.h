#pragma once

//���� Ÿ�̸� ���̱� ������ node�� ���� �ʰ� ���ΰ��ӿ� �ٷ� ����

// int�� 4byte
// long�� 64��Ʈ���� 8byte


#pragma region
/*
- API �����Լ�
�� ������ �ִ�.
�� ���� ���� �ܰԿ��� ������ ����ϰ� ���� Ÿ�̸ӵ��� �ƴϱ� ������ ���е��� ��������.


timeGetTime ##	(�����찡 ���۵��� 1�� �����ٸ� 60000��ȯ)
GetTickCount	(���� �ð� üũ -> ���õ� ���� 1�ʿ� 1000�� ����) 49.7�� ���� �����츦 �ѳ����� 0���� �ʱ�ȭ�Ǿ� ���� �߻�
GetTickCount64	

- Ÿ�̸�
�� �ð��� �����ϴ� �Լ����� �⺻������ �����찡 ���۵� ���� ���� �ð��� Mili second ������ ��ȯ.
�� �и������� ���ӿ��� ���⿡�� ���е��� ��������.
	���� ���� Ÿ�̸Ӱ� �ʿ��ϴ�!
	9000000�� ���� 1�ʸ���

�ػ�, Ŭ��

�� �ػ�?
�� 1���� �������� �󸶳� ���� ���������� ���� �� �ִ���
	
�� Ŭ��(������)?
�� CPU Ŭ��
�� ������ ȸ���� ������ ������ Hz(�ʴ� ������) ������ ǥ��
�� ���� 1���� 2���� ��ȣ 1��, 1��Ʈ�� �ű� �� �ִ�.
1GHz 1�ʿ� 1000000000�� = 10^9 = 10���

����
	�� Milli Second
	�� 10 Milli Second		Centi
	�� 100 Milli Second		Deci
*/
#pragma endregion timer

class Timer
{
private:
	float _timeScale;		//���� �ð��� 
	float _timeElapsed;		//�ð� �����
	bool _isHardWare;		//�ϵ���� ���� ����

	__int64 _curTime;
	__int64 _lastTime;
	__int64 _periodFrequency;	//�ð� �ֱ�

	unsigned long _frameRate;	//�ʴ� ������
	unsigned long _FPSFrameCount;	//
	float _FPSTimeElapsed;	//FPS �ð� ����� üũ
	float _worldTime;		//���� ���� �� ����ð�

public:
	HRESULT init(void);
	// -> ��������ȭ �ý����� ����
	void tick(float lockFPS = 0.0f); //������ ����


	//�����Ǹ� �ȵǴ� ��.
	//�Լ��� ���� const �ܺο��� �� ������ ������� �ʱ� ����
	unsigned long getFrameRate(char* str = nullptr) const;
	inline float getElapsedTime(void) const { return _timeElapsed; }
	inline float getWorldTime(void) const { return _worldTime; }

	Timer() {}
	~Timer() {}
};

