//
// Enemy.cpp
//

#include "stdafx.h"

Enemy::Enemy()
{
    // �ړ����x
    speed = 1.f;
}

Enemy::~Enemy()
{

}

// �X�V
void Enemy::update()
{
    // ����
    move();
}

// �`��
void Enemy::draw()
{

}

// �ړ�
void Enemy::move()
{
    location.x -= speed;
}
