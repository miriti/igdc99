#ifndef CHITBOX_H
#define CHITBOX_H

#include <vector>

#include "../engine/CDisplayObject.h"

using namespace std;

class CHitbox
{
    public:
        CHitbox(double nx, double ny, double nw, double nh, CDisplayObject* depender = NULL);
        virtual ~CHitbox();
        double x, y, w, h, dx, dy, halfW, halfH;
        bool collision;
        void solve();
        void updatePosition(double nx, double ny);
        void updateSize(double nw, double nh);
        void test(CHitbox * against);
        void addChild(CHitbox * child);

        double left();
        double right();
        double top();
        double bottom();
    protected:
        vector<CHitbox*> children;
        CDisplayObject* _depender;
    private:
};

#endif // CHITBOX_H
