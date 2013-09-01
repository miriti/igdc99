#include "CDisplayObject.h"

CDisplayObject::CDisplayObject()
{
    //ctor
}

CDisplayObject::~CDisplayObject()
{
    //dtor
}

void CDisplayObject::addChild(CDisplayObject * child)
{
    children.push_back(child);
}

void CDisplayObject::removeChild(CDisplayObject * child)
{
}

void CDisplayObject::render()
{
    for(int i=0; i<children.size(); i++)
    {
        children[i]->render();
    }
}

void CDisplayObject::update(unsigned int deltaTime)
{
    for(int i=0; i<children.size(); i++)
    {
        children[i]->update(deltaTime);
    }
}
