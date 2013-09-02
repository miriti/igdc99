#include "CIntro.h"
#include "../engine/CImage.h"
#include "../engine/CImageLoader.h"
#include "../engine/CApplication.h"

#include "CMainMenu.h"
#include "CGameMain.h"
#include "CGameRoot.h"

CIntro::CIntro()
{
    CImage * image = new CImage(CImageLoader::getImage("data/gfx/hud/igdc.png"));
    image->x = (CApplication::instance->displayWidth - image->w)/2;
    addChild(image);

    timePassed = 0;
}

CIntro::~CIntro()
{
    //dtor
}

void CIntro::update(unsigned int deltaTime)
{
    if(timePassed >= 300)
    {
        CGameMain * gameMain = new CGameMain();
        CGameRoot::instance->setState(gameMain);
    }
    else
    {
        timePassed+=deltaTime;
    }

    CDisplayObject::update(deltaTime);
}
