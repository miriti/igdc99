#include "CGameMain.h"

#include "../engine/CApplication.h"

CGameMain::CGameMain()
{
    background = new CGameBg();
    addChild(background);

    faith = new CFaith();
    faith->x = (160 - faith->w)/2;
    faith->y = (120 - faith->h)/2;
    addChild(faith);
}

CGameMain::~CGameMain()
{
    //dtor
}

void CGameMain::update(unsigned int deltaTime)
{
    background->parallax(-faith->speed);

    CDisplayObject::update(deltaTime);
}

void CGameMain::render(SDL_Renderer * renderer)
{
    CDisplayObject::render(renderer);
}
