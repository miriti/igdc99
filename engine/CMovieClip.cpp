#include "CMovieClip.h"

#include "CImageLoader.h"

CMovieClip::CMovieClip(char* path, int newFrameWidth, int newFrameHeight)
{
    surface = CImageLoader::getImage(path);
    texture = CImageLoader::getTextureFromSurface(surface);
    w = newFrameWidth;
    h = newFrameHeight;
    frameRect.x = frameRect.y = x = y = 0;

    frameRect.w = frameWidth = newFrameWidth;
    frameRect.h = frameHeight = newFrameHeight;

    frameMax = totalFrames = surface->clip_rect.w / newFrameWidth;
    frameMin = 0;
}

CMovieClip::~CMovieClip()
{
    //dtor
}

void CMovieClip::play()
{

}

void CMovieClip::stop()
{

}

void CMovieClip::pause()
{

}

void CMovieClip::render(SDL_Renderer * renderer)
{
    SDL_RenderCopyEx(renderer, texture, &frameRect, &rect, 0, NULL, flipHorisontal ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
}

void CMovieClip::update(unsigned int deltaTime)
{
    CDisplayObject::update(deltaTime);
    if(frameTime >= (1000 / frameRate))
    {
        setFrame(currentFrame+1);
        frameTime = 0;
    }
    else
    {
        frameTime+=deltaTime;
    }
}

void CMovieClip::setFrame(int num)
{
    if(num > frameMax) num = frameMin;
    if(num < frameMin) num = frameMax;

    frameRect.x = num * frameWidth;

    currentFrame = num;
}
