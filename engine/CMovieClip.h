#ifndef CMOVIECLIP_H
#define CMOVIECLIP_H

#include "CDisplayObject.h"

class CMovieClip: public CDisplayObject
{
    public:
        CMovieClip(char* path, int newFrameWidth, int newFrameHeight);
        virtual ~CMovieClip();
        void play();
        void stop();
        void pause();
        void render(SDL_Renderer * renderer);
        void update(unsigned int deltaTime);
        void setFrame(int num);
        int frameRate = 24;
        bool flipHorisontal = false;
    protected:
        int totalFrames;
        int frameWidth;
        int frameHeight;
        int currentFrame;
        int frameMin;
        int frameMax;
        SDL_Rect frameRect;
    private:
        unsigned int frameTime = 0;
        SDL_Surface * surface;
        SDL_Texture * texture;
};

#endif // CMOVIECLIP_H
