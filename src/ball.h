#ifndef _BALL_H_
#define _BALL_H_

#include "DxLib.h"
#include "define.h"

class Ball {
private:
    // x座標，y座標
    int x;
    int y;

    // xとyの移動量
    int dx;
    int dy;

    // 画像の横，縦幅
    int width;
    int height;

    // ゲームオーバーフラグ
    bool endFlag;

    // 音を鳴らすかどうかのフラグ
    bool soundFlag;

    // グラフィックハンドル
    int graphicHandle;

    void Draw();
    void Move();
    // void Destroy();

public:
    Ball();
    // ~Ball();
    bool All();
    int GetX();
    int GetY();
    int GetWidth();
    int GetHeight();
    void SetDX(int);
    void SetDY(int);
    int GetDX();
    int GetDY();
    bool GetSoundFlag();
};

#endif
