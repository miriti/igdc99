#include "CApplication.h"
#include "CLog.h"

#include <iostream>

using namespace std;

CApplication * CApplication::instance = NULL;

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
        this->Terminate();
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);

    if(renderer != NULL)
    {
        this->displayWidth = screenWidth;
        this->displayHeight = screenHeight;

        SDL_SetRenderDrawColor(renderer, 0x64, 0x95, 0xed, 0xff);

        running = true;
    }

    CApplication::instance = this;
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
    unsigned int lastTime = SDL_GetTicks();

    while(running)
    {
        unsigned int currentTime = SDL_GetTicks();
        unsigned int deltaTime = currentTime - lastTime;
        lastTime = currentTime;

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
            coreDisplayObject->update(deltaTime);
            coreDisplayObject->render();
        }

        SDL_RenderPresent(renderer);
    }
}

void CApplication::setCoreDisplay(CDisplayObject* displayObject)
{
    coreDisplayObject = displayObject;
    addChild(coreDisplayObject);
}
