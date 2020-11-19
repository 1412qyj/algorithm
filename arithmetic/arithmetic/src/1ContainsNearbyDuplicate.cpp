#include "../include/1ContainsNearbyDuplicate.h"

#if 1

bool ContainsNearbyDuplicate(vector<int>& nums, int k)
{
	unordered_map<int, int> hashmap;//�������������ֵ��������±�

	for (int i = 0; i < nums.size(); i++)
	{ 
		if (hashmap.count(nums[i]) == 0)//����Ҳ����������˵���ǵ�һ�����������
		{
			hashmap.insert(pair<int, int>(nums[i], i));
		}
		else //�ҵ���ͬ����
		{
			if (i - hashmap[nums[i]] > k)//˵�������㣬����nums[i]����ֵ
			{
				hashmap[nums[i]] = i;
			}
			else
			{
				return true;
			}
		}

	}
	
	return false;
}

#else

bool ContainsNearbyDuplicate(int* nums, int numsSize, int k)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < numsSize; i++)
	{
		for(j = i+1; j <= MIN(numsSize-1, i+k); j++)
		{
			if (nums[j] == nums[i])
			{
				return true;
			}
		}
		
	}

	return false;
}

#endif