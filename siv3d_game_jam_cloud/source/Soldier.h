//
// Soldier.h
//

#pragma once

// 兵士クラス
class Soldier : public Player
{
public:
    // メッシュ
    Box mesh;

private:
    Soldier(Vec3 _location);
    ~Soldier();

    // 更新
    void update() override;
    // 描画
    void draw() override;
};
