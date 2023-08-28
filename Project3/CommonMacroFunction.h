#pragma once


template <typename InterfaceType>
inline void SafeRelease(InterfaceType** currentScene)
{
	if (*currentScene != nullptr)
	{
		(*currentScene)->Release();
		*currentScene = nullptr;
	}
}

template <typename InterfaceType>
inline InterfaceType* SafeAcquire(InterfaceType* newObject)
{
	if (newObject != nullptr)
	{
		//���̰� ���� �Լ�
		newObject->AddRef();
	}
	return newObject;
}

// ���ο� ��ü�� ���϶� ���� ��ü�� ����
template <typename InterfaceType>
inline void SafeSet(InterfaceType** currentObject, InterfaceType* newObject)
{
	SafeAcquire(newObject);
	SafeRelease(&currentObject);
	currentObject = newObject;
}

inline HRESULT ExceptionToHResult()
{

	//���� �߻��� ���� �˻� ����
	try
	{
		//���� ���ܸ� �ٽ� ������.
		throw;
	}
	//try ��Ͽ��� �߻��� ���ܸ� ó���Ѵ�.
	//bad_alloc: �迭 �����÷ο� / ���� �Ҵ� Not alloc
	catch (std::bad_alloc&)
	{
		//�ϴ� ��ü null�� ��� ���α׷��� �츰��
		return E_OUTOFMEMORY;
	}

	catch (...)
	{
		return E_FAIL;
	}
}

//(x, y ) �ڷ��� ��ȯ
inline POINT PointMake(int x, int y)
{
	POINT pt = { x,y };
	return pt;
}

inline void LineMake(HDC hdc, int startX, int startY, int endX, int endY)
{
	MoveToEx(hdc, startX, startY,NULL);
	LineTo(hdc, endX, endY);
}

inline void LinePtPt(HDC hdc, POINT ptA, POINT ptB)
{
	MoveToEx(hdc, ptA.x, ptA.y, NULL);
	LineTo(hdc, ptB.x, ptB.y);
}

inline RECT RectMake(int x, int y, int width, int height)
{
	RECT rc = { x, y, x + width, y + height };
	return rc;
}

inline void DrawRectMake(HDC hdc, RECT rc)
{
	Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
}

inline RECT RectMakeCenter(int x, int y, int width ,int height)
{
	RECT rc = { x - width / 2, y - height / 2, x + width / 2, y + height / 2 };
	return rc;
}

inline void RectangleMake(HDC hdc, int x,int y,int width, int height)
{
	Rectangle(hdc, x, y, x + width, y + height);
}

inline void EllipseMake(HDC hdc, int x, int y, int width, int height)
{
	Ellipse(hdc, x, y, x + width, y + height);
}

inline void EllipseMakeCenter(HDC hdc, int x, int y, int width, int height)
{
	Ellipse(hdc, x - width / 2, y - height / 2, x + width / 2, y + height / 2);
}


//�浹 ���� ������¡
inline RECT CollisionAreaResizing(RECT& rcDest, int width, int height)
{
	RECT rc =
	{
		rcDest.left + width / 2,
		rcDest.top + height / 2,
		rcDest.right + width / 2,
		rcDest.bottom + height / 2,
	};

	return rc;
}