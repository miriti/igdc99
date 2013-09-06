#include "CGameBg.h"
#include "../engine/CApplication.h"
#include "../engine/CImageLoader.h"

#include <math.h>
#include <iostream>

using namespace std;

CGameBg::CGameBg()
{
    sky = new CImage("data/gfx/sprites/env/sky.png");
    addChild(sky);

    buildings0[0] = new CImage("data/gfx/sprites/env/buildings_layer_0.png");
    buildings0[1] = new CImage("data/gfx/sprites/env/buildings_layer_0.png");

    buildings0[1]->x = CApplication::instance->displayWidth;

    addChild(buildings0[0]);
    addChild(buildings0[1]);

    buildings1[0] = new CImage("data/gfx/sprites/env/buildings_layer_1.png");
    buildings1[1] = new CImage("data/gfx/sprites/env/buildings_layer_1.png");

    buildings1[1]->x = CApplication::instance->displayWidth;

    addChild(buildings1[0]);
    addChild(buildings1[1]);
}

CGameBg::~CGameBg()
{
    //dtor
}

void CGameBg::parallax(float delta)
{
    d_layer0 += delta / 10.f;
    d_layer1 += delta / 5.f;

    if(d_layer0 < -CApplication::instance->displayWidth)
    {
        d_layer0 = d_layer0 + CApplication::instance->displayWidth;
    }

    if(d_layer1 < -CApplication::instance->displayWidth)
    {
        d_layer1 = d_layer1 + CApplication::instance->displayWidth;
    }

    if(d_layer0 > 0)
    {
        d_layer0 = -CApplication::instance->displayWidth + d_layer0;
    }

    if(d_layer1 > 0)
    {
        d_layer1 = -CApplication::instance->displayWidth + d_layer1;
    }

    buildings0[0]->x = floor(d_layer0);
    buildings0[1]->x = CApplication::instance->displayWidth + floor(d_layer0);

    buildings1[0]->x = floor(d_layer1);
    buildings1[1]->x = CApplication::instance->displayWidth + floor(d_layer1);
}
