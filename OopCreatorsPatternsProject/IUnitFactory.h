#pragma once
#include "Unit.h"

class IUnitFactory
{
public:
	virtual Unit* Create() = 0;
};

class InfantryUnitFactory : public IUnitFactory
{
public:
	InfantryUnit* Create() override
	{
		return new InfantryUnit();
	}
};

class ArcherUnitFactory : public IUnitFactory
{
public:
	ArcherUnit* Create() override
	{
		return new ArcherUnit();
	}
};

class HorsemanUnitFactory : public IUnitFactory
{
public:
	HorsemanUnit* Create() override
	{
		return new HorsemanUnit();
	}
};
