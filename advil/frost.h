class Frost : public Bitmaps
{
public:
	Frost();
	~Frost();

	WPARAM DoLogic();
	int SetNextKey();
	int SetSquareOne(Square);
	int SetSquareTwo(Square);

private:
	Square	_one;
	Square	_two;
	LPBYTE  data;

	int FrostStrike;
	int HowlingBlast;
    int SoulReaper;
    int PlagueStrike;
    int Obliterate;
    int RuneTap;
    int RunicCorruption;
    int RunicEmpowerment;
    int HornofWinter;
    int Outbreak; 
    int PillarofFrost;
    int EmpowerRuneWeapon;
    int RaiseDead;

	int nextKey;
};