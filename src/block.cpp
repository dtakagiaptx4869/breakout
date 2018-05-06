#include "block.h"

int Block::graphicHandle = -1;

Block::Block(int x, int y) {
    // 画像は最初にインスタンスが生成されたときのみ呼び出す
    if (graphicHandle == -1) graphicHandle = LoadGraph("../image/block.bmp");
    GetGraphSize(graphicHandle, &width, &height);

    brokenFlag = false;
    this->x = x;
    this->y = y;

    count = 0;
    countMax = 40;
}

void Block::Draw() {
    // ブロックが壊れてないときだけ描画
    if (!brokenFlag) {
        DrawGraph(x-width/2, y-height/2, graphicHandle, FALSE);
    } /* else {
        if (count < countMax) {
            // 透過度を設定
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, (255/countMax)*(countMax-count));
            // 描画
            DrawGraph(x-width/2, y-height/2, graphicHandle, FALSE);
            // 設定を戻す
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0);
            count++;
        }
    } */
}

int Block::GetX() {
    return x;
}

int Block::GetY() {
    return y;
}

int Block::GetWidth() {
    return width;
}

int Block::GetHeight() {
    return height;
}

void Block::SetBrokenFlag(bool brokenFlag) {
    this->brokenFlag = brokenFlag;
}

bool Block::GetBrokenFlag() {
    return brokenFlag;
}

void Block::All() {
    Draw();
}
