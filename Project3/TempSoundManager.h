#pragma once
#include "SingletonBase.h"
// ������ ����� ���̺귯��(���)
// �ð� �Ǵ� ���� ���� -> PlaySound()
#include <mmsystem.h>
// ��ġ�����ڿ� ���� api tool
// mciSendString() �Լ��� ����ϱ� ���� �߰�
#include <mciapi.h>

#pragma comment(lib, "Winmm.lib")

class TempSoundManager : public SingletonBase <TempSoundManager>
{
public:
	HRESULT init(void);
	//Mp3
	void addMp3FileWithKey(string key, string fileName);
	//Wav
	void addWaveFileWithKey(string key, string fileName);
	//ȿ����
	void playEffectSoundWave(char* fileName);
	//Mp3 ���
	void playSoundWithKey(string key);
	//����
	void stopMp3WithKey(string key);

	TempSoundManager();
	~TempSoundManager();
};

