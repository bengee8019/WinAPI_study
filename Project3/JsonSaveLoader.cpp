#include "Stdafx.h"
#include "JsonSaveLoader.h"

// UTF-8
// 
HRESULT JsonSaveLoader::init(void)
{
	//Ȯ��� ���
	return S_OK;
}

void JsonSaveLoader::release(void)
{
	//Ȯ��� ���
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

	//HANDLE : �����쿡�� �ο��ϴ� ���� �ĺ���ȣ 32��Ʈ ������
	HANDLE file;

	//BOM Byte of Marker
	/*
		����Ʈ ���� ǥ��(BOM)

		�޸� ���� �� byte ������ ������ ����
		����Ʈ ���� ǥ���� ���� �� �տ� ���ڵ� ��Ŀ� ���õ� ���ڸ� �־
		���ڵ� ����� ǥ���Ѵ�.
		�Ϲ����� �����Ϳ����� BOM�� �ν��� �� ���� ��� �����ͷ� ���� ���� �ִ�.

		-�����ڵ��� ��� ���ڵ� ����̳� ����� ��Ŀ� ���� ����Ʈ ���� ǥ���� 
		�ʿ��� ��찡 ���� ����.

		������ UTF-16�� �⺻ ����ϰ� BOM�� 0xFEFF�� ����Ѵ�.
		��Ʋ ����� - 0xFFFE

		UTF-16�� �����ڵ� ����̱� ������ �ѱ��� 2����Ʈ�� ó���Ѵ�.
		�� �޸� �������� ������ ��ų �� �ִ�.(�ѱ��� 1~3����Ʈ�� ó���Ǵ� ��찡 �ֱ� ����)
		�� ���ڰ� �����ų� �ּ��� �����ٸ� ���ڵ� �����̴�.

		�� �����
		�� ��Ű��ó���� ���� �߿��� ����

		�� ������� ǥ���� ���� �� CPU ȸ�縶�� ������ �����ϱ� ������
			ó���ϴ� ����� ����� �ٸ���.
			Intel, AMD -> ��Ʋ ����� ���

		�� ����ȿ� ���� ���ٸ� ó���� ���� �ʾҴٸ� �����ʹ� ���� �ּҿ��� ���� �ּ��� �������� ����.


		- �� �����
		�� ��->�� 
		�޸𸮿� ����� ���� �״�� ���� �� ������ ����� �����ϱⰡ ���� ����.

		- ��Ʋ �����
		�� ��<-��
		�޸𸮿� ����� ���� ���� ����Ʈ�� ����� �� ������ ������ �ʿ���� ��찡 ���� ������
		������ ���� �� ���������� �����ϴ�.




	*/
	WORD BOM = 0xFEFF;
	DWORD dwBytes = 0;
	DWORD dwRead;

	/*
		���� ����� ��ġ�� ����ų� �о���� ����� �� �ִ� �ڵ� ��ȯ

	*/
	file = CreateFile
	(
		fileName,					// �����ϰų� �� ������ �̸�
		GENERIC_WRITE,				// ���� ���� Ÿ�� ������ ����?
		0,							// 0-> �ٸ� ��ü���� ���� X
		NULL,						// ��� ����
		CREATE_ALWAYS,				// ���ο� ���� ���� -> ������ ���� �����ϸ� ����ڴ�.
		FILE_ATTRIBUTE_NORMAL,		// ���Ͽ����� �Ӽ�, NORMAL -> �Ӽ�X
		NULL						// ���¿� ���� ����
	);

	//-1�� ���и� �ǹ��ϴ� ��찡 ����.
	//INVALID_HANDLE_VALUE : �ַ� �ʱ�ȭ�� ���, �Ϲ������� -1�� ���ǵǾ��ִ�.
	if (file == INVALID_HANDLE_VALUE)
	{
		MessageBox(_hWnd, "���� ���� ����", "����", MB_OK);
	}
	else
	{
		//���� �Ϲ����� ����
		//WriteFile(file, &BOM, 2, &dwBytes, NULL);
		//C, C++������ ���� ���� Ȯ�� �ʼ�
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
	//8192: (2^13) Ŭ���̾�Ʈ���� ����ϴ� �ֻ��� ��Ʈ -> ���������� ���� ���۶�� �θ���.
	// ����� -> byte(1~8) / word(2~16) / dword(4~32) / qword(8~64)
	//2byte���� �ֻ��� ��Ʈ

	//1�� �ھ �ּҰ��� �˰� �ִ�.
	TCHAR buf[8192];
	ZeroMemory(buf, sizeof(buf));

	HANDLE file;
	DWORD dwBytes;

	file = CreateFile
	(
		fileName,					// �����ϰų� �� ������ �̸�
		GENERIC_READ,				// �Ϲ����� ���·� �о���̱�
		0,							// 0-> �ٸ� ��ü���� ���� X
		NULL,						// ��� ����
		OPEN_EXISTING,				// ������ �����Ҷ��� ����.
		FILE_ATTRIBUTE_NORMAL,		// ���Ͽ����� �Ӽ�, NORMAL -> �Ӽ�X
		NULL						// ���¿� ���� ����
	);

	if (file == INVALID_HANDLE_VALUE)
	{
		MessageBox(_hWnd, "���� ���� ����", "����", MB_OK);

		return "";
	}
	else
	{
		ReadFile(file, buf, 8192, &dwBytes, NULL);
		CloseHandle(file);
	}

	//������ ����� ���� �Ѵ�.
	//return string(buf);
}

// �ٽ�
string JsonSaveLoader::loadStringWithFileStream(char* fileName)
{
	//stream�� ������ �޸� �����ؼ� CPU ȣ�� -> cpu �����ٸ�, �ִ��� ������ ó���ϰ� �� �ݾƹ����� ����
	ifstream fileIn;
	fileIn.open(fileName, ios::in);

	/*
	ios::in -> ���� ���� (�б� ��������)
	ios::out -> ���� ���� (���� ����)
	ios::ate -> ������ ������ ���� ������ �̵�.(������ ������ ��)
	ios::app -> ������ �߰�(������ ���ʺ���)
	ios::binary -> ���̳ʸ� ���� ����			-	2���� �ڵ�� �ٷ� ����

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
		MessageBox(_hWnd, "�����Ͱ� ����.", "���", MB_OK);
		return NULL;
	}

	Json::Reader reader;
	Json::Value root;

	//parsing: Ư�� ������ �о�鿩�� �̸� Ư�� ���α׷����� ����Ҽ� �ִ� ǥ��������� ��ȯ���ִ� �۾�.
	//parse: �Ľ��� �ϴ� ���μ���
	bool parsingRet = reader.parse(jsonStr, root);



	return Json::Value();
}
