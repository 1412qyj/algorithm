#include "stdafx.h"
#include "CppUnitTest.h"
#include "../arithmetic/include/4IsPalindrome.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test4
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test4)
		{
			// TODO:  �ڴ�������Դ���
			int input = GetPrivateProfileIntA("test4", "Input", 0, INI_PATH);

			LPSTR p_output = new char[5];

			GetPrivateProfileStringA("test4", "Output", "", p_output, 5, INI_PATH);

			bool flag = (strncmp(p_output, "true", 4) == 0) ? true : false;

			Assert::AreEqual(flag, IsPalindrome(input));


		}

	};
}