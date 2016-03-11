//
// Result.h
//

#pragma once

// リザルトシーンクラス
class Result : public Scene
{
private:
    // フォント
    Font f_text;
    Font f_sub_text;

public:
    Result();
    ~Result();

    // 更新
    void update(eScene* _next_scene) override;
    // 描画
    void draw() override;
};
