//
// Title.h
//

#pragma once

// タイトルシーンクラス
class Title : public Scene
{
private:

public:
    Title();
    ~Title();

    // 更新
    void update(eScene* _next_scene) override;
    // 描画
    void draw() override;
};
