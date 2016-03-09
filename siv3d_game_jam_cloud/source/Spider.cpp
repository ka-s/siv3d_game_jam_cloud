//
// Spider.cpp
//

#include "stdafx.h"

Spider::Spider(Vec3 _location)
{
    // 座標
    location = _location;
    // 体力
    hit_point = 60.f;
    // 攻撃力
    attack = 1.f;
    // コスト
    cost = 2.f;
    // 移動速度
    speed = 0.01f;

    // メッシュ
    mesh = Box(location, 1);
}

Spider::~Spider()
{

}

// 更新
void Spider::update()
{
    // 親関数呼び出し
    Enemy::update();
}

// 描画
void Spider::draw()
{
    // メッシュ
    mesh.setPos(location);
    mesh.draw();
}
