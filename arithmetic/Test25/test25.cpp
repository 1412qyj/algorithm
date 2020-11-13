#include "stdafx.h"
#include "CppUnitTest.h"
#include "../arithmetic/include/25Partition.h"
#include <sstream>
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test25
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test25)
		{
			// TODO:  �ڴ�������Դ���
			char *pIn = new char[MAX_PATH];
			char *pOut = new char[MAX_PATH];

			GetPrivateProfileStringA("test25", "Input", "", pIn, MAX_PATH, INI_PATH);
			GetPrivateProfileStringA("test25", "Output", "", pOut, MAX_PATH, INI_PATH);
			int iKey = GetPrivateProfileIntA("test25", "Key", 0, INI_PATH);

			stringstream sstrIn;
			stringstream sstrOut;
			vector<int> vecIn;
			vector<int> vecOut;
			int tmp;

			sstrIn << pIn;
			sstrOut << pOut;

			while (sstrIn >> tmp)
			{
				vecIn.push_back(tmp);
			}
			while (sstrOut >> tmp)
			{
				vecOut.push_back(tmp);
			}

			//����ͷ�ڵ�
			ListNode *pHead = new ListNode(0);//ͷ�ڵ��������������ܳ���

			//ѭ��ͷ�壬 ��Ϊͷ�����ݻᷴ���������ǽ����ݷ���ͷ��
			vector<int>::reverse_iterator iter;

			for (iter = vecIn.rbegin(); iter != vecIn.rend(); iter++)
			{
				tmp = *iter;
				HeadInsertNode(pHead, *iter);
			}

			ListNode *pRet = Partition(pHead, iKey);

			vector<int> vecRet;

			pHead = pHead->next;
			while (pHead)
			{
				vecRet.push_back(pHead->val);
				pHead = pHead->next;
			}

			bool bResult = (vecRet == vecOut) ? true : false;
			
			Assert::IsTrue(bResult);
		}

	};
}