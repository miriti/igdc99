#ifndef CGAMEMAIN_H
#define CGAMEMAIN_H

#include "../engine/CDisplayObject.h"
#include "CGameBg.h"
#include "CFaith.h"

class CGameMain : public CDisplayObject
{
    public:
        CGameMain();
        virtual ~CGameMain();
        void update(unsigned int deltaTime);
        void render(SDL_Renderer * renderer);
    protected:
    private:
        CGameBg * background;
        CFaith * faith;
};

#endif // CGAMEMAIN_H
