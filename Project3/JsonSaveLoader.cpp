#include "Stdafx.h"
#include "JsonSaveLoader.h"

// UTF-8
// 
HRESULT JsonSaveLoader::init(void)
{
	//확장시 사용
	return S_OK;
}

void JsonSaveLoader::release(void)
{
	//확장시 사용
}


JsonSaveLoader::JsonSaveLoader()
{
}

JsonSaveLoader::~JsonSaveLoader()
{
}

void JsonSaveLoader::saveString(char* fileName, string data)
{
	TCHAR* buf = (TCHAR*)data.c_str();

	//HANDLE : 윈도우에서 부여하는 고유 식별번호 32비트 정수값
	HANDLE file;

	//BOM Byte of Marker
	/*
		바이트 순서 표식(BOM)

		메모리 저장 시 byte 단위로 나눠서 저장
		바이트 순서 표식은 문서 맨 앞에 인코딩 방식에 관련된 문자를 넣어서
		인코딩 방식을 표현한다.
		일반적인 에디터에서는 BOM을 인식할 수 없고 헥사 에디터로 봐야 볼수 있다.

		-유니코드의 경우 인코딩 방법이나 엔디안 방식에 따라 바이트 순서 표식이 
		필요한 경우가 아주 많다.

		윈도우 UTF-16을 기본 사용하고 BOM은 0xFEFF를 사용한다.
		리틀 엔디안 - 0xFFFE

		UTF-16은 유니코드 기반이기 때문에 한글을 2바이트로 처리한다.
		ㄴ 메모리 이점으로 연결을 시킬 수 있다.(한글은 1~3바이트로 처리되는 경우가 있기 때문)
		ㄴ 글자가 깨지거나 주석이 깨진다면 인코딩 문제이다.

		▶ 엔디안
		ㄴ 아키텍처에서 아주 중요한 개념

		ㄴ 엔디안은 표준이 없을 때 CPU 회사마다 각각의 정의하기 때문에
			처리하는 엔디안 방식이 다르다.
			Intel, AMD -> 리틀 엔디안 사용

		ㄴ 엔디안에 대한 별다른 처리를 하지 않았다면 데이터는 낮은 주소에서 높은 주소의 방향으로 저장.


		- 빅 엔디안
		ㄴ 좌->우 
		메모리에 저장된 순서 그대로 읽을 수 있으며 사람이 이해하기가 비교적 쉽다.

		- 리틀 엔디안
		ㄴ 좌<-우
		메모리에 저장된 값의 하위 바이트만 사용할 때 별도의 로직이 필요없는 경우가 많기 때문에
		연산이 많을 때 수학적으로 유리하다.




	*/
	WORD BOM = 0xFEFF;
	DWORD dwBytes = 0;
	DWORD dwRead;

	/*
		파일 입출력 장치를 만들거나 읽어오고 사용할 수 있는 핸들 반환

	*/
	file = CreateFile
	(
		fileName,					// 생성하거나 열 파일의 이름
		GENERIC_WRITE,				// 파일 접근 타입 읽을지 쓸지?
		0,							// 0-> 다른 객체에게 공유 X
		NULL,						// 상속 여부
		CREATE_ALWAYS,				// 새로운 파일 생성 -> 동일한 파일 존재하면 덮어쓰겠다.
		FILE_ATTRIBUTE_NORMAL,		// 파일에대한 속성, NORMAL -> 속성X
		NULL						// 형태에 대한 정의
	);

	//-1은 실패를 의미하는 경우가 많다.
	//INVALID_HANDLE_VALUE : 주로 초기화에 사용, 일반적으로 -1로 정의되어있다.
	if (file == INVALID_HANDLE_VALUE)
	{
		MessageBox(_hWnd, "생성 파일 에러", "에러", MB_OK);
	}
	else
	{
		//가장 일반적인 형태
		//WriteFile(file, &BOM, 2, &dwBytes, NULL);
		//C, C++에서는 버퍼 길이 확인 필수
		WriteFile(file, buf, strlen(buf)* sizeof(TCHAR), &dwRead, NULL);
		CloseHandle(file);
	}
}

void JsonSaveLoader::saveStringWithFileStream(char* fileName, string data)
{
	ofstream outFile(fileName);

	outFile << data << endl;

	outFile.close();

}

string JsonSaveLoader::loadString(char* fileName)
{
	//8192: (2^13) 클라이언트에서 사용하는 최상위 비트 -> 서버에서는 소켓 버퍼라고 부른다.
	// 어셈블러 -> byte(1~8) / word(2~16) / dword(4~32) / qword(8~64)
	//2byte에서 최상위 비트

	//1번 코어만 주소값을 알고 있다.
	TCHAR buf[8192];
	ZeroMemory(buf, sizeof(buf));

	HANDLE file;
	DWORD dwBytes;

	file = CreateFile
	(
		fileName,					// 생성하거나 열 파일의 이름
		GENERIC_READ,				// 일반적인 형태로 읽어들이기
		0,							// 0-> 다른 객체에게 공유 X
		NULL,						// 상속 여부
		OPEN_EXISTING,				// 파일이 존재할때만 연다.
		FILE_ATTRIBUTE_NORMAL,		// 파일에대한 속성, NORMAL -> 속성X
		NULL						// 형태에 대한 정의
	);

	if (file == INVALID_HANDLE_VALUE)
	{
		MessageBox(_hWnd, "생성 파일 에러", "에러", MB_OK);

		return "";
	}
	else
	{
		ReadFile(file, buf, 8192, &dwBytes, NULL);
		CloseHandle(file);
	}

	//공백을 고려해 봐야 한다.
	//return string(buf);
}

// 핵심
string JsonSaveLoader::loadStringWithFileStream(char* fileName)
{
	//stream이 열리고 메모리 접근해서 CPU 호출 -> cpu 스케줄링, 최대한 빠르게 처리하고 문 닫아버리기 위해
	ifstream fileIn;
	fileIn.open(fileName, ios::in);

	/*
	ios::in -> 파일 개방 (읽기 전용으로)
	ios::out -> 파일 개방 (쓰기 전용)
	ios::ate -> 파일의 끝으로 파일 포인터 이동.(파일을 개방할 때)
	ios::app -> 데이터 추가(파일의 뒤쪽부터)
	ios::binary -> 바이너리 모드로 개방			-	2진수 코드로 바로 접근

	*/

	char data;
	string jsonStr;
	while (fileIn.get(data))
	{
		jsonStr += data;
	}

	fileIn.close();

	return jsonStr;
}


void JsonSaveLoader::saveJsonFile(char* fileName, Json::Value root)
{
	Json::StyledWriter writer;
	string outputConfig = writer.write(root);

	saveStringWithFileStream(fileName, outputConfig);
}

Json::Value JsonSaveLoader::loadJsonFile(char* fileName)
{
	string jsonStr = loadStringWithFileStream(fileName);

	if (jsonStr == "")
	{
		MessageBox(_hWnd, "데이터가 없다.", "경고", MB_OK);
		return NULL;
	}

	Json::Reader reader;
	Json::Value root;

	//parsing: 특정 문서를 읽어들여서 이를 특정 프로그램에서 사용할수 있는 표현방식으로 변환해주는 작업.
	//parse: 파싱을 하는 프로세서
	bool parsingRet = reader.parse(jsonStr, root);



	return Json::Value();
}
