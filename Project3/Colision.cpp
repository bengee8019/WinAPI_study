#include "Stdafx.h"
#include "ShootingScene.h"

//new 와 테이블의 관계를 잘 생각해보자...
//쉽게 잘라낼 수 있도록 컴포넌트화 해서 빼주는 방식.
//

void ShootingScene::collision(void)
{
	for (int i = 0; i < _rocket->getMissile()->getBullet().size(); i++)
	{
		for (int j = 0; j < _em->getMinions().size(); j++)
		{
			RECT rc;
			if (IntersectRect(&rc, &_rocket->getMissile()->getBullet()[i].rc, //&_em->getMinions()[j]->getRect()))
				&CollisionAreaResizing(_em->getMinions()[j]->getRect(),40,30)))
			{
				_rocket->removeMissile(i);
				_em->addHitRenderer(j);
				_em->removeMinion(j);
				
				break;
			}
		}
	}

	//빔
	for (int i = 0; i < _rocket->getBeam()->getBullet().size(); i++)
	{
		for (int j = 0; j < _em->getMinions().size(); j++)
		{
			RECT rc;
			if (IntersectRect(&rc, &_rocket->getBeam()->getBullet()[i].rc, //&_em->getMinions()[j]->getRect()))
				&CollisionAreaResizing(_em->getMinions()[j]->getRect(), 40, 30)))

			{
				_em->addHitRenderer(j);
				_em->removeMinion(j);
				break;
			}
		}
	}

}

