//
// Result.cpp
//

#include "stdafx.h"

Result::Result()
{
    // フォント
    f_text = Font(64);
    f_sub_text = Font(32);
}

Result::~Result()
{

}

// 更新
void Result::update(eScene* _next_scene)
{
    // クリックでタイトル画面へ
    if (Input::MouseL.clicked)
        *_next_scene = TITLE;
}

// 描画
void Result::draw()
{
    f_text(L"Game Over...").drawCenter(MAX_X / 2, MAX_Y / 2);
    f_sub_text(L"Click to Title").drawCenter(MAX_X / 2, MAX_Y / 2 + 128);
}
