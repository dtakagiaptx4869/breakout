#include "DxPortLib/DxLib.h"
#include "bar.h"
#include "define.h"

char key[256];

int main(int argc, char const* argv[]) {
    ChangeWindowMode(TRUE);

    if (DxLib_Init() == -1) return -1;

    SetDrawScreen(DX_SCREEN_BACK);

    Bar *bar = new Bar();

    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && GetHitKeyStateAll(key) == 0) {
        if (bar->All()) break;
    }

    DxLib_End();
    delete bar;
    return 0;
}
