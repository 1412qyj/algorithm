#include "stdafx.h"
#include "CppUnitTest.h"
#include "../arithmetic/include/2ExcelSheetColumnTitle.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test2
{		
	TEST_CLASS(UnitTest2)
	{
	public:
		
		TEST_METHOD(Test2)
		{
			// TODO:  �ڴ�������Դ���
			//����һ
			int input = 0;
			LPSTR p_output = new char[MAX_PATH];
			string strRet;

			input = GetPrivateProfileIntA("test2", "input", 0, INI_PATH);
			GetPrivateProfileStringA("test2", "output", "", p_output, MAX_PATH, INI_PATH);
			strRet = ExcelSheetColumnTitle(input);

			Assert::AreEqual(0, strcmp(strRet.c_str(), p_output));
			

			//���Զ�
			strRet.clear();
			LPSTR p_output1 = new char[MAX_PATH];

			int input1 = GetPrivateProfileIntA("test2", "Input1", 0, INI_PATH);
			GetPrivateProfileStringA("test2", "Output1", "", p_output1, MAX_PATH, INI_PATH);
			strRet = ExcelSheetColumnTitle(input1);

			Assert::AreEqual(0, strcmp(strRet.c_str(), p_output1));

			//free(p_ret);
		}

	};
}