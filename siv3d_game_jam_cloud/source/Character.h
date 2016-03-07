//
// Character.h
//

#pragma once

// キャラクター基底クラス
class Character
{
protected:
    // 座標
    Vec3 location;
    // 体力
    float hit_point;
    // 攻撃力
    float attack;
    // コスト
    float cost;

public:
    Character();
    ~Character();

    // 更新
    virtual void update() = 0;
    // 描画
    virtual void draw() = 0;
};
