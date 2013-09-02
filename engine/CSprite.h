#ifndef CSPRITE_H
#define CSPRITE_H

#include "CDisplayObject.h"
#include <SDL_render.h>

class CSprite : public CDisplayObject
{
    public:
        CSprite(int spriteWidth, int spriteHeight);
        virtual ~CSprite();
    protected:
        SDL_Texture * textureSurface;
    private:
};

#endif // CSPRITE_H
