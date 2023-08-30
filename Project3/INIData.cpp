#include "Stdafx.h"
#include "INIData.h"

HRESULT INIData::init(void)
{
	return S_OK;
}

void INIData::release(void)
{
	//! Do Nothing
}

void INIData::addData(char* section, char* key, char* value)
{
	tagIniData iniData;
	iniData.section = section;
	iniData.key = key;
	iniData.value = value;

	arrIniData vIniData;
	vIniData.push_back(iniData);
	
	_vIniData.push_back(vIniData);

}

void INIData::iniSave(char* fileName)
{
	char str[256];
	char dir[256];

	ZeroMemory(str, sizeof(str));
	ZeroMemory(dir, sizeof(dir));

	sprintf(dir, "\\INIData/%s.ini", fileName);
	GetCurrentDirectory(256, str);

	strcat(str, dir);

	for (int i = 0; i < _vIniData.size(); i++)
	{
		arrIniData vData = _vIniData[i];

		//어떤 파일을 쓸지 분기점, 읽어올 방식 결정
		//WritePrivateProfileString(): 파일에 정보를 쓰며 만약에 해당 섹션과 키값이 없으면 자동으로 생성을 한다.
		WritePrivateProfileString
		(
			vData[0].section,
			vData[0].key,
			vData[0].value,
			str
		);

		vData.clear();
	}

	_vIniData.clear();
}

char* INIData::loadDataString(char* fileName, char* section, char* key)
{
	char str[256];
	char dir[256];

	ZeroMemory(str, sizeof(str));
	ZeroMemory(dir, sizeof(dir));

	sprintf(dir, "\\INIData/%s.ini", fileName);
	GetCurrentDirectory(256, str);
	strcat_s(str, dir);

	char data[64] = { NULL };

	//파일 읽기
	GetPrivateProfileString
	(
		section,			//읽어올 벨류의 섹션 이름
		key,				//읽어올 벨류의 이름
		"",					//섹션 이름이나 키 이름을 찾지 못하면 출력할 문자열
		data,				//키값에서 가리키는 값을 저장할 버퍼
		64,					//버퍼의 크기
		str					
	);


	return data;
}

int INIData::loadDataInteger(char* fileName, char* section, char* key)
{
	char str[256];
	char dir[256];

	ZeroMemory(str, sizeof(str));
	ZeroMemory(dir, sizeof(dir));

	sprintf(dir, "\\INIData/%s.ini", fileName);
	GetCurrentDirectory(256, str);
	strcat_s(str, dir);

	return GetPrivateProfileInt(section, key, 0, str);
}

INIData::INIData()
{
}

INIData::~INIData()
{
}
