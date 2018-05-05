#include "ball.h"
#include "define.h"
#include "DxPortLib/DxLib.h"

// コンストラクタ
Ball::Ball() {
    // 画像の読み込みとサイズの取得
    graphicHandle = LoadGraph("../image/ball.bmp");
    GetGraphSize(graphicHandle, &width, &height);

    // y座標は固定なのでここで設定
    y = 410;

    // 最初は真ん中
    x = WINDOW_WIDTH / 2;

    // 最初の係数
    dx = 3;
    dy = -3;

    endFlag = false;
    soundFlag = false;
}

void Ball::Draw() {
    DrawGraph(x-width/2, y-height/2, graphicHandle, TRUE);
}
