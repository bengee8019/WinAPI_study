#pragma once
#include "SingletonBase.h"

#pragma region 파일 입출력
/*
비휘발성 메모리 HDD/SDD에 저장할때
어떻게 보낼지?		문법
어떻게 저장할지?		file format

▶ 문법적인 측면
	파일 포인터
		C	-	f*
		C++	-	fstream
		+ 플랫폼에서 지원하는 함수
			이를 사용해서 OS의 파일패스로 전달

▶ 파일 포맷 
	OS가 데이터를 Packing할 경우 암호화가 발생한다.

	Packing 하는 경우
		직접 암호화하거나
			패턴이 사람마다 다르기 때문에 쉽지 않다.
				1. 패턴의 오염
					패턴을 섞어서 

				2. 컴파일러 꺼내기
					읽던 컴파일러에게 종료 메세지를 날려서 더이상 못읽게 한다.

				3. 컴파일러 장악
					사후 처리를 위해 
					ㄴ 보안 우선

					ㄴ 주소(패턴)
						역추적해서 주소를 따면
						역컴파일을 걸어 실행하는 코드 정보를 저장한다.
						-> 얻은 정보를 바탕으로 사후 처리


			데누보 - 게임 출시 초기 3개월가량 뚫리는걸 막아주는 역할로 쓴다
				ㄴ (DRM)Digital Right Management 
					

		OS가 하거나
			바이너리파일의 이진코드의 패턴을 확인해서 언패킹

	Packing 하지 않은 경우
		파일 포맷
			ㄴ INI, JSON, txt, xml, csv, HTML 등등
				2	4	1	4	3	5

				INI, JSON 할줄 알아야 한다.

		고려할 점 2가지

			▶ 속도를 챙길 수 있는지?

			▶ 표현 방식이 명확한지?

만드는 게임 종류에 따라서 형태가 다 달라지기 때문에
파일 포인터를 사용할줄 아는게 좋겠다.

▶ INI (Initialization)
	
	- 응용 프로그램이나 윈도우 자체의 초기 설정에 필요한 정보가 기입된 텍스트 파일

	- INI 파일은 설정 파일에 대한 사실상 표준이라고 정의할 수 있다.
		ㄴ 대체할 수 있는 포맷이 전무하고 설정 파일을 관리할 때 아주 용이하다.
		ㄴ 또한 단순 구조의 텍스트 파일로 구성이 되어 있다는 특징이 있다.
		ㄴ 텍스트 파일의 포멧을 가지고 있기 때문에 확장자 변환도 허용(txt로 변환)

	- INI 파일은 마이크로소프트가 만든 OS인 윈도우즈에 연결이 되지만 다른 운영체제에서도 사용할 수 있다.

	- 일반적으로 프로그램이 실행될 때 해당하는 INI파일을 통해 프로그램 실행에 필요한 기본 정보를 읽어들이면서 시작한다.


	▷ 게임에서는 언제 사용할까?

	- 옵션 등에 자주 사용이 되고 상용엔진의 경우는 에디터의 설정값 저장에 사용된다.

	- 게임쪽에서 INI 파일은 값이 자주 바뀌는 경우에 사용하면 좋다.


	▷ INI 하면 떠올릴 3가지

	- 섹션, 키, 값

	- 일반적인 형태 (커스텀X)
	대괄호로 섹션이 나눠져있으면 INI파일 포맷이다.

	[Section]
	Key = Value

	- 커스텀 형태 (상용 엔진)
	[Section]
	Path = Value	(C:\.....)
	LifeTime = Key (1)   (함수)/ = 1 (또는 변수) 

	안써보면 실력이 진짜 안늘어나는 분야




*/
#pragma endregion

struct tagIniData
{
	char* section;
	char* key;
	char* value;
};

class INIData : public SingletonBase<INIData>
{
private:
	typedef vector<tagIniData> arrIniData;
	typedef vector<arrIniData> arrIniDatas;

	arrIniDatas _vIniData;

public:
	HRESULT init(void);
	void release(void);

	//데이터 추가->
	void addData(char* section, char* key, char* value);
	//세이브
	void iniSave(char* fileName);

	//문자값
	char* loadDataString(char* fileName, char* section, char* key);
	//정수값
	int loadDataInteger(char* fileName, char* section, char* key);

	INIData();
	~INIData();
};

