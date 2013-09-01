#include "engine/CApplication.h"

int main(int argc, char** argv){
    CApplication * app = new CApplication("IGDC #99 by Michael KEFIR Miriti", 1024, 576);
    app->Run();
    return app->Terminate();
}
