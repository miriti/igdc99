#include "CGameRoot.h"

#include "../engine/CApplication.h"
#include "../engine/CImage.h"
#include "../engine/CImageLoader.h"

#include <iostream>

using namespace std;

CGameRoot::CGameRoot()
{
    image = new CImage(CImageLoader::getImage("data/gfx/helloworld.png"));
    image->y = (CApplication::instance->displayHeight - image->h)/2;
    addChild(image);
}

CGameRoot::~CGameRoot()
{
}

void CGameRoot::update(unsigned int deltaTime)
{
    image->x += 0.3f;
    image->rotation += 5.f;
    CDisplayObject::update(deltaTime);
}
