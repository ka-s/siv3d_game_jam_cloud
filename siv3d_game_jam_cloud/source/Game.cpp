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
    // シーンを更新
    scene->update(&next_scene);
}

// 描画
void Game::draw()
{
    // シーンを描画
    scene->draw();
}

// ゲームを走らせる
void Game::run()
{
    update();
    draw();
}
