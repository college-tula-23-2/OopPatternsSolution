#include <iostream>
#include "Unit.h"
#include "IUnitFactory.h"
#include "IArmyFactory.h"

#include <vector>
#include <map>

//class ClientUnitFactory
//{
//    std::map<UnitType, IUnitFactory*> factories;
//public:
//    void AddFactory(UnitType type, IUnitFactory* factory)
//    {
//        factories.insert(std::make_pair(type, factory));
//    }
//    Unit* UnitCreate(UnitType type)
//    {
//        return factories[type]->Create();
//    }
//    Unit* CreateUnit(UnitType type)
//    {
//        switch (type)
//        {
//        case UnitType::Infantry:
//            return new InfantryUnit();
//            break;
//        case UnitType::Archer:
//            return new ArcherUnit();
//            break;
//        case UnitType::Horseman:
//            return new HorsemanUnit();
//            break;
//        default:
//            return nullptr;
//            break;
//        }
//    }
//};

void FactoryMethodExample()
{
    /*ClientUnitFactory facftory;
    facftory.AddFactory(UnitType::Infantry, new InfantryUnitFactory());
    facftory.AddFactory(UnitType::Archer, new ArcherUnitFactory());
    facftory.AddFactory(UnitType::Horseman, new HorsemanUnitFactory());*/

    /*Unit* unit = facftory.CreateUnit(UnitType::Infantry);
    unit->Move();
    unit = facftory.CreateUnit(UnitType::Archer);
    unit->Move();*/

    /*Unit* unit = facftory.UnitCreate(UnitType::Infantry);
    unit->Move();
    unit = facftory.UnitCreate(UnitType::Archer);
    unit->Move();
    unit = facftory.UnitCreate(UnitType::Horseman);
    unit->Move();*/
}

class ClienArmyFactory
{
    std::map<Citizenship, IArmyFactory*> armyFactories;
public:
    void AddFactory(Citizenship citizenship, IArmyFactory* factory)
    {
        armyFactories.insert(std::make_pair(citizenship, factory));
    }

    std::vector<Unit*> ArmyCreate(Citizenship citizenship, int armySize)
    {
        srand(time(nullptr));

        IArmyFactory* factory = armyFactories[citizenship];
        std::vector<Unit*> army;

        for (int i{}; i < armySize; i++)
        {
            UnitType type = (UnitType)(rand() % 3);
            
            switch (type)
            {
            case UnitType::Infantry:
                army.push_back(factory->InfantryCreate());
                break;
            case UnitType::Archer:
                army.push_back(factory->ArcherCreate());
                break;
            case UnitType::Horseman:
                army.push_back(factory->HorsemanCreate());
                break;
            default:
                break;
            }
        }

        return army;
    }
};

int main()
{
    ClienArmyFactory factory;
    factory.AddFactory(Citizenship::Roman, new RomanArmyFactory());
    factory.AddFactory(Citizenship::Carthage, new CarthageArmyFactory());

    std::vector<Unit*> army = factory.ArmyCreate(Citizenship::Roman, 20);
    for (auto unit : army)
        unit->Move();

    std::cout << "\n";

    army.clear();
    army = factory.ArmyCreate(Citizenship::Carthage, 30);
    for (auto unit : army)
        unit->Move();

    std::cout << "\n";
}
