#include "DxPortLib/DxLib.h"
#include "control.h"
#include "define.h"

char key[256];

int main(int argc, char const* argv[]) {
    ChangeWindowMode(TRUE);

    if (DxLib_Init() == -1) return -1;

    SetDrawScreen(DX_SCREEN_BACK);

    Control *control = new Control();

    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && GetHitKeyStateAll(key) == 0) {
        if (control->All()) break;
    }

    DxLib_End();
    return 0;
}
