#pragma once
#include "SingletonBase.h"

#pragma region ���̽�(JSON)
/*
�� ���̽� Java Script Object N

- ��ü�� ������ �Ӽ��� �ؽ�Ʈ �������� �����ϱ� ���� ��ȵ� �����̸� ������ ��ȯ�� ǥ��
	�� �ڹ� ��ũ��Ʈ ��� ǥ�� ǥ��������� �پ��� �� �����ϱ� ������ Ȯ�强�� ����.
	�� �ַ� ���ͳݿ��� �����͸� �ְ� ���� �� �ڷḦ ǥ���ϴ� ������� ���� Ȱ��ȴ�.
	�� �ؽ�Ʈ �����̱� ������ ������Ե� ���� ���� ����.
		�� ���ڿ� ����̱� ������ ������� ����

- ���̽��� �ڷ��� ������ ū ������ ������ Ư�� ��ǻ�� �������� ǥ���ϴµ� �����ϴ�.
0 0 0 0 0 0 0 0 
��Ʈ���� ������!

- ���� ��ü�� �ڹ� ��ũ��Ʈ�� ���� ������ �������� ���α׷��� �� "�÷���"�� �������̹Ƿ�
	C, C++, C#, �ڹ�, �ڹ� ��ũ��Ʈ, ��, ���̽� ��� ���� ���� �̿��� �� �ִ�.

- CSV, XML, HTML -> JSON "�Ϲ����� ��Ȳ������ ������."
�� �������� ���İ� ������ ����ϸ� ���̽��� XML�̶�� ��ũ�� ���� �׻� ����� �ϰ� �Ѵ�.

	�޸𸮸� ì�ܾ� �ϰ� ��Ż�Ȳ - XML, HTML
	
	�޸𸮿� ������� �ӵ��� ì��ڴ� -> JSON
	
	CSV�� ���� Ȯ���غ���.

- ���̽� ���Ŀ��� ����ϴ� ��ȣ

{}: ��ü
Ű: ��: ��ü�� ������ �Ӽ�
"": ���ڿ� ������
[]: �迭


- C++ -> ���̽� -> JsonCPP / Rapid Json
�� �ӵ��� Rapid Json�� �����ϴ�.
�� �޸� ��뷮�� JsonCPP�� �����ϴ�.

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

