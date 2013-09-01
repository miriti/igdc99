#ifndef CDISPLAYOBJECT_H
#define CDISPLAYOBJECT_H

#include <vector>
#include <SDL_rect.h>


class CDisplayObject
{
    public:
        CDisplayObject();
        virtual ~CDisplayObject();
        void addChild(CDisplayObject * child);
        void removeChild(CDisplayObject * child);
        void setParent(CDisplayObject * newParent);
        virtual void render();
        virtual void update(unsigned int deltaTime);
        float x;
        float y;
        float w;
        float h;
        float rotation;
    protected:
        SDL_Rect rect;
        CDisplayObject* parent;
    private:
        std::vector<CDisplayObject*> children;
};

#endif // CDISPLAYOBJECT_H
