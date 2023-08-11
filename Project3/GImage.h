#pragma once
class GImage
{
public:
	enum IMAGE_LOAD_KIND
	{
		LOAD_RESOURCE = 0, LOAD_FILE,		// ���ҽ�, ����
		LOAD_EMPTY, LOAD_END				// �� ��Ʈ��, �ε� Done
	};

	typedef struct tagImage
	{
		DWORD		resID;
		HDC			hMemDC;
		HBITMAP		hBit;
		HBITMAP		hOBit;
		float		x;						//�̹��� x��ǥ
		float		y;						//�̹��� y��ǥ
		int			width;					//�̹��� ���� ũ��
		int			height;					//�̹��� ���� ũ��
		int			currentFrameX;			//���� ������ x
		int			currentFrameY;			//���� ������ y
		int			maxFrameX;				//�ִ� ������ x ����
		int			maxFrameY;				//�ִ� ������ y ����
		int			frameWidth;				//
		int			frameHeight;			//
		BYTE		loadType;				

		tagImage()
		{
			resID = 0;
			hMemDC = nullptr;
			hBit = nullptr;
			hOBit = nullptr;
			x = y = 0;
			width = 0;
			height = 0;
			currentFrameX = 0;
			currentFrameY = 0;
			maxFrameX = 0;
			maxFrameY = 0;
			frameWidth = 0;
			frameHeight = 0;

			loadType = LOAD_RESOURCE;
		}
	}IMAGE_INFO, *LPIMAGE_INFO;

private:
	LPIMAGE_INFO	_imageInfo;
	char*			_fileName;
	bool			_isTrans;			// ���ٰ���?
	COLORREF		_transColor;		// ���� RGB �� (����Ÿ = RGB(255, 0, 255)

	/*
	COLORREF

	- �������� ������ ǥ���ϱ� ���� ��ȣ���� 32��Ʈ ������
	�� R, G, B ���� 1����Ʈ(8��Ʈ)�̸� 0~255������ ���� ǥ���ϴµ� ����ȭ �Ǿ� �ִ�.
	*/

	BLENDFUNCTION	_blendFunc;			// ���ĺ��� ���
	LPIMAGE_INFO	_blendImage;		// ���ĺ��� �̹���

public:
	HRESULT init(int width, int height);

	// �̹��� ���ҽ��� �ʱ�ȭ
	HRESULT init(const DWORD resID, int width, int height, bool isTrans = false, COLORREF transColor = RGB(0, 0, 0));
	// �̹��� ���Ϸ� �ʱ�ȭ
	HRESULT init(const char* fileName, int width, int height, bool isTrans = false, COLORREF transColor = RGB(0, 0, 0));



	//1������ ��� ��
	HRESULT init(const char* fileName, float x, float y, int width, int height,
		bool isTrans = false,
		COLORREF transColor = RGB(0, 0, 0));

	//
	HRESULT init(const char* fileName, int width, int height, int maxFrameX, int maxFrameY,
		bool isTrans = false,
		COLORREF transColor = RGB(0, 0, 0));

	//�÷��̾� ��ü � Ȱ��
	HRESULT init(const char* fileName, float x, float y, int width, int height,
		int maxFrameX, int maxFrameY,
		bool isTrans = false,
		COLORREF transColor = RGB(0, 0, 0));


	HRESULT initForAlphaBlend(void);

	// ���� ColorŰ ����
	void setTransColor(bool isTrans, COLORREF transColor);

	// ����
	void release(void);

	// ����
	void render(HDC hdc);
	void render(HDC hdc, int destX, int destY);
	void render(HDC hdc, int destX, int destY, int destWidth, int destHeight, int sourX, int sourY, int sourWidth, int sourHeight);
	// �̹��� Ŭ����
	void render(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);
	// ���ķ���
	void alphaRender(HDC hdc, BYTE alpha);
	void alphaRender(HDC hdc, int destX, int destY, BYTE alpha);
	void alphaRender(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha);
	void alphaRender(HDC hdc, int destX, int destY, int destWidth, int destHeight, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha);

	//������ ����
	void frameRender(HDC hdc, int destX, int destY);
	void frameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);


	LPIMAGE_INFO getImageInfo() { return _imageInfo; }

	// = �ζ��� �Լ� =
	inline HDC getMemDC(void) { return _imageInfo->hMemDC; }
	
	//�̹��� X��ǥ
	inline float getX(void) { return _imageInfo->x; }
	inline void setX(float x) { _imageInfo->x = x; }

	//�̹��� Y��ǥ
	inline float getY(void) { return _imageInfo->y; }
	inline void setY(float y) { _imageInfo->y = y; }

	//�̹��� ������ǥ
	inline void setCenter(float x, float y)
	{
		_imageInfo->x = x - (_imageInfo->width / 2);
		_imageInfo->y = y - (_imageInfo->height / 2);
	}

	//�̹��� ���� / ���� ũ��
	inline int getwidth(void) { return _imageInfo->width; }
	inline int getheight(void) { return _imageInfo->height; }

	//�ٿ�� �ڽ� (�浹�� ��Ʈ)
	inline RECT boundingBox(void)
	{
		RECT rc =
		{
			_imageInfo->x,
			_imageInfo->y,
			_imageInfo->x + _imageInfo->width,
			_imageInfo->y + _imageInfo->height
		};
		return rc;
	}

	//�ٿ�� �ڽ� (�浹�� ��Ʈ)
	inline RECT boundingBoxWithFrame(void)
	{
		RECT rc =
		{
			_imageInfo->x,
			_imageInfo->y,
			_imageInfo->x + _imageInfo->frameWidth,
			_imageInfo->y + _imageInfo->frameHeight
		};
		return rc;
	}

	inline int getFrameX(void) { return _imageInfo->currentFrameX; }
	inline void setFrameX(int frameX)
	{ 
		_imageInfo->currentFrameX = frameX;
		if (frameX > _imageInfo->maxFrameX)
		{
			_imageInfo->currentFrameX = _imageInfo->maxFrameX;
		}
	}

	inline int getFrameY(void) { return _imageInfo->currentFrameY; }
	inline void setFrameY(int frameY)
	{
		_imageInfo->currentFrameY = frameY;
		if (frameY > _imageInfo->maxFrameY)
		{
			_imageInfo->currentFrameY = _imageInfo->maxFrameY;
		}
	}

	//�̹��� 1������ ���� / ���� ũ��
	inline int getFrameWidth(void) { return _imageInfo->frameWidth; }
	inline int getFrameHeight(void) { return _imageInfo->frameHeight; }

	//�ִ� ������ X / Y ����
	inline int getMaxFrameX(void) { return _imageInfo->maxFrameX; }
	inline int getMaxFrameY(void) { return _imageInfo->maxFrameY; }

	//==================��������====================
  // �� �ݺ� / �̹����� �а� ���� ��� 
	void loopRender(HDC hdc, const LPRECT drawArea, int offsetX, int offsetY); //ex) ���ð��� ���, ���װ��� ��� (Ȱ���ϸ� ī�޶�������)
							//�׷����� ����
	void loopAlphaRender(HDC hdc, const LPRECT drawArea, int offsetX, int offsetY, BYTE alpha);

	GImage();
	~GImage() {}
};

