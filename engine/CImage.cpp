#include "CImage.h"
#include "CImageLoader.h"

#include <iostream>

using namespace std;

CImage::CImage(SDL_Surface* imageSurface)
{
    fromSurfcae(imageSurface);
}

CImage::CImage(char* filePath)
{
    SDL_Surface * newSurface = CImageLoader::getImage(filePath);
    fromSurfcae(newSurface);
}


CImage::~CImage()
{
    if(this->texture != NULL)
    {
        SDL_DestroyTexture(this->texture);
    }
}

void CImage::render(SDL_Renderer * renderer)
{
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    SDL_RenderCopyEx(renderer, this->texture, NULL, &this->rect, this->rotation, NULL, flip);
}

SDL_Surface* CImage::getSurface()
{
    return surface;
}

SDL_Texture* CImage::getTexture()
{
    return texture;
}

void CImage::fromSurfcae(SDL_Surface* imageSurface)
{
    surface = imageSurface;
    texture = CImageLoader::getTextureFromSurface(imageSurface);
    w = imageSurface->clip_rect.w;
    h = imageSurface->clip_rect.h;
    x = y = 0;
}

