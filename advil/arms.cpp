#include "common.h"

Arms::Arms()
{
    this->Charge= 0x31; //                  {r = 1  , g = 0  , b = 0}
    this->MortalStrike= 0x32; //           {r = 2  , g = 0  , b = 0} 
    this->Whirlwind= 0x33; //               {r = 4  , g = 0  , b = 0}
    this->Rend= 0x34; //                    {r = 8  , g = 0  , b = 0}
    this->Execute= 0x35; //                 {r = 16 , g = 0  , b = 0}
    this->ShieldBarrier= 0x36; //          {r = 32 , g = 0  , b = 0}
    this->Bloodbath= 0x37; //        {r = 64 , g = 0  , b = 0}
    this->Recklessness= 0x38; //            {r = 128, g = 0  , b = 0}e
    this->BloodFury= 0x39; //              {r = 0  , g = 1  , b = 0}
    this->BattleShout= 0x30; //            {r = 0  , g = 2  , b = 0}
    this->RallyingCry= 0xBD; //            {r = 0  , g = 4  , b = 0} 
    this->VictoryRush= 0xBB; //            {r = 0  , g = 8  , b = 0}
	
	this->MassSpellReflection= 0x45; //   {r = 0  , g = 16 , b = 0}
    this->DragonRoar= 0x52; //             {r = 0  , g = 32 , b = 0}
    this->ColossusSmash= 0x46; //          {r = 0  , g = 64 , b = 0}f
    this->EnragedRegeneration= 0xC0; //    {r = 0  , g = 128, b = 0}
    this->BerserkerRage= 0x5A; //          {r = 0  , g = 0  , b = 1}z
    this->HeroicLeap= 0x58; //             {r = 0  , g = 0  , b = 2}x
    this->SweapingStrikes= 0x43; //        {r = 0  , g = 0  , b = 4}c
}

Arms::~Arms()
{
}

WPARAM Arms::DoLogic()
{
	this->SetNextKey();
	return this->nextKey;
}

int Arms::SetSquareOne(Square in)
{
	this->_one = in;
	return 1;
}

int Arms::SetSquareTwo(Square in)
{
	this->_two = in;
	return 1;
}

int Arms::SetNextKey(){
	if (this->_one.red & 0x01)
	{
		this->nextKey = this->Charge;
		return 1;
	}

	if (this->_one.red & 0x02)
	{
		this->nextKey = this->MortalStrike;
		return 1;
	}

	if (this->_one.red & 0x04)
	{
		this->nextKey = this->Whirlwind;
		return 1;
	}

	if (this->_one.red & 0x08)
	{
		this->nextKey = this->Rend;
		return 1;
	}

	if (this->_one.red & 0x10)
	{
		this->nextKey = this->Execute;
		return 1;
	}

	if (this->_one.red & 0x20)
	{
		this->nextKey = this->ShieldBarrier;
		return 1;
	}

	if (this->_one.red & 0x40)
	{
		this->nextKey = this->Bloodbath;
		return 1;
	}

	if (this->_one.red & 0x80)
	{
		this->nextKey = this->Recklessness;
		return 1;
	}

	if (this->_one.green & 0x01)
	{
		this->nextKey = this->BloodFury;
		return 1;
	}

	if (this->_one.green & 0x02)
	{
		this->nextKey = this->BattleShout;
		return 1;
	}

	if (this->_one.green & 0x04)
	{
		this->nextKey = this->RallyingCry;
		return 1;
	}

	if (this->_one.green & 0x08)
	{
		this->nextKey = this->VictoryRush;
		return 1;
	}

	if (this->_one.green & 0x10)
	{
		this->nextKey = this->MassSpellReflection;
		return 1;
	}

	if (this->_one.green & 0x20)
	{
		this->nextKey = this->DragonRoar;
		return 1;
	}

	if (this->_one.green & 0x40)
	{
		this->nextKey = this->ColossusSmash;
		return 1;
	}

	if (this->_one.green & 0x80)
	{
		this->nextKey = this->EnragedRegeneration;
		return 1;
	}

	if (this->_one.blue & 0x01)
	{
		this->nextKey = this->BerserkerRage;
		return 1;
	}

	if (this->_one.blue & 0x02)
	{
		this->nextKey = this->HeroicLeap;
		return 1;
	}

	if (this->_one.blue & 0x04)
	{
		this->nextKey = this->SweapingStrikes;
		return 1;
	}

	return 1;
}