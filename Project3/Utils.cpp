#include "Stdafx.h"
#include "Utils.h"

float MY_UTIL::getDistance(float startX, float startY, float endX, float endY)
{
	return sqrtf(pow(startX-endX,2)+pow(startY-endY,2));
}

float MY_UTIL::getAngle(float startX, float startY, float endX, float endY)
{
	return atan2f(startY-endY,startX-endX);
}
