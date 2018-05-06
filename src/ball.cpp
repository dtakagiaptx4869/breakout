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

void Ball::Move() {
    // まず音をOFFにしておく
    soundFlag = false;

    // 移動量を加算
    x += dx;
    y += dy;

    // 画面はみ出し処理
    if (x < width / 2) {
        x = width / 2;
        dx *= -1;
        // 当たったのでサウンドフラグを立てる
        soundFlag = true;
    }
    if (x > WINDOW_WIDTH - width / 2) {
        x = WINDOW_WIDTH - width / 2;
        dx *= -1;
        // 当たったのでサウンドフラグを立てる
        soundFlag = true;
    }

    if (y < height / 2) {
        y = height / 2;
        dy *= -1;
        // 当たったのでサウンドフラグを立てる
        soundFlag = true;
    }

    // 下にはみ出たらゲームオーバー
    if (y > WINDOW_WIDTH) {
        endFlag = true;
    }
}

void Ball::Draw() {
    DrawGraph(x-width/2, y-height/2, graphicHandle, TRUE);
}

bool Ball::All() {
    Move();

    // 描画処理
    Draw();

    return endFlag;
}

int Ball::GetX() {
    return x;
}

int Ball::GetY() {
    return y;
}

int Ball::GetWidth() {
    return width;
}

int Ball::GetHeight() {
    return height;
}

void Ball::SetDX(int dx) {
    this->dx = dx;
}

void Ball::SetDY(int dy) {
    this->dy = dy;
}

int Ball::GetDX() {
    return dx;
}

int Ball::GetDY() {
    return dy;
}

bool Ball::GetSoundFlag() {
    return soundFlag;
}
