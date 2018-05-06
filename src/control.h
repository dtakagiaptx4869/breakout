#ifndef _CONTROL_H_
#define _CONTROL_H_

#include "DxPortLib/DxLib.h"
#include "define.h"
#include "bar.h"
#include "ball.h"
#include "block.h"

class Control {
private:
    Bar *bar;
    Ball *ball;
    Block *block[12];

    // ボール，バー，ブロックの座標
    int ball_x;
    int ball_y;
    int bar_x;
    int bar_y;
    int block_x;
    int block_y;

    // ボール，バー，ブロックの画像の幅と高さ
    int ball_width;
    int ball_height;
    int bar_width;
    int bar_height;
    int block_width;
    int block_height;

    // バウンド音とぶつかり音のフラグ
    bool boundFlag;
    bool demolishFlag;

    // サウンドハンドル
    int boundSoundHandle;
    int demolishSoundHandle;

    void HitCheckBallAndBar();
    // void HitCheckBallAndBlock();
    // void SoundPlay();

public:
    Control();
    ~Control();
    bool All();
};
#endif
