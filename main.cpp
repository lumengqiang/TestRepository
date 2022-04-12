#include <iostream>

#include "python.h"

using namespace std;

int main()
{
	PyObject* pModule = ABC;//声明变量
	Py_Initialize();//使用python之前，要调用Py_Initialize();这个函数进行初始化

	if (!Py_IsInitialized())

	{
		printf("初始化失败！");

		return 0;

	}

	PyRun_SimpleString("import sys");

	PyRun_SimpleString("sys.path.append('./Debug')");//这一步很重要，修改Python路径
	//PyRun_SimpleString("f=open('D:\learn\VS2015\test/abc.py','r',encoding='utf8')");//这一步很重要，修改Python路径

	

	PyObject* pModule = NULL;//声明变量

	PyObject* pFunc = NULL;// 声明变量

	pModule = PyImport_ImportModule("pythonTest");//这里是要调用的文件名hash_hmac.py

	if (pModule == NULL)

	{
		cout << "没找到" << endl;

	}

	pFunc = PyObject_GetAttrString(pModule, "hash_hmac");//这里是要调用的函数名

														 //两个字符串参数

	PyObject* pParams = Py_BuildValue("ss", "100", "200");

	char* result;

	PyObject* pRet = PyObject_CallObject(pFunc, pParams);//调用函数

	int res = 0;

	PyArg_Parse(pRet, "s", &result);//转换返回类型

	cout << "res:" << result << endl;//输出结果

	Py_Finalize();//调用Py_Finalize，这个根Py_Initialize相对应的。

	return 0;

}