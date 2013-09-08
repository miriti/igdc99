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

    if(bgMusic == NULL){
        bgMusic = CAudio::loadSound("data/sound/music.ogg", true);
        CAudio::play(bgMusic, -1);
    }
}

CGameMain::~CGameMain()
{
}

void CGameMain::update(unsigned int deltaTime)
{
    city->x = (CApplication::instance->displayWidth / 8) - city->faith->x;

    if(city->faith->y < 200)
    {
        if(city->y < (CApplication::instance->displayHeight / 4) - city->faith->y)
            city->y = (CApplication::instance->displayHeight / 4) - city->faith->y;

        if(city->y > ((CApplication::instance->displayHeight / 4) * 3) - city->faith->y)
            city->y = ((CApplication::instance->displayHeight / 4) * 3) - city->faith->y;
    }

    background->parallax(-city->faith->speed_x, 0.f);

    CDisplayObject::update(deltaTime);
}

Mix_Chunk* CGameMain::bgMusic = NULL;
