#pragma once

//유틸리티 모듈
//네임스페이스를 꼭! 잘 활용해보자
//
#define DEG_TO_RAD	0.017453f
#define PI			3.141592653f
#define PI_2		6.283185308f

#define FLPAT_EPSILON		0.001f
//반올림 오차 (Rounding Error)
// 오차때문에 조건을 지나칠 수 있다. 이때 엡실론을 통해 비교하면 절대값이기때문에 무적권 걸린다.
// 부동소수는 기본적으로 실수를 정확하게 표현하는게 불가능하다.
/*
무한한 실수를 유한한 비트로 표현하는데 한계가 있기 때문.
어쩔수 없이 근사값으로 처리를 한다.

실수를 이진수의 형태로 저장, 정확한 계산을 위해서는 상수값이 필요하다.
3D로 넘어가면 체감이 확 오는 부분.
*/

//실수->정수
#define FLOAT_TO_INT(f1)	static_cast<int>(f1+FLOAT_EPSILON)
/*
	캐스팅 연산자
	1. static_cast
	2. dynamic_cast
	3. const_cast
	4. reinterpret_cast
	ㄴ 데이터가 메모리상에 배열되는 순서가 역순으로 들어올 수 있다.
	ㄴ 엔디안
*/

//두 실수가 같은지 비교
// 
#define FLOAT_EQUAL(f1,f2)	(fabs(f1-f2) <= FLOAT_EPSILON)



namespace MY_UTIL
{
	//두 점 사이의 거리를 반환
	float getDistance(float startX, float startY, float endX, float endY);

	//두 점 사이의 각도를 라디안으로 반환
	float getAngle(float startX, float startY, float endX, float endY);

}

