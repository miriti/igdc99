#include "CCity.h"

#define CITY_GROUND_LEVEL 300

#include <time.h>

CCity::CCity()
{
    next_building_x = 0;

    srand(time(NULL));

    CBuilding * firstBuilding = new CBuilding(30, 15);

    addBuilding(firstBuilding);

    int nexHait = 15 + (-2 + rand() % 4);

    for(int i=0; i<10; i++)
    {
        CBuilding * testBuilding = new CBuilding(2 + rand() % 13, nexHait);
        nexHait += (-2 + rand() % 4);
        addBuilding(testBuilding);
    }

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

    next_building_x += building->w + 30;
}

void CCity::testCollisions(CHitbox* hitbox)
{
    for(int i=0; i<buildings.size(); i++)
    {
        hitbox->test(buildings[i]->hitbox);
    }
}
