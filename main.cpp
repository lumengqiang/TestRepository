#include <iostream>

#include "python.h"

using namespace std;

int main()
{
	PyObject* pModule = ABC;//��������
	PyObject* pFunc = DEF;// ��������
	Py_Initialize();//ʹ��python֮ǰ��Ҫ����Py_Initialize();����������г�ʼ��

	if (!Py_IsInitialized())

	{
		printf("��ʼ��ʧ�ܣ�");

		return 0;

	}

	PyRun_SimpleString("import sys");

	PyRun_SimpleString("sys.path.append('./Debug')");//��һ������Ҫ���޸�Python·��
	//PyRun_SimpleString("f=open('D:\learn\VS2015\test/abc.py','r',encoding='utf8')");//��һ������Ҫ���޸�Python·��

	

	PyObject* pModule = NULL;//��������

	PyObject* pFunc = NULL;// ��������

	pModule = PyImport_ImportModule("pythonTest");//������Ҫ���õ��ļ���hash_hmac.py

	if (pModule == NULL)

	{
		cout << "û�ҵ�" << endl;

	}

	pFunc = PyObject_GetAttrString(pModule, "hash_hmac");//������Ҫ���õĺ�����

														 //�����ַ�������

	PyObject* pParams = Py_BuildValue("ss", "100", "200");

	char* result;

	PyObject* pRet = PyObject_CallObject(pFunc, pParams);//���ú���

	int res = 0;

	PyArg_Parse(pRet, "s", &result);//ת����������

	cout << "res:" << result << endl;//������

	Py_Finalize();//����Py_Finalize�������Py_Initialize���Ӧ�ġ�

	return 0;

}
