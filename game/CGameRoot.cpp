#include "CGameRoot.h"

#include "../engine/CApplication.h"
#include "../engine/CImage.h"
#include "../engine/CImageLoader.h"

#include "CIntro.h"

#include <iostream>
#include <malloc.h>
#include <time.h>

using namespace std;

CGameRoot::CGameRoot()
{
    instance = this;

    CIntro * intro = new CIntro();
    setState(intro);
}

CGameRoot::~CGameRoot()
{
}

void CGameRoot::setState(CDisplayObject* newState, bool broot)
{
    if(currentState != NULL){
        removeChild(currentState, broot);
    }

    currentState = newState;

    addChild(currentState);
}

CGameRoot * CGameRoot::instance = NULL;

