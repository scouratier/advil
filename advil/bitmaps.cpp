#include "common.h"

#define KEY1VAL 230
#define KEY2VAL 244
#define KEY3VAL 225
#define N_SQUARES 3

Bitmaps::Bitmaps()
{
	
}

Bitmaps::Bitmaps(HWND hwnd)
{
	this->_height = 1;
	this->_width = 96;
	this->_active_windowDC = GetDC(hwnd);
	this->_captureDC = CreateCompatibleDC(this->_active_windowDC);
	this->_hwnd = hwnd;

	//this->_bmi = {0};
	this->_bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	this->_bmi.bmiHeader.biPlanes = 1;
	this->_bmi.bmiHeader.biBitCount = 32;
	this->_bmi.bmiHeader.biWidth = this->_width;
	this->_bmi.bmiHeader.biHeight = -this->_height;
	this->_bmi.bmiHeader.biCompression = BI_RGB;
	this->_bmi.bmiHeader.biSizeImage = 0;

	this->_new_bitmap = CreateDIBSection(this->_captureDC, &this->_bmi, DIB_RGB_COLORS, (VOID **)&this->_data, NULL, 0);
	HBITMAP old = (HBITMAP )SelectObject(this->_captureDC, this->_new_bitmap);
	BitBlt(this->_captureDC, 0, 0, this->_width, this->_height, this->_active_windowDC, 0, 0, SRCCOPY);
	SelectObject(this->_captureDC, old);
	this->_n_squares = 4;

	GetWindowThreadProcessId(hwnd, &this->_id);
}

Bitmaps::~Bitmaps()
{
	this->Release(this->_hwnd);
	//delete(this->_data);
}

int Bitmaps::GetSquareSize()
{
	int i = 0;
	int r;
	int b;
	int g;
	r = b = g = -1;

	while(i<this->_width*4)
	{
		r = this->_data[i+2];
		b = this->_data[i+1];
		g = this->_data[i];
		//printf("Square Size: R:%d G:%d B:%d\n",r,g,b);
		if (r == 230 && b == 244 && g == 225)
		{
			i = i + 4;
		}
		else
		{
			this->_squareSize = i/4;
			return (i/4);
		}
	}
	return -1;
}

int Bitmaps::ReadData()
{
	this->GetSquareSize();
	int start = this->_squareSize / 2;

	if (!ReadKey())
	{
		printf("invalid key\n");
		return 0;
	}
	ReadOne();

	int i = start*4;
	int a;
	int r;
	int b;
	int g;
	r = b = g = -1;
	for(a=0;a<this->_n_squares;a++)
	{
		r = this->_data[i+2];
		g = this->_data[i+1];
		b = this->_data[i];
		//printf("Read data = R:%d G:%d B:%d\n",r,g,b);
		i = i + this->_squareSize *4;
	}
	return a;
}

void Bitmaps::Release(HWND hwnd)
{
	ReleaseDC(hwnd, this->_active_windowDC);
	DeleteDC(this->_captureDC);
	DeleteObject(this->_new_bitmap);
}

int Bitmaps::ReadKey()
{
	int offset = 0;
	int key1, key2, key3;
	key1 = key2 = key3 = -1;
	key1 = this->GetRed(offset);
	key2 = this->GetGreen(offset);
	key3 = this->GetBlue(offset);
	//printf("Key data = R:%d G:%d B:%d\n",key1,key2,key3);
	if (key1 == KEY1VAL && key2 == KEY2VAL && key3 == KEY3VAL)
	{
		return 1;
	}
	return 0;
}

int Bitmaps::ReadOne()
{
	int offset;
	offset = 1;
	this->_spec = GetSpec();
	this->_combat = GetCombat();
	this->_follow = GetFollow();
	this->_forceFollow = GetForceFollow();
	this->_casting = GetCasting();
	//printf("Spec: %d\n",this->_spec);
	//printf("Combat: %d\n",this->_combat);
	//printf("Follow: %d\n",this->_follow);
	//printf("ForceFollow: %d\n",this->_forceFollow);
	//printf("Casting: %d\n",this->_casting);
	return 1;
}

int Bitmaps::GetRed(int offset)
{
	int i;
	i = offset * this->_squareSize * 4 + 4;
	return this->_data[i+2];
}

int Bitmaps::GetGreen(int offset)
{
	int i;
	i = offset * this->_squareSize * 4 + 4;
	return this->_data[i+1];
}

int Bitmaps::GetBlue(int offset)
{
	int i;
	i = offset * this->_squareSize * 4 + 4;
	return this->_data[i];
}

int Bitmaps::GetSpec()
{
	int offset = 1;
	return this->GetRed(offset);
}

int Bitmaps::GetCombat()
{
	int mask;
	int offset = 1;
	mask = this->GetGreen(offset);
	if ( mask & 0x01 )
	  return 1;
	return 0;
}

int Bitmaps::GetFollow()
{
	int mask;
	int offset = 1;
	mask = this->GetGreen(offset);
	if ( mask & 0x02 )
	  return 1;
	return 0;
}

int Bitmaps::GetForceFollow()
{
	int mask;
	int offset = 1;
	mask = this->GetGreen(offset);
	if ( mask & 0x04 )
	  return 1;
	return 0;
}

int Bitmaps::GetMount()
{
	int mask;
	int offset = 1;
	mask = this->GetGreen(offset);
	if ( mask & 0x08 )
	  return 1;
	return 0;
}

void Bitmaps::DoMount()
{
	int mask;
	int offset = 1;
	mask = this->GetGreen(offset);
	if ( mask & 0x08 )
		this->SendCommand(0x48);
	if ( mask & 0x10 )
		this->SendCommand(0x4A);
}

int Bitmaps::GetCasting()
{
	int offset = 1;
	return this->GetBlue(offset);
}

void Bitmaps::DoMovement()
{
	if ( this->_combat )
	{
		// send L for the /focustarget macro
		this->SendCommand(0x4C);
		if ( !this->_forceFollow )
		{
			// send the , key for the interact action
			this->SendCommand(0x4B);
			// send a back command so we don't have (s) the seizures..
			//this->SendCommand(0x53);
		}
	}
	
}

void Bitmaps::SendCommand(WPARAM wParam)
{
	SendMessage(this->_hwnd, WM_KEYDOWN, wParam, 0);
	Sleep(10);
	SendMessage(this->_hwnd, WM_KEYUP, wParam, 0);
}

void Bitmaps::SendCharacter(WPARAM wParam)
{
	SendMessage(this->_hwnd, WM_CHAR, wParam, 0);
}

LPBYTE Bitmaps::GetData(){
	return this->_data;
}

Square Bitmaps::GetSquareOne()
{
	Square squareData;
	int offset = 2;
	squareData.red = this->GetRed(offset);
	squareData.green = this->GetGreen(offset);
	squareData.blue = this->GetBlue(offset);
	return squareData;
}

Square Bitmaps::GetSquareTwo()
{
	Square squareData;
	int offset = 3;
	squareData.red = this->GetRed(offset);
	squareData.green = this->GetGreen(offset);
	squareData.blue = this->GetBlue(offset);
	return squareData;
}

// returns an array of squares data
/*Square* Bitmaps::GetSquares()
{
	Square squareData[N_SQUARES];
	int i = 0;
	for(i = 1;i<N_SQUARES;i++)
	{
		this->GetRed(i);
		this->GetGreen(i);
		this->GetBlue(i);
	}
	return squareData;
}*/
