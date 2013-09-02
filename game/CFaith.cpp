#include "CFaith.h"

#include "../engine/CApplication.h"

CFaith::CFaith(): CMovieClip("data/gfx/sprites/faith/faith_anim.png", 32, 32)
{
    animStill();
}

CFaith::~CFaith()
{
    //dtor
}

void CFaith::update(unsigned int deltaTime)
{
    if(CApplication::instance->input.isLeft())
    {
        speed-=0.1;
    }
    if(CApplication::instance->input.isRight())
    {
        speed+=0.1;
    }

    if(speed != 0){
        if(currentAnimation != 1)
            animRun();

        frameRate = 5 + abs(speed)*5;

        flipHorisontal = (speed < 0);
    }

    CMovieClip::update(deltaTime);
}

void CFaith::animStill()
{
    if(currentAnimation != 0)
    {
        frameMin = 0;
        frameMax = 0;
        frameRate = 1;

        currentAnimation = 0;
    }
}

void CFaith::animRun()
{
    if(currentAnimation != 1){
        frameMin = 1;
        frameMax = 4;
        frameRate = 5;

        currentAnimation = 1;
    }
}

void CFaith::animJump()
{

}

void CFaith::animSlide()
{

}

