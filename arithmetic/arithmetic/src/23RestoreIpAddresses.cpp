#include "../include/23RestoreIpAddresses.h"

//ģ�麯���������������
static vector<string> ret;

vector<string> RestoreIpAddresses(string s)
{
	string cur = s;
	int size = s.size();

	Handle(size, 0, -1, cur ,s);

	return ret;
}

//����ip��ַ�ַ�������
void Handle(int size, int pointNum, int lastPointPlace, string &cur, string &ori)
{
	//�Ѿ�������������
	if (pointNum == 3)
	{
		//�ж����һ����ֵ�Ƿ�����ȷ��
		if (isValid(lastPointPlace + 1, size - 1, ori))
			ret.push_back(cur);//�ӵ�����������

		return;
	}

	//Ѱ�Ҵ���λ�ã���һ����ĺ���λ�õ�����ĩβǰһ��λ�ÿ��Դ��
	for (int i = lastPointPlace + 1; i < size-1; i++)
	{
		if (isValid(lastPointPlace + 1, i, ori))
		{
			//��cur�в���.,Ҫ���ϵ������
			cur.insert(cur.begin() + i + pointNum + 1, '.');
			Handle(size, pointNum+1, i, cur, ori);

			//���˲���֮ǰ
			cur.erase(i + pointNum + 1, 1);
		}
	}

	return;
}

//�жϴ������Ƿ����Ҫ��
bool isValid(int firstPlace, int lastPlace, string &s)
{
	int sum = 0;

	for (int i = firstPlace; i <= lastPlace; i++)
	{
		//�����еķ�һλ����һλ��0ʱ
		if (s[firstPlace] == '0' && firstPlace != lastPlace)
			return false;

		sum = sum * 10 + s[i] - '0';
	}

	if (sum > 255)
		return false;

	return true;
}