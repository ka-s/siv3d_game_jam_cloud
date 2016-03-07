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
};
