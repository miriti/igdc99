#ifndef CGAMEROOT_H
#define CGAMEROOT_H

#include "../engine/CDisplayObject.h"
#include "../engine/CImage.h"

class CGameRoot : public CDisplayObject
{
    public:
        CGameRoot();
        virtual ~CGameRoot();
    protected:
        void update(unsigned int deltaTime);
    private:
        CImage * image;
};

#endif // CGAMEROOT_H
