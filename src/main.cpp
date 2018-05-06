#include "DxPortLib/DxLib.h"
#include "bar.h"
#include "ball.h"
#include "block.h"
#include "define.h"

char key[256];

int main(int argc, char const* argv[]) {
    ChangeWindowMode(TRUE);

    if (DxLib_Init() == -1) return -1;

    SetDrawScreen(DX_SCREEN_BACK);

    // test
    Bar *bar     = new Bar();
    Ball *ball   = new Ball();
    Block *block = new Block(100, 100);

    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && GetHitKeyStateAll(key) == 0) {
        block->All();
        if (bar->All()) break;
        if (ball->All()) break;
    }

    DxLib_End();
    delete bar;
    return 0;
}
