//
// Character.cpp
//

#include "stdafx.h"

Character::Character()
{
    // 座標
    location = Vec3(0.f, 0.f, 0.f);
    // 体力
    hit_point = 1.f;
    // 攻撃力
    attack = 1.f;
    // コスト
    cost = 1.f;
}

Character::~Character()
{

}

// 被ダメージ
void Character::damage(float _damage)
{
    hit_point -= _damage;
}

// 死亡処理
bool Character::is_dead()
{
    if (hit_point <= 0)
    {
        return true;
    }

    return false;
}

// コスト取得
float Character::get_cost()
{
    return cost;
}

// 攻撃力取得
float Character::get_attack()
{
    return attack;
}
