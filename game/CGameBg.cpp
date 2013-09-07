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

    d_layer0 = d_layer1 = y_layer0 = y_layer1 = 0.f;
}

CGameBg::~CGameBg()
{
}

void CGameBg::parallax(float delta_x, float delta_y)
{
    d_layer0 += delta_x / 20.f;
    d_layer1 += delta_x / 10.f;

    y_layer0 += delta_y / 20.f;
    y_layer1 += delta_y / 10.f;

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

    buildings0[0]->y = buildings0[1]->y = y_layer0;
    buildings1[0]->y = buildings1[1]->y = y_layer1;
}
