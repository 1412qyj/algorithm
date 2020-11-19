#include "../include/13MyAtoi.h"


int MyAtoi(string s)
{
	stringstream sstr(s);
	long long ret = 0;

	if (sstr >> ret)
	{
		if (ret > INT_MAX)
		{
			return INT_MAX;
		}

		if (ret < INT_MIN)
		{
			return INT_MIN;
		}

		return static_cast<int>(ret);
	}
	else
	{
		return 0;
	}
}