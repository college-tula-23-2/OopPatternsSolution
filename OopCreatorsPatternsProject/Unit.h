#pragma once
#include <iostream>

enum class UnitType
{
	Infantry,
	Archer,
	Horseman
};

class Unit
{
protected:
	std::string title;
	int attack;
	int defend;
public:
	Unit(std::string title)
		: title{ title },
		attack{},
		defend{}{ }

	std::string& Title() { return title; }
	int& Attack() { return attack; }
	int& Defend() { return defend; }

	virtual void Move() = 0;
	virtual void Battle(Unit* enemy) = 0;
};

class InfantryUnit : public Unit
{
public:
	InfantryUnit() : Unit("Infantry")
	{
		this->attack = 3;
		this->defend = 5;
	}

	void Move() override
	{
		std::cout << this->title << " moved\n";
	}

	void Battle(Unit* enemy) override
	{
		std::cout << "Battle: " << this->title
			<< " vs " << enemy->Title() << "\n";
	}
};

class ArcherUnit : public Unit
{
public:
	ArcherUnit() : Unit("Archer")
	{
		this->attack = 5;
		this->defend = 3;
	}

	void Move() override
	{
		std::cout << this->title << " moved\n";
	}

	void Battle(Unit* enemy) override
	{
		std::cout << "Battle: " << this->title
			<< " vs " << enemy->Title() << "\n";
	}
};

class HorsemanUnit : public Unit
{
public:
	HorsemanUnit() : Unit("Horseman")
	{
		this->attack = 7;
		this->defend = 3;
	}

	void Move() override
	{
		std::cout << this->title << " moved\n";
	}

	void Battle(Unit* enemy) override
	{
		std::cout << "Battle: " << this->title
			<< " vs " << enemy->Title() << "\n";
	}
};