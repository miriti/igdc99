#ifndef CIMAGE_H
#define CIMAGE_H

#include "CDisplayObject.h"
#include <SDL.h>


class CImage : public CDisplayObject
{
    public:
        CImage(SDL_Surface* imageSurface);
        CImage(char * filePath);
        virtual ~CImage();
        void render(SDL_Renderer * renderer);
        SDL_Surface* getSurface();
        SDL_Texture* getTexture();
        bool flipHorizontal;
        bool flipVertical;
    protected:
        SDL_Surface* surface;
        SDL_Texture* texture;
    private:
        void fromSurfcae(SDL_Surface * imageSurface);
};

#endif // CIMAGE_H
