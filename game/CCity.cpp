#include "CCity.h"

#define CITY_GROUND_LEVEL 300

CCity::CCity()
{
    CBuilding * testBuilding = new CBuilding(5, 20);
    next_building_x = 0;
    addBuilding(testBuilding);

    faith = new CFaith();
    addChild(faith);
}

CCity::~CCity()
{
    //dtor
}

void CCity::addBuilding(CBuilding* building)
{
    building->x = next_building_x;
    building->y = CITY_GROUND_LEVEL - building->h;

    building->added();

    addChild(building);

    buildings.push_back(building);
}

void CCity::update(unsigned int deltaTime)
{
    CDisplayObject::update(deltaTime);

    for(int i=0; i<buildings.size(); i++){
        faith->hitbox->test(buildings[i]->hitbox);
    }
}
