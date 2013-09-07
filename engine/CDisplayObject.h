#ifndef CDISPLAYOBJECT_H
#define CDISPLAYOBJECT_H

#include <vector>
#include <SDL_render.h>
#include <SDL_rect.h>
#include <SDL_keyboard.h>

#include "CInput.h"

class CDisplayObject
{
    public:
        CDisplayObject();
        virtual ~CDisplayObject();
        void addChild(CDisplayObject * child);
        void removeChild(CDisplayObject * child, bool dispose = false);
        void setParent(CDisplayObject * newParent);
        virtual void onKeyDown(SDL_Keycode keyCode);
        virtual void onKeyUp(SDL_Keycode keyCode);
        virtual void render(SDL_Renderer * renderer);
        virtual void update(unsigned int deltaTime);
        float globalX();
        float globalY();
        float x;
        float y;
        float w;
        float h;
        float rotation;
        bool kill;
    protected:
        SDL_Rect rect;
        CDisplayObject* parent;
        CInput * getInput();
    private:
        std::vector<CDisplayObject*> children;
};

#endif // CDISPLAYOBJECT_H
