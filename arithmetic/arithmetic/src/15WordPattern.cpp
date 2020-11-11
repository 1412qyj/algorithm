#include "../include/15WordPattern.h"

bool WordPattern(string pattern, string s)
{
	//���жϸ���
	int pos = 0;
	int count = 0;

	while (pos < s.size())
	{
		pos = s.find(' ', pos);
		if (pos == -1)
			break;

		pos++;
		count++;
	}

	//����ַ��������͸�����ʽ�ĸ�����ֱͬ�ӷ���false
	if (++count != pattern.size())
		return false;

	//���s
	stringstream sstr_s(s);
	string str_tmp;
	vector<string> vec_s;

	while (sstr_s >> str_tmp)
	{
		vec_s.push_back(str_tmp);
		str_tmp.clear();
	}

	//�ҵ�a��b��ģ��
	string str_temple_a = vec_s[pattern.find('a')];
	string str_temple_b = vec_s[pattern.find('b')];

	pos = 0;
	//����pattern
	while (pos < count)
	{
		//�����a��
		if (pattern[pos] == 'a')
		{
			//��aģ��Ƚ�
			if (str_temple_a != vec_s[pos])
				return false;
		}

		if (pattern[pos] == 'b')
		{
			//��bģ��Ƚ�
			if (str_temple_b != vec_s[pos])
				return false;
		}

		pos++;
	}

	return true;
}