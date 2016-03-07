//
// Spider.h
//

#pragma once

// 蜘蛛クラス
class Spider : public Enemy
{
private:
    // メッシュ
    Box mesh;

public:
    Spider(Vec3 _location);
    ~Spider();

    // 更新
    void update();
    // 描画
    void draw();
};
