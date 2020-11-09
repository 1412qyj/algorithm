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
			int input = 0;
			LPSTR p_output = new char[MAX_PATH];
			char *p_ret = NULL;

			input = GetPrivateProfileIntA("test2", "input", 0, INI_PATH);
			GetPrivateProfileStringA("test2", "output", "", p_output, MAX_PATH, INI_PATH);
			p_ret = ExcelSheetColumnTitle(input);

			Assert::AreEqual(0, strcmp(p_ret, p_output));

			//free(p_ret);
		}

	};
}