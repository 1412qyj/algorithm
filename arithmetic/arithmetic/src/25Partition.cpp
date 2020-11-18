#include "../include/25Partition.h"

void HeadInsertNode(ListNode *pHead, int val)
{
	ListNode *pNode = new ListNode(val);

	if (pHead->next == NULL)
	{
		pHead->next = pNode;
		pHead->val++;
		return;
	}

	pNode->next = pHead->next;
	pHead->next = pNode;

	pHead->val++;

	return;
}


//���ǳƵ�һ�����ڵ���x�Ľڵ�Ϊ��׼�ڵ�
ListNode* Partition(ListNode* head, int x)
{
	ListNode *pMov = NULL;//�ƶ�ָ��
	ListNode *pDel = NULL;//ɾ���ڵ�ָ�룬ʼ�ձ������ƶ�ָ��֮ǰ
	ListNode *pMod = NULL;//�����׼�ڵ�ǰһ��λ�õĵ�ַ��ָ��
	ListNode *pTmp = NULL;
	bool flag = true;

	pMov = head->next;
	while (pMov)
	{
		if (flag)
		{
			//��ifֻλ�ҵ���׼�ڵ��ǰһ��λ��
			if (pMov->val < x)
			{
				//�ƶ�ָ���ƶ�
				pMod = pMov;
				pMov = pMov->next;
				continue;
			}
			else//���else ifֻ�ᱻִ��һ��
			{
				flag = false;//��flag��0���������жϵ�����ͽ�����
				//��ʱpModָ���׼�ڵ��ǰһ��λ�ã�pMov�ڻ�׼�ڵ�

				//���￪ʼʹ��pDelָ��
				pDel = pMov;

				//�ƶ�pMov���µĿ�ʼ
				pMov = pMov->next;
				continue;
			}
		}

		//�ж����С��x���Ϳ�ʼ����ǰ���ƶ�����
		if (pMov->val < x)
		{
			//step1��ȡ�������ǰ��ָ��
			pTmp = pMov;
			pMov = pTmp->next;

			pTmp->next = NULL;//�Ͽ�������

			pDel->next = pMov;//�Ͽ�ǰ����

			//���뵽pMob����
			pTmp->next = pMod->next;
			pMod->next = pTmp;//������ǰ���ƶ��������

			//����pMod
			pMod = pMod->next;

			pTmp = NULL;
			continue;
		}

		pDel = pMov;
		//�ƶ�ָ���ƶ�
		pMov = pMov->next;
	}


	return head;
}