#include <cstddef>
#include "CDisplayObject.h"

#include <math.h>
#include <iostream>

using namespace std;

CDisplayObject::CDisplayObject()
{
}

CDisplayObject::~CDisplayObject()
{
}

void CDisplayObject::addChild(CDisplayObject * child)
{
    children.push_back(child);
    child->setParent(this);
}

void CDisplayObject::removeChild(CDisplayObject * child)
{
}

void CDisplayObject::setParent(CDisplayObject* newParent)
{
    this->parent = newParent;
}

/**
 * Render
 */
void CDisplayObject::render()
{
    for(unsigned int i=0; i<children.size(); i++)
    {
        children[i]->render();
    }
}

/**
 * update
 */
void CDisplayObject::update(unsigned int deltaTime)
{
    rect.h = floor(h);
    rect.w = floor(w);
    rect.x = floor(x);
    rect.y = floor(y);

    for(unsigned int i=0; i<children.size(); i++)
    {
        children[i]->update(deltaTime);
    }
}
