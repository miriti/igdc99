#include <cstddef>
#include "engine/CApplication.h"
#include "game/CGameRoot.h"

int main(int argc, char** argv){
    CApplication * app = new CApplication("IGDC #99", 854, 480, 427, 240);

    CGameRoot * gameRoot = new CGameRoot();
    app->setCoreDisplay(gameRoot);

    app->Run();

    return app->Terminate();
}
