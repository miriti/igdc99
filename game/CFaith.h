#ifndef CFAITH_H
#define CFAITH_H

#include "../engine/CMovieClip.h"

#include "CHitbox.h"

class CFaith: public CMovieClip
{
    public:
        CFaith();
        virtual ~CFaith();
        void update(unsigned int deltaTime);
        float speed_x;
        float speed_y;

        void animStill();
        void animRun();
        void animJump();
        void animSlide();

        CHitbox * hitbox;
    protected:
    private:
        int currentAnimation;
        bool in_jump;
};

#endif // CFAITH_H
