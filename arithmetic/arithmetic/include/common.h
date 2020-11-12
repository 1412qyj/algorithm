#ifndef __COMMON_H
#define __COMMON_H

//c
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <math.h>
#include <stdint.h>

#include <stdbool.h>

//c++
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <limits.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

//define
#define INI_PATH "..\\arithmetic\\config\\config.ini"


#ifdef __cplusplus
extern "C"
{
#endif
	//common func
	char * GetLanguage();
	char * GetAuthor();

#ifdef __cplusplus
}
#endif

#endif