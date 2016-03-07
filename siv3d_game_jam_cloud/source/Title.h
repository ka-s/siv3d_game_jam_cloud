//
// Title.h
//

#pragma once

// タイトルシーンクラス
class Title : public Scene
{
private:
    // タイトルテキスト
    Font f_title;
    // サブテキスト
    Font f_sub_text;

public:
    Title();
    ~Title();

    // 更新
    void update(eScene* _next_scene) override;
    // 描画
    void draw() override;
};
