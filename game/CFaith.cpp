#include "CFaith.h"
#include "CCity.h"
#include "CGameMain.h"
#include "CGameRoot.h"

#include "../engine/CApplication.h"

#include <iostream>
#include <stdlib.h>

#define FAITH_MAX_SPEED     6.f
#define FAITH_GRAVITY       0.15f
#define FAITH_JUMP_POWER    3.5f
#define FAITH_ACCELERATION  0.003f

CFaith::CFaith(): CMovieClip("data/gfx/sprites/faith/faith_anim.png", 32, 32)
{
    currentAnimation = -1;
    animStill();

    speed_x = 2.f;
    speed_y = 0;
    hitbox = new CHitbox(0, 0, 8, 14, this);

    snd_step = CAudio::loadSound("data/sound/sfx/step.wav", false);
    snd_jump_0 = CAudio::loadSound("data/sound/sfx/jump_0.wav", false);
    //snd_jump_1 = CAudio::loadSound("data/sound/sfx/jump_1.wav", false);

    step_frame_count = 0;
}

CFaith::~CFaith()
{
}

void CFaith::update(unsigned int deltaTime)
{
    if(y > CITY_GROUND_LEVEL)
    {
        CGameMain * newGameMain = new CGameMain();
        CGameRoot::instance->setState(newGameMain, false);
        return;
    }

    if((getInput()->isUp()) || (getInput()->isKeyDown(SDLK_x)))
    {
        if(!in_jump)
        {
            in_jump = true;
            speed_y = -FAITH_JUMP_POWER;
            CAudio::play(snd_jump_0);
            animJump();
        }
    }

    speed_y += FAITH_GRAVITY;

    if(speed_x < FAITH_MAX_SPEED)
    {
        if(!in_jump)
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
    }else{
        in_jump = true;
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

