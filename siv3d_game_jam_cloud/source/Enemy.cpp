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
    // 拠点襲撃フラグ
    attack_base = false;
}

Enemy::~Enemy()
{

}

// 更新
void Enemy::update()
{
    // 動く
    move();

    // 拠点襲撃チェック
    if (location.x < 8.f)
    {
        attack_base = true;
    }
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

// 拠点襲撃フラグ取得
bool Enemy::is_attack_base()
{
    return attack_base;
}
