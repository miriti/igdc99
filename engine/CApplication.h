#ifndef CAPPLICATION_H
#define CAPPLICATION_H

#include <SDL2/SDL.h>
#include "CDisplayObject.h"

class CApplication
{
    public:
        CApplication(char * title, int screenWidth, int screenHeight);
        virtual ~CApplication();
        void Run();
        void setCoreDisplay(CDisplayObject * displayObject);
        int Terminate();
    protected:
        bool running;
    private:
        CDisplayObject * coreDisplayObject;
        SDL_Window * window;
        SDL_Renderer * renderer;
};

#endif // CAPPLICATION_H
