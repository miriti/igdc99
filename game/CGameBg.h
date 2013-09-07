#ifndef CGAMEBG_H
#define CGAMEBG_H

#include "../engine/CDisplayObject.h"
#include "../engine/CImage.h"

class CGameBg: public CDisplayObject
{
    public:
        CGameBg();
        virtual ~CGameBg();
        void parallax(float delta_x, float delta_y);
    protected:
    private:
        float d_layer0;
        float d_layer1;
        float y_layer0;
        float y_layer1;
        CImage * sky;
        CImage * buildings0[2];
        CImage * buildings1[2];
};

#endif // CGAMEBG_H
