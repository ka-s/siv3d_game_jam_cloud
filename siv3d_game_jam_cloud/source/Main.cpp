//
// Main.cpp
//

#include "stdafx.h"

using namespace std;

void Main()
{
    // ウィンドウタイトル
    Window::SetTitle(F_TITLE);
    // ウィンドウサイズ
    Window::Resize(MAX_X, MAX_Y);

    // ゲームインスタンス作成
    auto game = make_shared<Game>();

    while (System::Update())
    {
        // ゲームを走らせる
        game->run();
    }
}
