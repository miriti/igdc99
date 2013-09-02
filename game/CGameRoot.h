#ifndef CGAMEROOT_H
#define CGAMEROOT_H

#include "../engine/CDisplayObject.h"
#include "../engine/CImage.h"

class CGameRoot : public CDisplayObject
{
    public:
        CGameRoot();
        virtual ~CGameRoot();
        static CGameRoot * instance;
        void setState(CDisplayObject * newState);
    private:
        CDisplayObject * currentState;
};

#endif // CGAMEROOT_H
