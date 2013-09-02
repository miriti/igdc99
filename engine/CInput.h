#ifndef CINPUT_H
#define CINPUT_H

#include <map>
#include <SDL_keyboard.h>

class CInput
{
    public:
        void onKeyDown(SDL_Keycode keySym);
        void onKeyUp(SDL_Keycode keySym);
        bool isKeyDown(SDL_Keycode keySym);
        bool isLeft();
        bool isRight();
        bool isUp();
        bool isDown();
    protected:
        std::map<SDL_Keycode, bool> keysDown;
    private:
};

#endif // CINPUT_H
