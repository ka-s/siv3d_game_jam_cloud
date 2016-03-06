//
// Main.cpp
//

#include "stdafx.h"

using namespace std;

void Main()
{
    // ゲームインスタンス作成
    auto game = make_shared<Game>();

    while (System::Update())
    {
        // ゲームを走らせる
        game->run();
    }
}
