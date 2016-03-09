//
// Enemy.cpp
//

#include "stdafx.h"

Enemy::Enemy()
{
    // ˆÚ“®‘¬“x
    speed = 1.f;
}

Enemy::~Enemy()
{

}

// XV
void Enemy::update()
{
    // “®‚­
    move();
}

// •`‰æ
void Enemy::draw()
{

}

// ˆÚ“®
void Enemy::move()
{
    location.x -= speed;
}
