#include "../include/24LengthOfLongestSubstring.h"

#if 1

int LengthOfLongestSubstring(string s)
{
	int max = 0;//����ִ�����
	int tmpmax = 0;//��ǰ�����ִ�����
	int start = 0;//�ִ���ʼ���±�λ��
	int hashmap[128] = {0};//�ַ�����ϣ��asciiһ��128����
	int i = 0;//ѭ���±�

	for (i = 0; i < s.size(); i++)
	{
		if (hashmap[s[i]] > start)//�����ϣ������ֵ��start�󣬼������ظ��ַ���
		{
			tmpmax = i - start;//��ȡ��ǰ���ִ�����

			max = (tmpmax > max) ? tmpmax : max;//�����ܵ��ִ�����

			start = hashmap[s[i]];//����ʼλ��start��ֵ���óɲ����ڵ�ǰ�ַ�������λ��
		}

		hashmap[s[i]] = i + 1;//�����ϣ���е�������ֵ��startС����ʼ��Ϊ0�����û��¼����϶���startС��
							  //�������ַ�����λ�õ���һ��λ�ã����ظ��ַ����ֺ����startλ��
	}

	tmpmax = i - start;

	return (tmpmax > max ? tmpmax : max);

}

#else

int LengthOfLongestSubstring(string s)
{
	int curMax = 1;
	int Max = 1;
	vector<char> vecCur;

	for (int i = 0; i < s.size(); i++)
	{
		vecCur.push_back(s[i]);
		for (int j = i + 1; j < s.size(); j++)
		{
			//�����е�����ִ����ҵ�ǰ���ַ�
			if (find(vecCur.begin(), vecCur.end(), s[j]) == vecCur.end())
			{
				vecCur.push_back(s[j]);
				curMax++;
				continue;
			}

			Max = (curMax > Max) ? curMax : Max;
			
			curMax = 0;
			vecCur.clear();
		}
	}

	return Max;
}

#endif