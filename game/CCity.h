#ifndef CCITY_H
#define CCITY_H

#include <vector>

#include "../engine/CDisplayObject.h"

#include "CBuilding.h"
#include "CFaith.h"

using namespace std;

class CCity: public CDisplayObject
{
    public:
        CCity();
        virtual ~CCity();
        void addBuilding(CBuilding* building);
        void update(unsigned int deltaTime);
        CFaith* faith;
    protected:
    private:
        vector<CBuilding*> buildings;
        float next_building_x;
};

#endif // CCITY_H
