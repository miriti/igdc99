#include "CApplication.h"
#include "CLog.h"

#include <stdio.h>

/**
 * Constructor
 *
 */
CApplication::CApplication(char * title, int screenWidth, int screenHeight)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);

    if(window == NULL)
    {
        // Error
        this->Terminate();
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);

    running=true;
}

/**
 * Destructor
 */
CApplication::~CApplication()
{
    this->Terminate();
}

/**
 * Terminate the application
 */
int CApplication::Terminate()
{
    SDL_Quit();
    return 0;
}

/**
 * Run the application
 */
void CApplication::Run()
{
    while(running)
    {
        SDL_Event event;
        SDL_PollEvent(&event);

        switch(event.type)
        {
        case SDL_QUIT:
            running = false;
            break;
        }

        SDL_RenderClear(renderer);

        if(coreDisplayObject != NULL)
        {
            coreDisplayObject->update(16);
            coreDisplayObject->render();
        }

        SDL_RenderPresent(renderer);
    }
}

void CApplication::setCoreDisplay(CDisplayObject* displayObject)
{
    coreDisplayObject = displayObject;
}

