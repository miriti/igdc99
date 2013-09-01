#ifndef CDISPLAYOBJECT_H
#define CDISPLAYOBJECT_H

#include <vector>


class CDisplayObject
{
    public:
        CDisplayObject();
        virtual ~CDisplayObject();
        void addChild(CDisplayObject * child);
        void removeChild(CDisplayObject * child);
        virtual void render();
        virtual void update(unsigned int deltaTime);
    protected:
    private:
        std::vector<CDisplayObject*> children;
};

#endif // CDISPLAYOBJECT_H
