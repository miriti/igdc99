#include "CCity.h"

#include <time.h>
#include <iostream>

#include "../engine/CApplication.h"

using namespace std;

CCity::CCity()
{
    next_building_x = 0;

    srand(time(NULL));

    CBuilding * firstBuilding = new CBuilding(30, 15);

    addBuilding(firstBuilding);

    faith = new CFaith();
    faith->y = firstBuilding->y - faith->h;
    faith->x = (CApplication::instance->displayWidth / 8);
    addChild(faith);
}

CCity::~CCity()
{
}

void CCity::update(unsigned int deltaTime)
{
    for(int i=buildings.size()-1; i>=0; i--)
    {
        if(x + (buildings[i]->x + buildings[i]->w) < 0)
        {
            buildings[i]->kill = true;
            buildings.erase(buildings.begin()+i);
        }
    }

    if(-x + CApplication::instance->displayWidth > next_building_x)
    {
        CBuilding * newBuilding = new CBuilding(3 + rand() % 17, nextHeight);
        addBuilding(newBuilding);
    }

    CDisplayObject::update(deltaTime);
}

void CCity::addBuilding(CBuilding* building)
{
    building->x = next_building_x;
    building->y = CITY_GROUND_LEVEL - building->h;

    building->added();

    addChild(building);

    buildings.push_back(building);

    next_building_x += building->w + 60;

    nextHeight = 15 + (-1 + rand() % 2);
}

void CCity::testCollisions(CHitbox* hitbox)
{
    for(int i=0; i<buildings.size(); i++)
    {
        hitbox->test(buildings[i]->hitbox);
    }
}
