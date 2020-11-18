#include "../include/12IsValid.h"

bool IsValid(string s)
{
	stack<char> stack;//����һ��ջ
	
	if (s.size() % 2 != 0)//���ջ��ֵ����2�ı�����ֱ�ӷ���false
		return false;

	if (s == "")//����ǿ��ַ���������true
		return true;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
		{
			stack.push(')');
		}

		else if (s[i] == '{')
		{
			stack.push('}');
		}

		else if (s[i] == '[')//ǰ����if��������ŵĻ�������ѹջ��Ӧ���з���
		{
			stack.push(']');
		}

		else if (!stack.empty())//��Ϊ��
		{
			if (s[i] == stack.top())//�����ǰ�ַ���ջ��Ԫ����ͬ���ͳ�ջ
			{
				stack.pop();
			}
			else
			{
				return false;//��Ȼ���Ǵ���ģ�false
			}
		}

		else if (stack.empty())//����ַ�����û������ջ�Ѿ����ˣ�˵�����Ҹ������Գƣ�false
		{
			return false;
		}
	}

	return stack.empty();//string���������stackû������false����֮true
}