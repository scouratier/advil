class Ret : public Bitmaps
{
public:
	Ret();
	~Ret();

	WPARAM DoLogic();
	int SetNextKey();
	int SetSquareOne(Square);
	int SetSquareTwo(Square);

private:
	Square	_one;
	Square	_two;
	LPBYTE  data;
	int nextKey;

	int Inquisition;
    int TemplarsVerdict;
    int ExecutionSentence;
    int HammerofWrath;
    int CrusaderStrike;
    int Judgment;
    int Exorcism;
    int AvengingWrath;
    int GuardianofAncientKing;
    int FlashofLight;
    int FistofJustice;
    int EternalFlame;
    int BlessingofKings;
    int Cleanse;
    int HandofFreedom;
    int Rebuke;
    int LayonHands;
};