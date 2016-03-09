//
// Player.h
//

#pragma once

// プレイヤーサイドのキャラクタークラス
class Player : public Character
{
private:

public:
    Player();
    ~Player();

    // 更新
    void update() override;
    // 描画
    void draw() override;

};
