#include "CFaith.h"

#include "../engine/CApplication.h"

#define FAITH_MAX_SPEED 3.f

CFaith::CFaith(): CMovieClip("data/gfx/sprites/faith/faith_anim.png", 32, 32)
{
    currentAnimation = -1;
    speed_x = speed_y = 0;
    hitbox = new CHitbox(0, 0, 8, 14, true);
    animStill();
}

CFaith::~CFaith()
{
    //dtor
}

void CFaith::update(unsigned int deltaTime)
{
    if(hitbox->collision)
    {
        if(hitbox->dx != 0)
        {
            x += hitbox->dx;
            speed_x = 0;
        }

        if(hitbox->dy != 0)
        {
            y += hitbox->dy;
            speed_y = 0;
        }

        hitbox->solve();
    }

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

    if(getInput()->isDown())
    {
        speed_y += 0.1;

        if(speed_y > FAITH_MAX_SPEED)
            speed_y = FAITH_MAX_SPEED;
    }

    if(getInput()->isUp())
    {
        speed_y -= 0.1;

        if(speed_y < -FAITH_MAX_SPEED)
            speed_y = -FAITH_MAX_SPEED;
    }

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

