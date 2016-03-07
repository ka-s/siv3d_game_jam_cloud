//
// Soldier.cpp
//

#include "stdafx.h"

Soldier::Soldier(Vec3 _location)
{
    // 座標
    location = _location;
    // 体力
    hit_point = 180.f;
    // 攻撃力
    attack = 1.f;
    // コスト
    cost = 1.f;

    // メッシュ
    mesh = Box(location, 1);
}

Soldier::~Soldier()
{

}

// 更新
void Soldier::update()
{

}

// 描画
void Soldier::draw()
{
    // メッシュ描画
    mesh.setPos(location);
    mesh.draw(Palette::Aqua);
}
