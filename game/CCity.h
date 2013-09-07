#ifndef CCITY_H
#define CCITY_H

#include <vector>

#include "../engine/CDisplayObject.h"

#include "CBuilding.h"
#include "CFaith.h"

#define CITY_GROUND_LEVEL 300

using namespace std;

class CCity: public CDisplayObject
{
    public:
        CCity();
        virtual ~CCity();
        void update(unsigned int deltaTime);
        void addBuilding(CBuilding* building);
        void testCollisions(CHitbox* hitbox);
        CFaith* faith;
    protected:
    private:
        int nextHeight;
        float build_x;
        vector<CBuilding*> buildings;
        float next_building_x;
};

#endif // CCITY_H
