#ifndef CIMAGELOADER_H
#define CIMAGELOADER_H

#include <SDL.h>
#include <SDL_render.h>
#include <SDL_image.h>
#include <map>

class CImageLoader
{
    public:
        static SDL_Surface* getImage(char* path);
        static SDL_Texture* getTexture(char* path);
        static SDL_Texture* getTextureFromSurface(SDL_Surface * surface);
    private:
        static std::map<char*, SDL_Surface*> loadedSurfaces;
        static std::map<SDL_Surface*, SDL_Texture*> loadedTextures;
};

#endif // CIMAGELOADER_H
