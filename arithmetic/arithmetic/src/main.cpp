#include <iostream>
#include <Windows.h>

#define DEBUG

#ifdef DEBUG
#include "../include/15WordPattern.h"
#include "../include/5MinDepth.h"
#include "../include/18PlusOne.h"
#include "../include/20MoveZeroes.h"
#include "../include/23RestoreIpAddresses.h"

#endif

using namespace std;

int main()
{

#ifdef DEBUG
	string s("25525511135");

	vector<string> vec = RestoreIpAddresses(s);

	for (vector<string>::iterator iter = vec.begin(); iter != vec.end(); iter++)
		cout << *iter << endl;

#endif

	system("pause");
	return 0;
}