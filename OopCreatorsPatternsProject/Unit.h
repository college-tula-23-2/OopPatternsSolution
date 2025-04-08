#pragma once
#include <iostream>

enum class UnitType
{
	Infantry,
	Archer,
	Horseman
};

std::string UnitTipeTitle[] = { "Infantry", "Archer", "Horseman" };

enum class Citizenship
{
	Roman,
	Carthage,
};

std::string CitizenshipTitle[] = { "Roman", "Carthage" };

class Unit
{
protected:
	std::string title;
	int attack;
	int defend;

	UnitType type;
	Citizenship citizenship;
public:
	Unit()
		: title{},
		attack{},
		defend{}{ }

	std::string& Title() { return title; }
	int& Attack() { return attack; }
	int& Defend() { return defend; }

	UnitType& Type() { return type; }
	Citizenship& Citizenship() { return citizenship; }

	virtual void Move() = 0;
	virtual void Battle(Unit* enemy) = 0;
};

class InfantryUnit : public Unit
{
protected:
	std::string coldWeapon;
public:
	InfantryUnit()
	{
		this->type = UnitType::Infantry;
		this->attack = 3;
		this->defend = 5;
	}

	std::string& ColdWeapon() { return coldWeapon; }
};

class ArcherUnit : public Unit
{
protected:
	std::string bowWeapon;
public:
	ArcherUnit()
	{
		this->type = UnitType::Archer;
		this->attack = 5;
		this->defend = 3;
	}

	std::string& BowWeapon() { return bowWeapon; }
};

class HorsemanUnit : public Unit
{
protected:
	std::string weapon;
public:
	HorsemanUnit()
	{
		this->type = UnitType::Horseman;
		this->attack = 7;
		this->defend = 3;
	}
	std::string& Weapon() { return weapon; }
};