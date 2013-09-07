#ifndef CBUILDING_H
#define CBUILDING_H

#include "../engine/CDisplayObject.h"
#include "../engine/CImage.h"

#include "CHitbox.h"

class CBuilding: public CDisplayObject
{
    public:
        CBuilding(int wSections, int hSections);
        virtual ~CBuilding();
        void update(unsigned int deltaTime);
        void added();
        CHitbox * hitbox;
    protected:
    private:
};

class CBuildingSection: public CImage
{
    public:
        CBuildingSection();
        virtual ~CBuildingSection();
};

#endif // CBUILDING_H
