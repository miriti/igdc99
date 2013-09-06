#include "CImageLoader.h"
#include "CApplication.h"

#include <iostream>
#include <stdlib.h>

using namespace std;

SDL_Surface* CImageLoader::getImage(char* path)
{
    if(loadedSurfaces.find(path) != loadedSurfaces.end())
    {
        return loadedSurfaces[path];
    }
    else
    {
        cout << "Loading surface from: " << path << endl;
        SDL_Surface * newSurface =IMG_Load(path);

        if(newSurface != NULL)
        {
            loadedSurfaces[path] = newSurface;
            return newSurface;
        }
        else
        {
            cerr << "Error while loading Surface from <" << path << ">: " << SDL_GetError() << endl;
        }
    }

    return NULL;
}

/**
 * Loading image and creating texture from it
 *
 */
SDL_Texture* CImageLoader::getTexture(char* path)
{
    SDL_Surface * surface = CImageLoader::getImage(path);

    if(surface == NULL)
    {
        cerr << "Error while loading <" << path << ">: " << SDL_GetError() << endl;
    }
    else
    {
        return CImageLoader::getTextureFromSurface(surface);
    }

    return NULL;
}

SDL_Texture* CImageLoader::getTextureFromSurface(SDL_Surface* surface)
{
    if(loadedTextures.find(surface) != loadedTextures.end())
    {
        return loadedTextures[surface];
    }
    else
    {
        SDL_Texture * newTexture = SDL_CreateTextureFromSurface(CApplication::instance->renderer, surface);

        if(newTexture != NULL)
        {
            cout << "Texture loaded (" << surface->w << "x" << surface->h << ")" << endl;
            loadedTextures[surface] = newTexture;
            return newTexture;
        }
        else
        {
            cerr << "Error while creating texture from surface: " << SDL_GetError() << endl;
        }
    }

    return NULL;
}


std::map<char*, SDL_Surface*> CImageLoader::loadedSurfaces;
std::map<SDL_Surface*, SDL_Texture*> CImageLoader::loadedTextures;
