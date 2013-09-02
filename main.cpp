#include <cstddef>
#include "engine/CApplication.h"
#include "game/CGameRoot.h"

int main(int argc, char** argv){
    CApplication * app = new CApplication("IGDC #99", 640, 480, 160, 120);

    CGameRoot * gameRoot = new CGameRoot();
    app->setCoreDisplay(gameRoot);

    app->Run();

    return app->Terminate();
}
