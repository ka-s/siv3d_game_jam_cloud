//
// Soldier.h
//

#pragma once

// 兵士クラス
class Soldier : public Player
{
private:
    // メッシュ
    Box mesh;

public:
    Soldier(Vec3 _location);
    ~Soldier();

    // 更新
    void update();
    // 描画
    void draw() override;
};
