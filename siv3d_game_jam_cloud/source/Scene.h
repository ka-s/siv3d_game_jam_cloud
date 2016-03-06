//
// Scene.h
//

#pragma once

// シーンクラス
//   ゲームシーンの親クラス
class Scene
{
private:

public:
    Scene() {};
    ~Scene() {};

    // 更新
    virtual void update(eScene* _next_scene) = 0;
    // 描画
    virtual void draw() = 0;
};
