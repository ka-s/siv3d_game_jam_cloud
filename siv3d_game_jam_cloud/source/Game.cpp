//
// Game.cpp
//

#include "stdafx.h"

using namespace std;

Game::Game()
{
    // �^�C�g���������V�[���ɐݒ�
    scene = make_shared<Title>();
}

Game::~Game()
{

}

// �X�V
void Game::update()
{
    // �V�[�����X�V
    scene->update(&next_scene);
}

// �`��
void Game::draw()
{
    // �V�[����`��
    scene->draw();
}

// �Q�[���𑖂点��
void Game::run()
{
    update();
    draw();
}
