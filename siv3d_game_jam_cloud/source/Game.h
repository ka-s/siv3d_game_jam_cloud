//
// Game.h
//

#pragma once

// ゲームクラス
//   ゲーム全体,主にゲームシーンを管理するクラス
class Game
{
private:
    // ゲームシーンインスタンス
    std::shared_ptr<Scene> scene;

    // 現在のシーン
    eScene now_scene;
    // 次のシーン
    eScene next_scene;

    // 更新
    void update();
    // 描画
    void draw();

    // シーン切り替え
    void scene_changer();

public:
    Game();
    ~Game();

    // ゲームを走らせる
    void run();
};
