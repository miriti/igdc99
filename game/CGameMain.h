#ifndef CGAMEMAIN_H
#define CGAMEMAIN_H

#include <SDL2/SDL_mixer.h>

#include "../engine/CDisplayObject.h"
#include "CGameBg.h"
#include "CCity.h"

class CGameMain : public CDisplayObject
{
    public:
        CGameMain();
        virtual ~CGameMain();
        void update(unsigned int deltaTime);
    protected:
    private:
        static Mix_Chunk* bgMusic;
        CGameBg * background;
        CCity * city;
};

#endif // CGAMEMAIN_H
