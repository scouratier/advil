#include "common.h"

Frost::Frost()
{
	this->HowlingBlast = 0x31;
	this->PlagueStrike = 0x32;
	this->Obliterate = 0x33;
	this->SoulReaper = 0x34;
	this->FrostStrike = 0x36;
    this->RaiseDead = 0x38;
	this->HornofWinter = 0x39;
    this->Outbreak = 0x30;
	this->PillarofFrost = 0xBD;
	this->EmpowerRuneWeapon = 0xBB;

    this->RuneTap = 0x00;
    this->RunicCorruption = 0x00;
    this->RunicEmpowerment = 0x00;
   
}

Frost::~Frost()
{

}

WPARAM Frost::DoLogic()
{
	this->SetNextKey();
	return this->nextKey;
}

int Frost::SetSquareOne(Square in)
{
	this->_one = in;
	return 1;
}

int Frost::SetSquareTwo(Square in)
{
	this->_two = in;
	return 1;
}

int Frost::SetNextKey()
{
	if (this->_one.red & 0x01)
	{
		this->nextKey = this->FrostStrike;
		return 1;
	}
	if (this->_one.red & 0x02)
	{
		this->nextKey = this->HowlingBlast;
		return 1;
	}
	if (this->_one.red & 0x04)
	{
		this->nextKey = this->SoulReaper;
		return 1;
	}
	if (this->_one.red & 0x08)
	{
		this->nextKey = this->PlagueStrike;
		return 1;
	}
	if (this->_one.red & 0x10)
	{
		this->nextKey = this->Obliterate;
		return 1;
	}
	if (this->_one.red & 0x20)
	{
		this->nextKey = this->RuneTap;
		return 1;
	}
	if (this->_one.red & 0x40)
	{
		this->nextKey = this->RunicCorruption;
		return 1;
	}
	if (this->_one.red & 0x80)
	{
		this->nextKey = this->RunicEmpowerment;
		return 1;
	}
	if (this->_one.green & 0x01)
	{
		this->nextKey = this->HornofWinter;
		return 1;
	}
	if (this->_one.green & 0x02)
	{
		this->nextKey = this->Outbreak;
		return 1;
	}
	if (this->_one.green & 0x04)
	{
		this->nextKey = this->PillarofFrost;
		return 1;
	}
	if (this->_one.green & 0x08)
	{
		this->nextKey = this->EmpowerRuneWeapon;
		return 1;
	}
	if (this->_one.green & 0x10)
	{
		this->nextKey = this->RaiseDead;
		return 1;
	}
	return 1;
}