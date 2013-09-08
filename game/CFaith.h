#ifndef CFAITH_H
#define CFAITH_H

#include <SDL2/SDL_mixer.h>
#include <vector>

#include "../engine/CMovieClip.h"

#include "CHitbox.h"

class CFaith: public CMovieClip
{
    public:
        CFaith();
        virtual ~CFaith();
        void update(unsigned int deltaTime);

        void setFrame(int num);

        float speed_x;
        float speed_y;

        void animStill();
        void animRun();
        void animJump();
        void animSlide();

        CHitbox * hitbox;
    protected:
    private:
        int step_frame_count;
        Mix_Chunk* snd_step;
        Mix_Chunk* snd_jump_0;
        Mix_Chunk* snd_jump_1;
        int currentAnimation;
        bool in_jump;
};

#endif // CFAITH_H
