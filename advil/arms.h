class Arms : public Bitmaps
{
public:
	Arms();
	~Arms();

	WPARAM DoLogic();
	int SetNextKey();
	int SetSquareOne(Square);
	int SetSquareTwo(Square);

private:
	Square	_one;
	Square	_two;
	LPBYTE  data;

    int Charge; //                  {r = 1  , g = 0  , b = 0}
    int MortalStrike; //           {r = 2  , g = 0  , b = 0} 
    int Whirlwind; //               {r = 4  , g = 0  , b = 0}
    int Rend; //                    {r = 8  , g = 0  , b = 0}
    int Execute; //                 {r = 16 , g = 0  , b = 0}
    int ShieldBarrier; //          {r = 32 , g = 0  , b = 0}
    int Bloodbath; //        {r = 64 , g = 0  , b = 0}
    int Recklessness; //            {r = 128, g = 0  , b = 0}
    int BloodFury; //              {r = 0  , g = 1  , b = 0}
    int BattleShout; //            {r = 0  , g = 2  , b = 0}
    int RallyingCry; //            {r = 0  , g = 4  , b = 0} 
    int VictoryRush; //            {r = 0  , g = 8  , b = 0}
	
	int MassSpellReflection; //   {r = 0  , g = 16 , b = 0}
    int DragonRoar; //             {r = 0  , g = 32 , b = 0}
    int ColossusSmash; //          {r = 0  , g = 64 , b = 0}
    int EnragedRegeneration; //    {r = 0  , g = 128, b = 0}
    int BerserkerRage; //          {r = 0  , g = 0  , b = 1}
    int HeroicLeap; //             {r = 0  , g = 0  , b = 2}
    int SweapingStrikes; //        {r = 0  , g = 0  , b = 4}

	int nextKey;
};