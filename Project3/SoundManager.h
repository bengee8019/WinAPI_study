#pragma once
#include "SingletonBase.h"

#pragma region ���� (FMOD + Ʈ������ + ���͸� ����)
/*
FMOD 

- ���� ���� ���̺귯��
	���� ���� �����̱� ������ �Ϲ����� Ȯ���ڴ� ���� �����Ѵ�
	�پ��� �÷������� ������ �Ѵ�.

- WinAPI / DirectX ���� ��쿡�� ��ü ���̺귯���� ������ ������ ������ �ʿ��� ��찡 ���� �����ϴ�.
	���� �Ⱓ ���� (������ ������� �и��Ǿ� ���� Ȱ���ϱ� ��������.)

�� ��� ����

- �𸮾� + ����Ƽ������ ���̼��� ������� �⺻ ����Ǿ��ִ�.
	�׷��� ������ ������ ��찡 ���� ��ø� ��ǥ�� �Ҷ��� ���̼����� �ʿ�� �Ѵ�.

- �𸮾� ����
	�ſ� ���̱� ������ ���̼��� ������� (�⺻ �÷�������)����Ǿ��ִ�.
	�÷����� �߰��ؼ� ����.
	�� EX) .bank  - fmod visualizer

- ����Ƽ ����
	�⺻������ FMODä��, ��� ����� ä�������� �ʴ´�.
	�߰� ����� ����ϱ� ���ؼ��� �߰� ������ ��ġ�ؾ� �Ѵ�.
	�� EX) .bank  - fmod visualizer

- �̿��� �÷���
	����ϱ� ���� ����ó���� �ʿ��ϴ�.
	���, Ŭ����, �̸� ����, ���̺귯�� ��ũ ->  ����??

- ����, �Ϳ�, ���̿���ũ �ø���, DJMAX RespectV ��� ���� ���ӿ��� ����ϰ��ִ�. 
	
�� FMOD ����

- ũ�� 3������ ������.
�� ���̺귯�� + ���α׷�

1. FMOD Ex
	��StudioAPI / CoreAPI
	�� �ο췹�� ���� ����(Native ���� ä��Ǵ� API)
	�� API ���� - ������ ������.
	�� �ڵ��� ���ϸ� ���� ������ ����. (����)
	�� �Ϲ����� ���� ������ ����ϰų� �����̳ʰ� �������� �����̵Ǵ� ��찡 ����. (wav, mp3, mid)


2. FMOD �̺�Ʈ �ý���
	�� Ex�� ���� ���̾�
	�� �����̳ʰ� �۾��� ���� �������� ����ϴ� Data ��� Driven API
	�� �����̳��� ������� ���� ����ȭ�� �ڵ�� ��������� �븱 �� �ִ�.
	�� �����̳ʿ� ���� ���� Ʃ���� �����ϱ� ������ ���α׷��Ӱ� ���忡 �Ű澲�� �ʾƵ� �ȴ�. -> ���߼ӵ� ���

	�� ��Ȳ�� ���带 �����̳ʿ� �־�ΰ�
	�� �̺�Ʈ�� ���� �ε����� ���ڷ� �־��ְ� �÷��̸� ���ָ� �Ǵ� ���


3. FMOD �����̳�
	�� ���� �̺�Ʈ�� ������ ��
	�� ��ȹ + ���� + ���⼺ �ܰ迡�� FMOD�� ä���� �Ǹ� ���� �����̳ʰ� �ַ� ����Ѵ�.
	�� ��� ����, �����̳� ���̴� Ʈ������ ���踦 �� �����̱� ������ ���α׷��ӷμ��� ���ϴ�.

�����̳ʿ� ������ �ϵ��� ���� �ϵ��� ������� �˾ƾ� �ϴ� ������̴�.

FMOD ���� �ܺα�� ��ü�� ���̺귯���� ���� �ش� �÷����� �� �°Բ� Ŀ���ҵǱ� ������
�ܺ� ���̺귯���� ����ϱ� ���ؼ��� ���̺귯���� ���� ���ذ� �ʿ��ϴ�.

	�� ���� ���̺귯�� - .dll
		��Ÿ�ӿ��� ã�Ƽ� ���� ������ �����н� �Ű澲��.

	
	�� ���� ���̺귯�� - .lib
		�� ���ԵǾ��ֱ� ������ ���� ã�� �ʾƵ� �ȴ�.	(����)
		�� ���̺귯���� ũ�� ������Ʈ�� ���ſ����� �ִ�.(����)

	������ �ʿ��� ����̴�? ->���� ���̺귯���� �ӵ��� ì����.



*/
#pragma endregion
//���� ����
constexpr auto soundBuffer = 10;
//������ ä��(����)
constexpr auto extraSoundChannel = 5;
//�� ���� ����
constexpr auto totalSoundChannel = soundBuffer + extraSoundChannel;

using namespace FMOD;

class SoundManager :public SingletonBase<SoundManager>
{
private:
	typedef map<string, Sound**> arrSounds;
	typedef map<string, Sound**>::iterator arrSoundsIter;
	typedef map<string, Channel**> arrChannels;
	typedef map<string, Channel**>::iterator arrChannelsIter;

	System* _system;
	Sound** _sound;
	Channel** _channel;

	arrSounds _mTotalSounds;

public:
	HRESULT init(void);
	void release(void);
	void update(void);

	void addSound(string keykeyName, string soundName, bool backGround, bool loop);

	void play(string keyName, float volume);
	void stop(string keyName);
	void pause(string keyName);
	void resume(string keyName);

	bool isPlaySound(string keyName);
	bool isPauseSound(string keyName);

	SoundManager();
	~SoundManager() {}
};

