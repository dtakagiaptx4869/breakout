#include "DxPortLib/DxLib.h"
#include "control.h"
#include "define.h"

char key[256];

int main(int argc, char const* argv[]) {
    ChangeWindowMode(TRUE);

    // DXライブラリ初期化
    if (DxLib_Init() == -1) return -1;

    // 裏画面へ描画
    SetDrawScreen(DX_SCREEN_BACK);

    // コントロールインスタンスを生成
    Control *control = new Control();

    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && GetHitKeyStateAll(key) == 0) {
        // ゲームオーバーでtrueを返す
        if (control->All()) break;
    }

    // 終了処理
    DxLib_End();
    delete control;
    return 0;
}
