#include "CBuilding.h"

#include "../engine/CImageLoader.h"

CBuilding::CBuilding(int wSections, int hSections)
{
    CBuildingSection * section;

    for(int i=0; i<wSections; i++)
    {
        for(int j=0; j<hSections; j++)
        {
            section = new CBuildingSection();
            section->x = i*section->w;
            section->y = j*section->h;

            addChild(section);
        }
    }

    rect.w = section->w * wSections;
    rect.h = section->h * hSections;

    w = rect.w;
    h = rect.h;

    hitbox = new CHitbox(0, 0, w, h);
}

void CBuilding::update(unsigned int deltaTime)
{
    CDisplayObject::update(deltaTime);

    if(x+w < 0)
    {
        kill = true;
    }
}


void CBuilding::added()
{
    hitbox->updatePosition(x + (w/2), y + (h/2));
}


CBuilding::~CBuilding()
{
    //dtor
}

/****
CBuildingSection
*****/

CBuildingSection::CBuildingSection(): CImage(CImageLoader::getImage("data/gfx/sprites/env/building_section.png"))
{

}

CBuildingSection::~CBuildingSection()
{

}
