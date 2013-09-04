#ifndef CHITBOX_H
#define CHITBOX_H

#include <vector>

using namespace std;

class CHitbox
{
    public:
        CHitbox(float nx, float ny, float nw, float nh, bool dynamic = false);
        virtual ~CHitbox();
        float x, y, w, h, dx, dy, halfW, halfH;
        bool collision;
        void solve();
        void updatePosition(float nx, float ny);
        void updateSize(float nw, float nh);
        void test(CHitbox * against);
        void addChild(CHitbox * child);

        float left();
        float right();
        float top();
        float bottom();
    protected:
        vector<CHitbox*> children;
    private:
};

#endif // CHITBOX_H
