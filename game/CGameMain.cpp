#include "CGameMain.h"

#include "../engine/CApplication.h"

#include <iostream>

using namespace std;

CGameMain::CGameMain()
{
    background = new CGameBg();
    addChild(background);

    city = new CCity();
    addChild(city);
}

CGameMain::~CGameMain()
{
}

void CGameMain::update(unsigned int deltaTime)
{
    city->x = (CApplication::instance->displayWidth / 8) - city->faith->x;
    city->y = (CApplication::instance->displayHeight / 2) - city->faith->y;

    background->parallax(-city->faith->speed_x, -city->faith->speed_y);

    CDisplayObject::update(deltaTime);
}
