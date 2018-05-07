#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "DxLib.h"
#include "define.h"

class Block {
private:
    // 座標
    int x;
    int y;

    // 縦，横幅
    int width;
    int height;

    // ブロックが壊れているか否かのフラグ
    bool brokenFlag;

    // グラフィックハンドル
    // 全て同じ画像なので静的変数にして共有
    static int graphicHandle;

    // フェード描画用カウント
    int count;
    int countMax;

    void Draw();

public:
    Block(int, int);
    int GetX();
    int GetY();
    int GetWidth();
    int GetHeight();
    void SetBrokenFlag(bool);
    bool GetBrokenFlag();
    void All();
};

#endif
