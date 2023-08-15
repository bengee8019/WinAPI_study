#include "Stdafx.h"
#include "Utils.h"

float MY_UTIL::getDistance(float startX, float startY, float endX, float endY)
{
	return sqrtf(pow(endX-startX,2)+pow(endY-startY,2));
}

float MY_UTIL::getAngle(float startX, float startY, float endX, float endY)
{
	return atan2f(endY-startY,endX-startX);
}
