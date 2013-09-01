#ifndef CAPPLICATION_H
#define CAPPLICATION_H

#include <SDL.h>
#include "CDisplayObject.h"

class CApplication: public CDisplayObject
{
    public:
        CApplication(char * title, int screenWidth, int screenHeight);
        virtual ~CApplication();
        void Run();
        void setCoreDisplay(CDisplayObject * displayObject);
        int Terminate();
        SDL_Window * window;
        SDL_Renderer * renderer;
        static CApplication * instance;
        int displayWidth;
        int displayHeight;
    protected:
        bool running;
    private:
        CDisplayObject * coreDisplayObject;
};

#endif // CAPPLICATION_H
