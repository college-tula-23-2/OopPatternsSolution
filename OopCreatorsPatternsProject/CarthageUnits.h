#pragma once
#include "Unit.h"

class CarthageInfantryUnit : public InfantryUnit
{
public:
	CarthageInfantryUnit()
	{
		this->citizenship = Citizenship::Carthage;
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

class CarthageArcherUnit : public ArcherUnit
{
public:
	CarthageArcherUnit()
	{
		this->citizenship = Citizenship::Carthage;
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

class CarthageHorsmanUnit : public HorsemanUnit
{
public:
	CarthageHorsmanUnit()
	{
		this->citizenship = Citizenship::Carthage;
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

