/*
 :    音楽:魔王魂
 :        https://maoudamashii.jokersounds.com/
 :
 :    画像:プログラミング入門サイト ~bituse~
 :        https://bituse.info/
 */


#include "DxLib.h"
#include "control.h"
#include "define.h"

char key[256];

#ifdef DXPORTLIB
int main(int argc, char const* argv[]) {
    SetUseCharSet(DX_CHARSET_EXT_UTF8);
#else
int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int) {
#endif

    // ウィンドウ上部に表示するテキスト
    SetWindowText(_T("breakout"));

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
