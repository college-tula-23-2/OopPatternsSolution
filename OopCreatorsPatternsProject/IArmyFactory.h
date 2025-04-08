#pragma once
#include "Unit.h"
#include "RomanUnits.h"
#include "CarthageUnits.h"

class IArmyFactory
{
public:
	virtual InfantryUnit* InfantryCreate() = 0;
	virtual ArcherUnit* ArcherCreate() = 0;
	virtual HorsemanUnit* HorsemanCreate() = 0;
};

class RomanArmyFactory : public IArmyFactory
{
public:
	RomanInfantryUnit* InfantryCreate() override
	{
		return new RomanInfantryUnit();
	}

	RomanArcherUnit* ArcherCreate() override
	{
		return new RomanArcherUnit();
	}

	RomanHorsmanUnit* HorsemanCreate() override
	{
		return new RomanHorsmanUnit();
	}
};

class CarthageArmyFactory : public IArmyFactory
{
public:
	CarthageInfantryUnit* InfantryCreate() override
	{
		return new CarthageInfantryUnit();
	}

	CarthageArcherUnit* ArcherCreate() override
	{
		return new CarthageArcherUnit();
	}

	CarthageHorsmanUnit* HorsemanCreate() override
	{
		return new CarthageHorsmanUnit();
	}
};
