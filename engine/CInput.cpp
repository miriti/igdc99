#include "CInput.h"

void CInput::onKeyDown(SDL_Keycode keySym)
{
    keysDown[keySym] = true;
}

void CInput::onKeyUp(SDL_Keycode keySym)
{
    keysDown[keySym] = false;
}

bool CInput::isKeyDown(SDL_Keycode keySym)
{
    return keysDown.find(keySym) == keysDown.end() ? false : keysDown[keySym];
}

bool CInput::isLeft()
{
    return isKeyDown(SDLK_LEFT) || isKeyDown(SDLK_a);
}

bool CInput::isRight()
{
    return isKeyDown(SDLK_RIGHT) || isKeyDown(SDLK_d);
}

bool CInput::isUp()
{
    return isKeyDown(SDLK_UP) || isKeyDown(SDLK_w);
}

bool CInput::isDown()
{
    return isKeyDown(SDLK_DOWN) || isKeyDown(SDLK_s);
}
