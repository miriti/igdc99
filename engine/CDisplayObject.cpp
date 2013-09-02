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
    for(int i=0; i<children.size(); i++)
    {
        if(children[i]==child)
        {
            children.erase(children.begin()+i);
            return;
        }
    }
}

void CDisplayObject::setParent(CDisplayObject* newParent)
{
    this->parent = newParent;
}

/**
 * Render
 */
void CDisplayObject::render(SDL_Renderer * renderer)
{
    for(unsigned int i=0; i<children.size(); i++)
    {
        children[i]->render(renderer);
    }
}

/**
 * update
 */
void CDisplayObject::update(unsigned int deltaTime)
{
    rect.h = floor(h);
    rect.w = floor(w);
    rect.x = floor(parent->x + x);
    rect.y = floor(parent->y + y);

    for(unsigned int i=0; i<children.size(); i++)
    {
        children[i]->update(deltaTime);
    }
}

void CDisplayObject::onKeyDown(SDL_Keycode keyCode)
{

}

void CDisplayObject::onKeyUp(SDL_Keycode keyCode)
{

}
