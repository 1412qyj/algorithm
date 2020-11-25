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
	auto q = head;
	auto p = head;
	int tmp;

	while (q)
	{
		if (q->val < x)
		{
			tmp = q->val;
			q->val = p->val;
			p->val = tmp;

			p = p->next;
		}

		q = q->next;
	}

	return head;

}