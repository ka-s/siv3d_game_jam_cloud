//
// Spider.cpp
//

#include "stdafx.h"

Spider::Spider(Vec3 _location)
{
    // 座標
    location = _location;
    // 体力
    hit_point = 5.f;
    // 攻撃力
    attack = 1.f;
    // コスト
    cost = 2.f;
    // 移動速度
    speed = (32.f - 8.f) / (60.f * 8.f);
    // se
    se = Sound(L"Assets/se_spider/ani_fa_mon03.mp3");

    // メッシュ
    mesh = Model(L"Assets/spider/spider01.obj");
    // テクスチャ
    t_base = Texture(L"Assets/spider/spider_desert.tex.tga");
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
    // 原点補正
    Vec3 _location = location - Vec3(0.f, 0.5f, 0.f);
    // メッシュ
    mesh.nodes().at(0).mesh
        .scaled(Vec3(0.1f, 0.1f, 0.1f))
        .rotated(Vec3(0.f, Radians(90.f), 0.f))
        .translated(_location)
        .draw(t_base);
}
