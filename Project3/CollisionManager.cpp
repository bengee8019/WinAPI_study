#include "Stdafx.h"
#include "CollisionManager.h"

HRESULT CollisionManager::init()
{
	return S_OK;
}

void CollisionManager::collisionCheck()
{
	iterBullet _cVIBullet;
	viEnemy _cVIEnemy;

	for (_cVIEnemy = _cVEnemy.begin(); _cVIEnemy != _cVEnemy.end(); _cVIEnemy++)
	{
		for (_cVIBullet = _cVBullet.begin(); _cVIBullet != _cVBullet.end(); _cVIBullet++)
		{
			if (IntersectRect(&tmpRC, &(*_cVIEnemy)->getRC(), &(*_cVIBullet).rc))
			{

			}
		}
	}

}
