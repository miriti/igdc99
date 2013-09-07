#include <cstddef>
#include "CDisplayObject.h"
#include "CApplication.h"

#include <math.h>
#include <iostream>

using namespace std;

CDisplayObject::CDisplayObject()
{
    rect.w = rect.h = rect.x = rect.y = 0;
    x = y = w = h = rotation = 0;
    kill = false;
}

CDisplayObject::~CDisplayObject()
{
}

void CDisplayObject::addChild(CDisplayObject * child)
{
    children.push_back(child);
    child->setParent(this);
}

void CDisplayObject::removeChild(CDisplayObject * child, bool dispose)
{
    for(int i=0; i<children.size(); i++)
    {
        if(children[i]==child)
        {
            CDisplayObject * foundChild = children[i];
            children.erase(children.begin()+i);

            if(dispose)
            {
                delete foundChild;
            }

            return;
        }
    }
}

void CDisplayObject::setParent(CDisplayObject* newParent)
{
    this->parent = newParent;
}

float CDisplayObject::globalX()
{
    return parent == NULL ? x : parent->globalX()+x;
}

float CDisplayObject::globalY()
{
    return parent == NULL ? y : parent->globalY()+y;
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
    rect.x = floor(globalX());
    rect.y = floor(globalY());

    if(children.size()>0)
    {
        for(int i=children.size()-1; i>=0; i--)
        {
            if(children[i]->kill)
            {
                CDisplayObject * eraceObject = children[i];
                children.erase(children.begin()+i);
                delete eraceObject;
            }
            else
            {
                children[i]->update(deltaTime);
            }
        }
    }
}

void CDisplayObject::onKeyDown(SDL_Keycode keyCode)
{
    for(unsigned int i=0; i<children.size(); i++)
    {
        children[i]->onKeyDown(keyCode);
    }
}

void CDisplayObject::onKeyUp(SDL_Keycode keyCode)
{
    for(unsigned int i=0; i<children.size(); i++)
    {
        children[i]->onKeyUp(keyCode);
    }
}

CInput* CDisplayObject::getInput()
{
    return &CApplication::instance->input;
}

