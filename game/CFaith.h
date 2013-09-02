#ifndef CFAITH_H
#define CFAITH_H

#include "../engine/CMovieClip.h"

class CFaith: public CMovieClip
{
    public:
        CFaith();
        virtual ~CFaith();
        void update(unsigned int deltaTime);

        float speed;

        void animStill();
        void animRun();
        void animJump();
        void animSlide();
    protected:
    private:
        int currentAnimation = -1;
};

#endif // CFAITH_H
