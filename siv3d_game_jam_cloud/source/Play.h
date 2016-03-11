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
    // カメラ
    Camera camera;

    // キャラクターコンテナ
    std::vector<std::shared_ptr<Character>> character;
    // 味方数
    int player_number;

    // コスト
    float cost;
    Font f_cost;

    // 敵スポーンレート
    int spawn_late;

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
