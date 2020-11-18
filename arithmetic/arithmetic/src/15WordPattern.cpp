#include "../include/15WordPattern.h"

#if 0
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
#else
bool WordPattern(string pattern, string s)
{
	unordered_map<char, string> map;
	unordered_map<string, char> rmap;//����һ��pattern��Ӧ�������ʱ����ִ��󣬷�����һ��map
									 //��֤pattern�͵�������һһ��Ӧ
	stringstream sstr(s);
	string str;

	for (char c : pattern)
	{
		//���ַ���false�����
		//sstr >> s �������0��˵��pattern�ĸ�����s��Ԫ�ظ�����һ�£�����false
		//���map����c�������c����ֵ����s������false
		if (!(sstr >> s) || (map.count(c) == 1 && map[c] != s) || (rmap.count(s) == 1 && rmap[s] != c) )
			return false;

		//��map����Ӽ�ֵ
		map[c] = s;
		rmap[s] = c;
	}
	
	//������pattern��������������֤�Ƿ�sҲΪ��
	return (sstr >> str) ? false : true;
}


#endif