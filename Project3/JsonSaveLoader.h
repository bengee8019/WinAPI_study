#pragma once
#include "SingletonBase.h"

#pragma region 제이슨(JSON)
/*
▶ 제이슨 Java Script Object N

- 객체의 구조와 속성을 텍스트 형식으로 전달하기 위해 고안된 형식이며 데이터 교환의 표준
	ㄴ 자바 스크립트 기반 표준 표기법이지만 다양한 언어를 지원하기 때문에 확장성이 좋다.
	ㄴ 주로 인터넷에서 데이터를 주고 받을 때 자료를 표현하는 방법으로 많이 활용된다.
	ㄴ 텍스트 형식이기 때문에 사람에게도 아주 좋은 포맷.
		ㄴ 문자열 기반이기 때문에 오버헤드 적음

- 제이슨은 자료의 종류에 큰 제한은 없으며 특히 컴퓨터 변수값을 표현하는데 적합하다.
0 0 0 0 0 0 0 0 
비트연산 빠르다!

- 형식 자체가 자바 스크립트의 구문 형식을 따르지만 프로그래밍 언어나 "플랫폼"에 독립적이므로
	C, C++, C#, 자바, 자바 스크립트, 펄, 파이썬 등등 많은 언어에서 이용할 수 있다.

- CSV, XML, HTML -> JSON "일반적인 상황에서는 빠르다."
ㄴ 데이터의 형식과 성능을 고려하면 제이슨은 XML이라는 마크업 언어와 항상 고민을 하게 한다.

	메모리를 챙겨야 하고 통신상황 - XML, HTML
	
	메모리와 상관없이 속도를 챙기겠다 -> JSON
	
	CSV도 따로 확인해보자.

- 제이슨 형식에서 사용하는 기호

{}: 객체
키: 값: 객체가 가지는 속성
"": 문자열 데이터
[]: 배열


- C++ -> 제이슨 -> JsonCPP / Rapid Json
ㄴ 속도는 Rapid Json이 유리하다.
ㄴ 메모리 사용량은 JsonCPP가 유리하다.

- 

*/
#pragma endregion


class JsonSaveLoader :public SingletonBase<JsonSaveLoader>
{
private:
	void saveString(char* fileName, string data);
	void saveStringWithFileStream(char* fileName, string data);

	string loadString(char* fileName);
	string loadStringWithFileStream(char* fileName);


public:
	HRESULT init(void);
	void release(void);
	void saveJsonFile(char* fileName, Json::Value root);

	Json::Value loadJsonFile(char* fileName);

	JsonSaveLoader();
	~JsonSaveLoader();
};

