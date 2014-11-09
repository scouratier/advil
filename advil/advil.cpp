#include "common.h"

bool saveBitmap(LPCSTR filename, HBITMAP bmp, HPALETTE pal)
{
    bool result = false;
    PICTDESC pd;

    pd.cbSizeofstruct   = sizeof(PICTDESC);
    pd.picType      = PICTYPE_BITMAP;
    pd.bmp.hbitmap  = bmp;
    pd.bmp.hpal     = pal;

    LPPICTURE picture;
    HRESULT res = OleCreatePictureIndirect(&pd, IID_IPicture, false,
                       reinterpret_cast<void**>(&picture));

    if (!SUCCEEDED(res))
    return false;

    LPSTREAM stream;
    res = CreateStreamOnHGlobal(0, true, &stream);

    if (!SUCCEEDED(res))
    {
    picture->Release();
    return false;
    }

    LONG bytes_streamed;
    res = picture->SaveAsFile(stream, true, &bytes_streamed);

    HANDLE file = CreateFile(filename, GENERIC_WRITE, FILE_SHARE_READ, 0,
                 CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);

    if (!SUCCEEDED(res) || !file)
    {
    stream->Release();
    picture->Release();
    return false;
    }

    HGLOBAL mem = 0;
    GetHGlobalFromStream(stream, &mem);
    LPVOID data = GlobalLock(mem);

    DWORD bytes_written;

    result   = !!WriteFile(file, data, bytes_streamed, &bytes_written, 0);
    result  &= (bytes_written == static_cast<DWORD>(bytes_streamed));

    GlobalUnlock(mem);
    CloseHandle(file);
	 
    stream->Release();
    picture->Release();

    return result;
}

BOOL printRawData(LPBYTE data)
{
	int i = 0;

	while(i<192)
	{
		//cout << dec << data[i] << " ";
		printf("R:%d G:%d B:%d A:%d\n",data[i+2],data[i+1],data[i],data[i+3]);
		i = i + 4;
		//printf("1: %.2X 2: %.2X 3: %.2X",data[i], data[i+1], data[i+2]);
		//printf("1: %d 2: %d 3: %d\n",data[i], data[i+1], data[i+2],data[i+4]);
	}
	cout << endl;
	return true;
}


BOOL CALLBACK enumWindowAction(HWND hwnd, LPARAM ptr)
{	
	TCHAR		title[255];
	string		wow_name ("World of Warcraft");
	int			spec = -1;

	if (!hwnd)
		return true;
	GetWindowText(hwnd,title,sizeof(title));
	int i = 0;
	
	if ( wow_name.compare( title ) == 0 )
	{
		Bitmaps * bm = new Bitmaps(hwnd);
		bm->ReadData();
		bm->DoMovement();
		bm->DoMount();
		spec = bm->GetSpec();
		if (spec == 1)
		{
			Arms arms;// = new Arms();
			arms.SetSquareOne(bm->GetSquareOne());
			arms.SetSquareTwo(bm->GetSquareTwo());
			bm->SendCommand(arms.DoLogic());

		}
		if (spec == 7)
		{
			Ret ret;// = new Ret();
			ret.SetSquareOne(bm->GetSquareOne());
			ret.SetSquareTwo(bm->GetSquareTwo());
			bm->SendCommand(ret.DoLogic());
		}
		if (spec == 9)
		{
			Frost frost;
			frost.SetSquareOne(bm->GetSquareOne());
			frost.SetSquareTwo(bm->GetSquareTwo());
			bm->SendCommand(frost.DoLogic());
		}


		bm->~Bitmaps();



//		DWORD id;
	//	GetWindowThreadProcessId(hwnd, &id);
		//char		filename[128];
		//sprintf(filename, "e:\\temp\\wow-%d.bmp", id);
		//saveBitmap(filename, new_bitmap, NULL);


    
	}
	return TRUE;
}

void main(void){
    	
	while(1)
	{
		EnumWindows(enumWindowAction, NULL);
		Sleep(50);
	}
}