//
// Game.cpp
//

#include "stdafx.h"

using namespace std;

Game::Game()
{
    // タイトルを初期シーンに設定
    scene = make_shared<Title>();
}

Game::~Game()
{

}

// 更新
void Game::update()
{
    // シーン切り替え
    scene_changer();

    // シーンを更新
    scene->update(&next_scene);
}

// 描画
void Game::draw()
{
    // シーンを描画
    scene->draw();
}

// シーン切り替え
void Game::scene_changer()
{
    // シーン切り替え
    if (now_scene != next_scene)
    {
        switch (next_scene)
        {
        case TITLE:
            scene = make_shared<Title>();
            break;
        case GAME:
            scene = make_shared<Play>();
            break;
        case RESULT:
            scene = make_shared<Result>();
            break;
        }
        // シーン番号更新
        now_scene = next_scene;
    }
}

// ゲームを走らせる
void Game::run()
{
    update();
    draw();
}
