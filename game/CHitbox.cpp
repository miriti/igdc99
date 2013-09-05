#include "CHitbox.h"

#include <iostream>
#include <math.h>

using namespace std;

CHitbox::CHitbox(double nx, double ny, double nw, double nh, CDisplayObject* depender)
{
    updatePosition(nx, ny);
    updateSize(nw, nh);
    collision = false;
    _depender = depender;
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

void CHitbox::updatePosition(double nx, double ny)
{
    x = nx;
    y = ny;
}

void CHitbox::updateSize(double nw, double nh)
{
    w = nw;
    h = nh;

    halfW = w / 2;
    halfH = h / 2;
}


void CHitbox::test(CHitbox* against)
{
    double _cx = x - against->x;
    double _cy = y - against->y;
    double wSum = halfW + against->halfW;
    double hSum = halfH + against->halfH;

    if((fabs(_cx) < wSum) && (fabs(_cy) < hSum))
    {
        if(children.size() == 0)
        {
            collision = true;

            double _dx = wSum - fabs(_cx);
            double _dy = hSum - fabs(_cy);

            if(_dx < _dy)
            {
                dx = _dx * (_cx < 0 ? -1.f : 1.f);
                dy = 0;
                cout << "wSum: " << wSum << "\t_dx: " << _dx << "\t_cx: " <<  _cx << "\tdx: " << dx << endl;
            }
            else
            {
                dx = 0;
                dy = _dy * (_cy < 0 ? -1.f : 1.f);
            }

            if(_depender != NULL)
            {
                _depender->x += dx;
                _depender->y += dy;
                updatePosition(_depender->x, _depender->y);
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

double CHitbox::left()
{
    return x - halfW;
}

double CHitbox::right()
{
    return x + halfW;
}

double CHitbox::top()
{
    return y - halfH;
}

double CHitbox::bottom()
{
    return y + halfH;
}

