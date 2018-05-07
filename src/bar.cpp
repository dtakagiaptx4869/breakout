#include "bar.h"

// コンストラクタ
Bar::Bar() {
    // 画像をロード
    graphicHandle = LoadGraph("../image/bar.bmp");

    // 画像の横，縦幅を取得
    GetGraphSize(graphicHandle, &width, &height);

    // y座標は固定なのでここで設定
    y = 460 - height / 2;

    // x座標は最初は中央に設定
    x = WINDOW_WIDTH / 2;

    // バーの移動速度を設定
    speed = 4;

    // 終了フラグは偽にしておく
    endFlag = false;
}

// 描画関数
void Bar::Draw() {
    DrawGraph(x-width/2, y-height/2, graphicHandle, TRUE);
}

// バー自体の移動制御用関数
void Bar::KeyGet() {
    if (key[KEY_INPUT_LEFT] == 1) {
        // 左に移動
        x -= speed;
    }
    if (key[KEY_INPUT_RIGHT] == 1) {
        // 左に移動
        x += speed;
    }
    if (key[KEY_INPUT_ESCAPE] == 1) {
        // エスケープキーが押されていれば終了フラグをtrueにする
        endFlag = true;
    }

    // 画面のはみ出し処理
    if (x < width / 2) x = width / 2;
    if (x > WINDOW_WIDTH - width / 2) x = WINDOW_WIDTH - width / 2;
}

// 全体の処理を行うAll関数
bool Bar::All() {
    // キー処理;
    KeyGet();

    // 描画処理
    Draw();

    // 終了フラグを返す
    return endFlag;
}

// xのゲッター
int Bar::GetX() {
    return x;
}

// yのゲッター
int Bar::GetY() {
    return y;
}

// widthのゲッター
int Bar::GetWidth() {
    return width;
}

// heightのゲッター
int Bar::GetHeight() {
    return height;
}
