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
    // 当たり判定タイプ
    eCollision collision;
    // 行動SE
    Sound se;

public:
    Character();
    ~Character();

    // 更新
    virtual void update() = 0;
    // 描画
    virtual void draw() = 0;

    // 被ダメージ
    void damage(float _damage);
    // 死亡処理
    bool is_dead();
    // 行動SE
    void action_se();

    // コスト取得
    float get_cost();
    // 攻撃力取得
    float get_attack();
    // 当たり判定タイプ取得
    eCollision get_collision();
};
