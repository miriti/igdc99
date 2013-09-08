#include <cstddef>
#include <cstring>
#include <iostream>

#include "engine/CApplication.h"
#include "game/CGameRoot.h"

using namespace std;

int main(int argc, char** argv)
{

    for(int i=0; i<argc; i++)
    {
        if(strcmp(argv[i], "-nosnd") == 0)
        {
            CAudio::enabled = false;
            cout << "Running without sound..." << endl;
        }
    }

    CApplication * app = new CApplication("«Run, Faith, Run» - igdc #99 entry by Michael KEFIR Miriti - 1-9 Sep. 2013", 854, 480, 427, 240);

    CGameRoot * gameRoot = new CGameRoot();
    app->setCoreDisplay(gameRoot);

    app->Run();

    return app->Terminate();
}
