#include "CFaith.h"
#include "CCity.h"

#include "../engine/CApplication.h"

#include <iostream>

#define FAITH_MAX_SPEED     3.f
#define FAITH_GRAVITY       0.075f
#define FAITH_JUMP_POWER    3.f
#define FAITH_ACCELERATION  0.01f

CFaith::CFaith(): CMovieClip("data/gfx/sprites/faith/faith_anim.png", 32, 32)
{
    currentAnimation = -1;
    animStill();

    speed_x = 2.f;
    speed_y = 0;
    hitbox = new CHitbox(0, 0, 8, 14, this);
}

CFaith::~CFaith()
{
}

void CFaith::update(unsigned int deltaTime)
{
    if((getInput()->isUp()) || (getInput()->isKeyDown(SDLK_x)))
    {
        if(!in_jump)
        {
            in_jump = true;
            speed_y = -FAITH_JUMP_POWER;
            animJump();
        }
    }

    speed_y += FAITH_GRAVITY;

    if(speed_x < FAITH_MAX_SPEED){
        speed_x += FAITH_ACCELERATION;
    }


    if(speed_x != 0)
    {
        if(!in_jump)
        {
            frameRate = 5 + abs(speed_x) * 5;

            flipHorisontal = (speed_x < 0);
        }
    }

    x += speed_x;
    y += speed_y;

    hitbox->updatePosition(x + 16, y + 25);

    ((CCity*)parent)->testCollisions(hitbox);

    if(hitbox->collision)
    {
        if(hitbox->dx != 0)
        {
            speed_x = 0;
        }

        if(hitbox->dy != 0)
        {
            speed_y = 0;
            if(hitbox->dy < 0)
            {
                in_jump = false;
                animRun();
            }
        }

        hitbox->solve();
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
    if(currentAnimation != 1)
    {
        frameMin = 1;
        frameMax = 4;
        frameRate = 5;

        currentAnimation = 1;
    }
}

void CFaith::animJump()
{
    if(currentAnimation != 2)
    {
        frameMin = 5;
        frameMax = 5;
        frameRate = 1;

        currentFrame = 5;

        currentAnimation = 2;
    }
}

void CFaith::animSlide()
{

}

