//
// Title.cpp
//

#include "stdafx.h"

Title::Title()
{
    // タイトルテキストの大きさ設定
    f_title = Font(32);
    // サブテキストの大きさを設定
    f_sub_text = Font(32);
}

Title::~Title()
{

}

// 更新
void Title::update(eScene* _next_scene)
{
    // クリックでメインゲーム画面へ
    if (Input::MouseL.clicked)
        *_next_scene = GAME;
}

// 描画
void Title::draw()
{
    // タイトルテキスト描画
    f_title(F_TITLE).drawCenter(MAX_X / 2, MAX_Y / 2);
    // サブテキスト描画
    f_sub_text(L"Click to Start").drawCenter(MAX_X / 2, MAX_Y / 2 + 128);
}
