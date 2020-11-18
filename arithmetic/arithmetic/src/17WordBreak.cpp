#include "../include/17WordBreak.h"

#if 1
bool WordBreak(string s, vector<string>& wordDict)
{
	if (find(wordDict.begin(), wordDict.end(), s) != wordDict.end())
		return true;


	for(int i = 1; i < s.size(); i++)
	{
		if (find(wordDict.begin(), wordDict.end(), s.substr(0, i)) != wordDict.end())
		{
			if (WordBreak(s.substr(i), wordDict))//���ʣ���Ӵ�Ҳ�ҵ�����
				return true;
		}
	}
	
	return false;
}

#else
bool WordBreak(string s, vector<string>& wordDict)
{
	int l = 0;//��pos
	int r = 1;//��pos
	
	while (!s.empty())
	{
		//��ʱ�ҵ���r��������ʵĺ�һ��λ��
		if (find(wordDict.begin(), wordDict.end(), s.substr(l, r)) != wordDict.end())
		{
			//�ҵ��Ͳ���
			s.erase(0, r);
			r = 1;
			continue;
		}

		if (r == s.size())
			break;

		r++;
	}

	return s.empty();
}

#endif