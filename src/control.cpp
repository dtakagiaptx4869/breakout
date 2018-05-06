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
