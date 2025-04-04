#include <iostream>
#include "Unit.h"
#include "IUnitFactory.h"

#include <map>

class ClientUnitFactory
{
    std::map<UnitType, IUnitFactory*> factories;
public:
    void AddFactory(UnitType type, IUnitFactory* factory)
    {
        factories.insert(std::make_pair(type, factory));
    }
    Unit* UnitCreate(UnitType type)
    {
        return factories[type]->Create();
    }

    Unit* CreateUnit(UnitType type)
    {
        switch (type)
        {
        case UnitType::Infantry:
            return new InfantryUnit();
            break;
        case UnitType::Archer:
            return new ArcherUnit();
            break;
        case UnitType::Horseman:
            return new HorsemanUnit();
            break;
        default:
            return nullptr;
            break;
        }
    }
};

int main()
{
    ClientUnitFactory facftory;
    facftory.AddFactory(UnitType::Infantry, new InfantryUnitFactory());
    facftory.AddFactory(UnitType::Archer, new ArcherUnitFactory());
    facftory.AddFactory(UnitType::Horseman, new HorsemanUnitFactory());

    /*Unit* unit = facftory.CreateUnit(UnitType::Infantry);
    unit->Move();
    unit = facftory.CreateUnit(UnitType::Archer);
    unit->Move();*/

    Unit* unit = facftory.UnitCreate(UnitType::Infantry);
    unit->Move();
    unit = facftory.UnitCreate(UnitType::Archer);
    unit->Move();
    unit = facftory.UnitCreate(UnitType::Horseman);
    unit->Move();
}
