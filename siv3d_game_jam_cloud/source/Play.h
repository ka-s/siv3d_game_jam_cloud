//
// Play.h
//

#pragma once

// メインシーンクラス
class Play : public Scene
{
private:
    // 地面
    Plane ground;
    // 拠点
    Box home;
    double s_home;

    // 味方コンテナ
    std::vector<std::shared_ptr<Player>> player;
    // 敵コンテナ
    std::vector<std::shared_ptr<Enemy>> enemy;

    // コスト
    float cost;
    Font f_cost;

    // ヒントメッセージ
    Font f_hint;

public:
    Play();
    ~Play();

    // 更新
    void update(eScene* _next_scene) override;
    // 描画
    void draw() override;
};
