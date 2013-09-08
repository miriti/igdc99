#ifndef CAPPLICATION_H
#define CAPPLICATION_H

#include <SDL.h>
#include "CDisplayObject.h"
#include "CInput.h"
#include "CAudio.h"

class CApplication: public CDisplayObject
{
    public:
        CApplication(char * title, int screenWidth, int screenHeight, int sceneWidth=-1, int sceneHeight = -1);
        virtual ~CApplication();
        void Run();
        void setCoreDisplay(CDisplayObject * displayObject);
        int Terminate();
        SDL_Window * window;
        SDL_Renderer * renderer;
        static CApplication * instance;
        int displayWidth;
        int displayHeight;
        CInput input;
    protected:
        bool running;
    private:
        CDisplayObject * coreDisplayObject;
};

#endif // CAPPLICATION_H
