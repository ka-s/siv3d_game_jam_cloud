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

public:
    Enemy();
    ~Enemy();

    // 更新
    void update() override;
    // 描画
    void draw() override;

    // 移動
    void move();
};
