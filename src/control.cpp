#include "control.h"

Control::Control() {
    // バーとボールのインスタンスを生成
    bar  = new Bar();
    ball = new Ball();

    boundFlag    = false;
    demolishFlag = false;

    // バーの幅と高さを取得
    bar_width  = bar->GetWidth();
    bar_height = bar->GetHeight();

    // ボールの幅と高さを取得
    ball_width  = ball->GetWidth();
    ball_height = ball->GetHeight();

    // 音楽ファイルの読み込み
    boundSoundHandle    = LoadSoundMem("../sound/bound.wav");
    demolishSoundHandle = LoadSoundMem("../sound/demolish.wav");

    // ブロックの間を50ピクセルあけて，4列3行で配置
    // 左端が45ピクセルの位置なる，それに画像の横幅の半分を足す
    for (int i = 0; i < 12; i++) {
        if (i < 4) {
            block[i] = new Block(95+(50+100)*i, 50*1);
        } else if (i > 3 && i < 8){
            block[i] = new Block(95+(50+100)*(i-4), 50*2);
        } else {
            block[i] = new Block(95+(50+100)*(i-8), 50*3);
        }
    }

    // ブロックの横幅と縦幅を取得
    block_width  = block[0]->GetWidth();
    block_height = block[0]->GetHeight();
}

Control::~Control() {
    delete bar;
    delete ball;
    for (int i = 0; i < 12; i++) {
        delete block[i];
    }
}

// ボールとバーの当たり判定
void Control::HitCheckBallAndBar() {
    // ボールクラス内での音フラグを取得
    boundFlag = ball->GetSoundFlag();

    // バーの座標を取得
    bar_x = bar->GetX();
    bar_y = bar->GetY();

    // ボールの座標を取得
    ball_x = ball->GetX();
    ball_y = ball->GetY();

    // ボールとバーの高さの半分を足したものよりも
    // バーの中心とボールの中心の距離の絶対値の方が小さかったら当たり
    // その距離より大きいやつは除外
    if (abs(bar_y-ball_y) < bar_height/2+ball_height/2) {
        // かつ，ボールがバー内にあれば当たり
        if (bar_x+bar_width/2 > ball_x && bar_x-bar_width/2 < ball_x) {
            // バーの左端に当たってる場合
            if (ball_x < bar_x-bar_width/2*2/3) {
                // ボールを反転
                ball->SetDX(-1*ball->GetDX());
                // yは跳ね返すだけ
                ball->SetDY(-1*ball->GetDY());
                // バウンド音フラグを立てる
                boundFlag = true;
            // バーの右端に当たっている場合
            } else if (ball_x > bar_x+bar_width/2*2/3) {
                // ボールを反転
                ball->SetDX(-1*ball->GetDX());
                // yは跳ね返すだけ
                ball->SetDY(-1*ball->GetDY());
                // バウンド音フラグを立てる
                boundFlag = true;
            // それ以外
            } else {
                // xは何もしない
                // yは跳ね返すだけ
                ball->SetDY(-1*ball->GetDY());
                // バウンド音フラグを立てる
                boundFlag = true;
            }
        }
    }
}

bool Control::All() {
    bool endFlag = false;
    HitCheckBallAndBar();
    endFlag += bar->All();
    endFlag += ball->All();
    for (int i = 0; i < 12; i++) {
        block[i]->All();
    }

    return endFlag;
}
