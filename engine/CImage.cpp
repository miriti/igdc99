#include "CImage.h"
#include "CApplication.h"
#include "CImageLoader.h"

#include <iostream>

using namespace std;

CImage::CImage(SDL_Surface* imageSurface)
{
    surface = imageSurface;
    texture = CImageLoader::getTextureFromSurface(imageSurface);
    w = imageSurface->clip_rect.w;
    h = imageSurface->clip_rect.h;
    x = y = 0;
}

CImage::~CImage()
{
    if(this->texture != NULL)
    {
        SDL_DestroyTexture(this->texture);
    }
}

void CImage::render()
{
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    SDL_RenderCopyEx(CApplication::instance->renderer, this->texture, NULL, &rect, this->rotation, NULL, flip);
}
