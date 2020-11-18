#include "../include/20MoveZeroes.h"

#if 1

void MoveZeroes(vector<int> &nums)
{
	//�ָ��㷨�����������arg�����ᱻ�Ƶ�ǰ��ȥ���ұ���ԭ��λ�ò���
	stable_partition(nums.begin(), nums.end(), [](int num){return num != 0;});
}

#else

//˫ָ��
//ֻ�ƶ���0����
void MoveZeroes(vector<int>& nums)
{
	if (nums.size() == 0)
		return;

	int tmp;
	int p = 0;//pָ����Զָ��0Ԫ��
	int size = nums.size();

	for(int i = 0; i < size; i++)//pָ��û����0ʱ��l����һ�£������������l
	{//iָ����������
		if(nums[i] != 0)
		{
			tmp = nums[i];
			nums[i] = nums[p];
			nums[p++] = tmp;
		}
	}

	return;
}

#endif