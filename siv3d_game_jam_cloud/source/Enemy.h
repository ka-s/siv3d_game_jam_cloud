//
// Enemy.h
//

#pragma once

// 敵サイドのキャラクタークラス
class Enemy : public Character
{
protected:
    // 移動速度
    float speed;
    // 拠点襲撃フラグ
    bool attack_base;

public:
    Enemy();
    ~Enemy();

    // 更新
    void update() override;
    // 描画
    void draw() override;

    // 移動
    void move();
    
    // 拠点襲撃フラグ取得
    bool is_attack_base();
};
