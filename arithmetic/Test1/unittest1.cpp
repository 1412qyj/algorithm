#include "stdafx.h"
#include "CppUnitTest.h"
#include "../arithmetic/include/1ContainsNearbyDuplicate.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO:  �ڴ�������Դ���
			LPSTR p_array = new char[MAX_PATH];
			LPSTR p_key = new char[MAX_PATH];
			LPSTR p_output = new char[MAX_PATH];
			int p_nums[MAX_PATH];
			string str;
			char tmp[10];
			int i = 0;
			int cout = 0;

			GetPrivateProfileStringA("test1", "Array", "", p_array, MAX_PATH, INI_PATH);
			GetPrivateProfileStringA("test1", "Key", "", p_key, MAX_PATH, INI_PATH);
			GetPrivateProfileStringA("test1", "Output", "", p_output, MAX_PATH, INI_PATH);

			
			istringstream sstr(p_array);

			//char *nums-> int* nums
			//get nums in Array
			
			while (sstr >> tmp)
			{
				p_nums[i] = atoi(tmp);
				cout++;
				i++;
			}

			//test
			if (!strncmp(p_output, "true", 4))
			{
				Assert::IsTrue(ContainsNearbyDuplicate(p_nums, cout, atoi(p_key)));
			}
			else
			{
				Assert::IsFalse(ContainsNearbyDuplicate(p_nums, cout, atoi(p_key)));
			}


		}
	};
}