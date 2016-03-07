//
// Play.h
//

#pragma once

// メインシーンクラス
class Play : public Scene
{
private:

public:
    Play();
    ~Play();

    // 更新
    void update(eScene* _next_scene) override;
    // 描画
    void draw() override;
};
