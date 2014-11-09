#define _WIN32_WINNT 0x0501

#include <windows.h>
#include <stdio.h>
#include <winuser.h>
#include <string>
#include <iostream>
#include <sstream>  // Required for stringstreams
#include <d3dx9.h>
#include <d3dx9tex.h>

#include <ole2.h>
#include <olectl.h>

typedef struct Square
{
	int red;
	int green;
	int blue;
} Square;

#include "bitmaps.h"

#include "arms.h"
#include "ret.h"
#include "frost.h"

using std::string;
using namespace std;

