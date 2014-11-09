class Bitmaps
{
public:
	Bitmaps();
	Bitmaps(HWND hwnd);
	~Bitmaps();

	int ReadData();
	int GetSquareSize();
	void Release(HWND hwnd);

	int ReadKey();
	int ReadOne();

	int GetRed(int);
	int GetGreen(int);
	int GetBlue(int);

	LPBYTE GetData();

	int GetSpec();
	int GetCombat();
	int GetFollow();
	int GetForceFollow();
	int GetMount();
	int GetCasting();

	Square GetSquareOne();
	Square GetSquareTwo();
	//Square GetSquares();

	void DoMovement();
	void DoMount();

	void SendCommand(WPARAM);
	void SendCharacter(WPARAM);

private:
	LPBYTE				_data;
	HDC					_active_windowDC;
	HDC					_captureDC;
	int					_height;
	int					_width;
	HBITMAP				_new_bitmap;
	BITMAPINFO			_bmi;
	int					_squareSize;
	char				_filename[128];
	DWORD				_id;
	int					_n_squares;

	HWND				_hwnd;

	int					_controlR;
	int					_controlG;
	int					_controlB;

	int					_spec;
	int					_combat;
	int					_follow;
	int					_forceFollow;
	int					_casting;
};