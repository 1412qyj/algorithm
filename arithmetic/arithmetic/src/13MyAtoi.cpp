#include "../include/13MyAtoi.h"

//bool FirstIsSub(const char ch)
//{
//	if (ch == '-')
//		return true;
//	else
//		return false;
//}
//
//bool IsNum(const char ch)
//{
//	if (ch >= 'a' && ch <= 'z' || ch >= 'A' || ch <= 'Z')
//		return true;
//	else
//		return false;
//}

int MyAtoi(string s)
{
	stringstream sstr(s);
	float ret = 0.0f;

	if (sstr >> ret)
	{
		if (ret >= INT_MAX)
		{
			return INT_MAX;
		}

		if (ret <= INT_MIN)
		{
			return INT_MIN;
		}

		return static_cast<int>(ret);
	}
	else
	{
		return 0;
	}


	//int flag = 1;
	//stringstream sstr(s);
	//float ret = 0.0f;

	////�ַ���Ϊ�գ�����0
	//if (s.empty())
	//{
	//	return 0;
	//}

	////�ַ�����һ���Ǹ��ţ����÷���λ
	//if (FirstIsSub(s[0]))
	//{
	//	flag = -1;
	//}
	//else
	//{
	//	//������
	//	if (IsNum(s[0]))
	//	{
	//		sstr >> ret;

	//		if (ret > )
	//	}
	//	else //��������
	//	{
	//		return 0;
	//	}
	//}

	
}