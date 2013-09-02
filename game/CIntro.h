#ifndef CINTRO_H
#define CINTRO_H

#include "../engine/CDisplayObject.h"

class CIntro : public CDisplayObject
{
    public:
        CIntro();
        virtual ~CIntro();
        void update(unsigned int deltaTime);
    protected:
    private:
        unsigned int timePassed;
};

#endif // CINTRO_H
