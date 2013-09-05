#include "CFaith.h"
#include "CCity.h"

#include "../engine/CApplication.h"

#include <iostream>

#define FAITH_MAX_SPEED     3.f
#define FAITH_GRAVITY       0.05f
#define FAITH_JUMP_POWER    2.f

CFaith::CFaith(): CMovieClip("data/gfx/sprites/faith/faith_anim.png", 32, 32)
{
    currentAnimation = -1;
    speed_x = speed_y = 0;
    hitbox = new CHitbox(0, 0, 8, 14, this);
    animStill();
}

CFaith::~CFaith()
{
    //dtor
}

void CFaith::update(unsigned int deltaTime)
{
    if(!in_jump)
    {
        if(getInput()->isLeft())
        {
            speed_x -= 0.1;
            if(speed_x < -FAITH_MAX_SPEED)
                speed_x = -FAITH_MAX_SPEED;
        }

        if(getInput()->isRight())
        {
            speed_x += 0.1;

            if(speed_x > FAITH_MAX_SPEED)
                speed_x = FAITH_MAX_SPEED;
        }
    }

    if(getInput()->isUp())
    {
        if(!in_jump)
        {
            in_jump = true;
            speed_y = -FAITH_JUMP_POWER;
        }
    }

    speed_y += FAITH_GRAVITY;


    if(speed_x != 0)
    {
        if(currentAnimation != 1)
            animRun();

        frameRate = 5 + abs(speed_x) * 5;

        flipHorisontal = (speed_x < 0);
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

}

void CFaith::animSlide()
{

}

