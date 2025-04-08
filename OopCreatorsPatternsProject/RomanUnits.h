#pragma once
#include "Unit.h"

class RomanInfantryUnit : public InfantryUnit
{
public:
	RomanInfantryUnit()
	{
		this->citizenship = Citizenship::Roman;
		this->attack++;
	}

	void Move() override
	{
		std::cout << CitizenshipTitle[(int)citizenship] <<
			" " << UnitTipeTitle[(int)type] <<
			" moved\n";
	}

	void Battle(Unit* enemy) override
	{
		std::cout << CitizenshipTitle[(int)citizenship] <<
			" " << UnitTipeTitle[(int)type] << " vs " <<
			CitizenshipTitle[(int)enemy->Citizenship()] <<
			" " << UnitTipeTitle[(int)enemy->Type()] << "\n";
	}
};

class RomanArcherUnit : public ArcherUnit
{
public:
	RomanArcherUnit()
	{
		this->citizenship = Citizenship::Roman;
		this->attack--;
	}

	void Move() override
	{
		std::cout << CitizenshipTitle[(int)citizenship] <<
			" " << UnitTipeTitle[(int)type] <<
			" moved\n";
	}

	void Battle(Unit* enemy) override
	{
		std::cout << CitizenshipTitle[(int)citizenship] <<
			" " << UnitTipeTitle[(int)type] << " vs " <<
			CitizenshipTitle[(int)enemy->Citizenship()] <<
			" " << UnitTipeTitle[(int)enemy->Type()] << "\n";
	}
};

class RomanHorsmanUnit : public HorsemanUnit
{
public:
	RomanHorsmanUnit()
	{
		this->citizenship = Citizenship::Roman;
	}

	void Move() override
	{
		std::cout << CitizenshipTitle[(int)citizenship] <<
			" " << UnitTipeTitle[(int)type] <<
			" moved\n";
	}

	void Battle(Unit* enemy) override
	{
		std::cout << CitizenshipTitle[(int)citizenship] <<
			" " << UnitTipeTitle[(int)type] << " vs " <<
			CitizenshipTitle[(int)enemy->Citizenship()] <<
			" " << UnitTipeTitle[(int)enemy->Type()] << "\n";
	}
};

