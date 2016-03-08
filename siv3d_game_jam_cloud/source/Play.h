//
// Play.h
//

#pragma once

// メインシーンクラス
class Play : public Scene
{
private:
    ///// プロトタイプコード
    // 地面
    Plane ground;
    // 拠点
    Box home;
    double s_home;
    //// 敵
    //Box enemy;
    //Vec3 v_enemy;
    //double s_enemy;
    //int hp_enemy;
    //int attack_enemy;
    //double speed_enemy;
    //int cost_enemy;
    //// 兵士
    //Box soldier;
    //Vec3 v_soldier;
    //int hp_soldier;
    //int attack_soldier;

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
