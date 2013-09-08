#include "CApplication.h"
#include "CLog.h"

#include <iostream>

using namespace std;

CApplication * CApplication::instance = NULL;

/**
 * Constructor
 *
 */
CApplication::CApplication(char * title, int screenWidth, int screenHeight, int sceneWidth, int sceneHeight)
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
        if((sceneWidth != -1)&&(sceneHeight != -1))
        {
            SDL_RenderSetLogicalSize(renderer, sceneWidth, sceneHeight);
            this->displayWidth = sceneWidth;
            this->displayHeight = sceneHeight;
        }
        else
        {
            this->displayWidth = screenWidth;
            this->displayHeight = screenHeight;
        }

        SDL_SetRenderDrawColor(renderer, 0x64, 0x95, 0xed, 0xff);

        running = true;
    }

    CAudio::Init();

    parent = NULL;

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
        case SDL_KEYDOWN:
            input.onKeyDown(event.key.keysym.sym);
            break;
        case SDL_KEYUP:
            input.onKeyUp(event.key.keysym.sym);
            break;
        }

        SDL_RenderClear(renderer);

        if(coreDisplayObject != NULL)
        {
            coreDisplayObject->update(deltaTime);
            coreDisplayObject->render(renderer);
        }

        SDL_RenderPresent(renderer);
    }
}

void CApplication::setCoreDisplay(CDisplayObject* displayObject)
{
    coreDisplayObject = displayObject;
    addChild(coreDisplayObject);
}
