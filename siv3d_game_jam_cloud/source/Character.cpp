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
