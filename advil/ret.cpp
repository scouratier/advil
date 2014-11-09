#include "common.h"

Ret::Ret()
{
	this->Inquisition = 0x36;
    this->TemplarsVerdict = 0x33;
    this->ExecutionSentence = 0x37;
    this->HammerofWrath = 0x35;
    this->CrusaderStrike = 0x32;
    this->Judgment = 0x31;
    this->Exorcism = 0x34;
    this->AvengingWrath = 0x38;
    this->GuardianofAncientKing = 0x39;
    this->FlashofLight = 0x30;
    this->FistofJustice = 0x52;
    this->EternalFlame = 0x45;
    this->BlessingofKings = 0xBB;
    this->Cleanse = 0x58;
    this->HandofFreedom = 0x5A;
    this->Rebuke = 0xBD;
    this->LayonHands = 0x46;
}

Ret::~Ret()
{

}

WPARAM Ret::DoLogic()
{
	this->SetNextKey();
	return this->nextKey;
}

int Ret::SetSquareOne(Square in)
{
	this->_one = in;
	return 1;
}

int Ret::SetSquareTwo(Square in)
{
	this->_two = in;
	return 1;
}

int Ret::SetNextKey()
{
	if (this->_one.red & 0x01)
	{
		this->nextKey = this->Inquisition;
		return 1;
	}
	if (this->_one.red & 0x02)
	{
		this->nextKey = this->TemplarsVerdict;
		return 1;
	}
	if (this->_one.red & 0x04)
	{
		this->nextKey = this->ExecutionSentence;
		return 1;
	}
	if (this->_one.red & 0x08)
	{
		this->nextKey = this->HammerofWrath;
		return 1;
	}
	if (this->_one.red & 0x10)
	{
		this->nextKey = this->CrusaderStrike;
		return 1;
	}
	if (this->_one.red & 0x20)
	{
		this->nextKey = this->Judgment;
		return 1;
	}
	if (this->_one.red & 0x40)
	{
		this->nextKey = this->Exorcism;
		return 1;
	}
	if (this->_one.red & 0x80)
	{
		this->nextKey = this->AvengingWrath;
		return 1;
	}
	if (this->_one.green & 0x01)
	{
		this->nextKey = this->GuardianofAncientKing;
		return 1;
	}
	if (this->_one.green & 0x02)
	{
		this->nextKey = this->FlashofLight;
		return 1;
	}
	if (this->_one.green & 0x04)
	{
		this->nextKey = this->FistofJustice;
		return 1;
	}
	if (this->_one.green & 0x08)
	{
		this->nextKey = this->EternalFlame;
		return 1;
	}
	if (this->_one.green & 0x10)
	{
		this->nextKey = this->BlessingofKings;
		return 1;
	}
	if (this->_one.green & 0x20)
	{
		this->nextKey = this->Cleanse;
		return 1;
	}
	if (this->_one.green & 0x40)
	{
		this->nextKey = this->HandofFreedom;
		return 1;
	}
	if (this->_one.green & 0x80)
	{
		this->nextKey = this->Rebuke;
		return 1;
	}
	if (this->_one.blue & 0x01)
	{
		this->nextKey = this->LayonHands;
		return 1;
	}
	return 1;
}