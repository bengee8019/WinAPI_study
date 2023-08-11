#pragma once
#include "SingletonBase.h"
#include "GImage.h"

// 1. ��ü�� ���� new	
// 2. ���� ����				2�� �켱������ ����
// �� STL -> Map


#pragma region STL MAP
/*
KEY �� VALUE

first -> key
second -> value

insert()�� ����  key �� value�� ������ ���� pair�� �޴´�.

-pair() �ΰ��� �ڷ����� �ϳ��� �����ִ� ����ü ( ���ø����� � �ڷ����̶� �����ϴ�.)

-make_pair(): pair�� ������ִ� �Լ�
�� pair.first = x, pair.second = y
�� pair = make_pair(x, y)

�ϳ��� Ű�� ���� ���� �����ϰ� �ʹٸ� ��Ƽ���� ����غ� �� �ִ�.

pair�� Ȯ����� ������ �ۼ��ϰų� �ټ��� ��ȯ���� ������ �ʹٸ� tuple�� ����غ���.


*/
#pragma endregion

//��ü�� �������� �����ϱ� ���� singleton
class ImageManager : public SingletonBase<ImageManager>
{
private:
	typedef map<string, GImage*> mapImageList;
	typedef map<string, GImage*>::iterator mapImageIter;

private:
	mapImageList _mImageList;
	//���� string��� char*�� ���ٸ�?? ����Ʈ������ iterator���� 
		//1. ȣȯ�� ����, 2. �ݺ��ø��� �����ϸ鼭 �ӵ� ������


public:
	HRESULT init(void);
	void release(void);

	//�ܵ� ó���� ������
	// �� 1. �����ӿ�ũ �ڵ� ����ġ
	// �� 2. ��ü�� (�̹���) �浹 ���ɼ�


	GImage* addImage(string strKey, int width, int height);
	// �̹��� ���Ϸ� �ʱ�ȭ
	GImage* addImage(string strKey, const char* fileName, int width, int height, bool isTrans = false, COLORREF transColor = RGB(0, 0, 0));



	//1������ ��� ��
	GImage* addImage(string strKey, const char* fileName, float x, float y, int width, int height,
		bool isTrans = false,
		COLORREF transColor = RGB(0, 0, 0));
	//
	GImage* addFrameImage(string strKey, const char* fileName, int width, int height, int maxFrameX, int maxFrameY,
		bool isTrans = false,
		COLORREF transColor = RGB(0, 0, 0));
	//�÷��̾� ��ü � Ȱ��
	GImage* addFrameImage(string strKey, const char* fileName, float x, float y, int width, int height,
		int maxFrameX, int maxFrameY,
		bool isTrans = false,
		COLORREF transColor = RGB(0, 0, 0));


	GImage* findImage(string strKey);

	bool deleteImage(string strKey);
	bool deleteAll();


	// ����
	void render(string str, HDC hdc);
	void render(string str, HDC hdc, int destX, int destY);
	void render(string str, HDC hdc, int destX, int destY, int destWidth, int destHeight, int sourX, int sourY, int sourWidth, int sourHeight);
	// �̹��� Ŭ����
	void render(string str, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);
	// ���ķ���
	void alphaRender(string str, HDC hdc, BYTE alpha);
	void alphaRender(string str, HDC hdc, int destX, int destY, BYTE alpha);
	void alphaRender(string str, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha);
	void alphaRender(string str, HDC hdc, int destX, int destY, int destWidth, int destHeight, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha);

	//������ ����
	void frameRender(string str, HDC hdc, int destX, int destY);
	void frameRender(string str, HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);

	//��������
	void loopRender(string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY);
	void loopAlphaRender(string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY, BYTE alpha);

	//LPIMAGE_INFO getImageInfo() { return _imageInfo; }



	ImageManager();
	~ImageManager();
};

