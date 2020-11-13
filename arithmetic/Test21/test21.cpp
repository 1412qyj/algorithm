#include "stdafx.h"
#include "CppUnitTest.h"
#include "../arithmetic/include/21Reverse.h"
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test21
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test21)
		{
			// TODO:  �ڴ�������Դ���
			int i_in = GetPrivateProfileIntA("test21", "Input", 0, INI_PATH);
			int i_out = GetPrivateProfileIntA("test21", "Output", 0, INI_PATH);

			Assert::AreEqual(i_out, Reverse(i_in));

			i_in = GetPrivateProfileIntA("test21", "Input1", 0, INI_PATH);
			i_out = GetPrivateProfileIntA("test21", "Output1", 0, INI_PATH);

			Assert::AreEqual(i_out, Reverse(i_in));
		}

	};
}