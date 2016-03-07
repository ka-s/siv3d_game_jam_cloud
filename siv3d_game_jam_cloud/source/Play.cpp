//
// Play.cpp
//

#include "stdafx.h"

Play::Play()
{
    // 地面
    ground = Plane(Vec3(0, 0, 0), 32);
    // 拠点
    s_home = 8.0;
    home = Box(Vec3(0, 0, 0), s_home);
    // 敵
    v_enemy = Vec3(32.0, 0.0, 0.0);
    s_enemy = 1.0;
    enemy = Box(v_enemy, s_enemy);
    hp_enemy = 60;
    attack_enemy = 1;
    speed_enemy = 0.1;
    cost_enemy = 2;
    // 兵士
    v_soldier = Vec3(8.0, -12.0, 0.0);
    soldier = Box(v_soldier, 1);
    hp_soldier = 180;
    attack_soldier = 1;

    // コスト
    cost = 4;
    f_cost = Font(16);

    // ヒントメッセージ
    f_hint = Font(16);
}

Play::~Play()
{

}

// 更新
void Play::update(eScene* _next_scene)
{
    // フリーカメラ
    Graphics3D::FreeCamera();

    // 味方召喚
    if (Input::Key1.clicked && cost >= 1)
    {
        // 兵士を定位置に移動
        v_soldier.y = 0.0;
        // コストを消費
        cost -= 1;
    }

    // 敵移動
    v_enemy.x -= speed_enemy;
    if (v_enemy.x < 8)
    {
        v_enemy.x = 8;
    }

    // 攻撃判定
    if (v_soldier.y == 0.0 && v_enemy.y == 0.0)
    {
        hp_enemy -= attack_soldier;
    }
    // 防御判定
    if (v_soldier.y == 0.0 && v_enemy.y == 0.0 && v_enemy.x == 8)
    {
        hp_soldier -= attack_enemy;
    }

    // 死亡判定
    if (hp_soldier <= 0)
    {
        v_soldier.y = -128.0;
    }
    if (hp_enemy <= 0)
    {
        v_enemy.y = -128.0;
        cost += cost_enemy;
    }

}

// 描画
void Play::draw()
{
    // 地面
    ground.draw();
    // 拠点
    home.asMesh().translated(Vec3(0, s_home / 2.0, 0)).scaled(Vec3(1, 2, 1)).draw();
    // 敵
    enemy.setPos(v_enemy + Vec3(0.0, s_enemy / 2.0, 0.0));
    enemy.draw();
    // 兵士
    enemy.setPos(v_soldier + Vec3(0.0, 0.5, 0.0));
    soldier.draw(Palette::Aqua);

    // コスト表示
    f_cost(L"コスト: ", cost).draw(0, 0);
    // ヒントメッセージ
    f_hint(L"1.兵士(1) 2.重装備兵(2) 3.タレット(4) 4.戦車(8)").draw(0, MAX_Y - 32);
}
