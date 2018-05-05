#ifndef _BAR_H_
#define _BAR_H_

#include "DxPortLib/DxLib.h"

class Bar {
private:
    // x座標，y座標
    int x, y;
    // 画像の横，縦幅
    int width, height;
    // バーの移動速度
    int speed;
    // 終了フラグ．終了ならtrue
    bool endFlag;
    // グラフィックハンドル
    int graphicHandle;

    void Draw();
    void KeyGet();
    // void Destroy();

public:
    Bar();
    // ~Bar();
    bool All();
    int GetX();
    int GetY();
    int GetWidth();
    int GetHeight();
};

#endif
