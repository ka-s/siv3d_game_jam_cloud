//
// Enemy.cpp
//

#include "stdafx.h"

Enemy::Enemy()
{
    // 移動速度
    speed = 1.f;
    // 当たり判定タイプ
    collision = ENEMY;
}

Enemy::~Enemy()
{

}

// 更新
void Enemy::update()
{
    // 動く
    move();
}

// 描画
void Enemy::draw()
{

}

// 移動
void Enemy::move()
{
    location.x -= speed;
}
