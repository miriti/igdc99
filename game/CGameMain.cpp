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
    //dtor
}

void CGameMain::update(unsigned int deltaTime)
{
    city->x = 20-city->faith->x;
    city->y = 60-city->faith->y;

    background->parallax(-city->faith->speed_x);

    CDisplayObject::update(deltaTime);
}
