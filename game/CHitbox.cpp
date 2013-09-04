#include "CHitbox.h"

#include <iostream>
#include <stdlib.h>

CHitbox::CHitbox(float nx, float ny, float nw, float nh, bool dynamic)
{
    updatePosition(nx, ny);
    updateSize(nw, nh);
    collision = false;
}

CHitbox::~CHitbox()
{
    //dtor
}

void CHitbox::solve()
{
    if(collision)
    {
        collision = false;
    }
}

void CHitbox::updatePosition(float nx, float ny)
{
    x = nx;
    y = ny;
}

void CHitbox::updateSize(float nw, float nh)
{
    w = nw;
    h = nh;

    halfW = w / 2;
    halfH = h / 2;
}


void CHitbox::test(CHitbox* against)
{
    float _cx = x - against->x;
    float _cy = y - against->y;
    float wSum = halfW + against->halfW;
    float hSum = halfH + against->halfH;

    if((abs(_cx) < wSum) && (abs(_cy) < hSum))
    {
        if(children.size() == 0)
        {
            collision = true;

            float _dx = wSum - abs(_cx);
            float _dy = hSum - abs(_cy);

            if(_dx < _dy)
            {
                dx = _dx * (_cx < 0 ? -1 : 1);
                dy = 0;
            }
            else
            {
                dx = 0;
                dy = _dy * (_cy < 0 ? -1 : 1);
            }
        }
        else
        {
            // TODO test with every child
        }
    }
}

void CHitbox::addChild(CHitbox* child)
{
    children.push_back(child);
}

float CHitbox::left()
{
    return x - halfW;
}

float CHitbox::right()
{
    return x + halfW;
}

float CHitbox::top()
{
    return y - halfH;
}

float CHitbox::bottom()
{
    return y + halfH;
}

