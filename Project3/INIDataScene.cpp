#include "Stdafx.h"
#include "INIDataScene.h"

HRESULT INIDataScene::init(void)
{
    return S_OK;
}

void INIDataScene::release(void)
{
}

void INIDataScene::update(void)
{
	if (KEYMANAGER->isOnceKeyDown('9'))
	{
		INIDATAMANAGER->addData("�뼮", "������", "10");
		INIDATAMANAGER->addData("�뼮", "������", "10");
		INIDATAMANAGER->addData("�뼮", "������", "10");
		INIDATAMANAGER->addData("�뼮", "������", "10");

		INIDATAMANAGER->iniSave("100��");
	}
	if (KEYMANAGER->isOnceKeyDown('0'))
	{
		int test = INIDATAMANAGER->loadDataInteger("100��", "�뼮", "������");
		printf("�뼮: %d \n", test);

		int a = 0;

	}
}

void INIDataScene::render(void)
{
}

INIDataScene::INIDataScene()
{
}

INIDataScene::~INIDataScene()
{
}
