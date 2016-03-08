//
// Play.cpp
//

#include "stdafx.h"

using namespace std;

Play::Play()
{
    ///// プロトタイプコード
    // 地面
    ground = Plane(Vec3(0, 0, 0), 128);
    // 拠点
    s_home = 8.0;
    home = Box(Vec3(0, 0, 0), s_home);
    //// 敵
    //v_enemy = Vec3(32.0, 0.0, 0.0);
    //s_enemy = 1.0;
    //enemy = Box(v_enemy, s_enemy);
    //hp_enemy = 60;
    //attack_enemy = 1;
    //speed_enemy = 0.1;
    //cost_enemy = 2;
    //// 兵士
    //v_soldier = Vec3(8.0, -12.0, 0.0);
    //soldier = Box(v_soldier, 1);
    //hp_soldier = 180;
    //attack_soldier = 1;

    // コスト
    cost = 4.f;
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

    // 兵士召喚
    if (Input::Key1.clicked && cost >= 1)
    {
        player.push_back(make_shared<Soldier>(Vec3(8.f, 0.5f, 0.f)));
        // コスト消費
        cost -= player.back()->get_cost();
    }

    // 敵移動
    for (auto i : enemy)
    {
        i->move();
    }

    // プレイヤー攻撃処理
    for (auto i : player)
    {
        for (auto j : enemy)
        {
            j->damage(i->get_attack());
        }
    }

    // 防御判定
    //if (v_soldier.y == 0.0 && v_enemy.y == 0.0 && v_enemy.x == 8)
    //{
    //    hp_soldier -= attack_enemy;
    //}

    //// 死亡判定
    //if (hp_soldier <= 0)
    //{
    //    v_soldier.y = -128.0;
    //}
    //if (hp_enemy <= 0)
    //{
    //    v_enemy.y = -128.0;
    //    cost += cost_enemy;
    //}

}

// 描画
void Play::draw()
{
    // 地面
    ground.draw();
    // 拠点
    home.asMesh().translated(Vec3(0, s_home / 2.0, 0)).scaled(Vec3(1, 2, 1)).draw();
    // 敵
    //enemy.setPos(v_enemy + Vec3(0.0, s_enemy / 2.0, 0.0));
    //enemy.draw();
    // 兵士
    //enemy.setPos(v_soldier + Vec3(0.0, 0.5, 0.0));
    //soldier.draw(Palette::Aqua);

    // 全味方描画
    for (auto i : player)
    {
        i->draw();
    }
    // 全敵描画
    for (auto i : enemy)
    {
        i->draw();
    }

    // コスト表示
    f_cost(L"コスト: ", cost).draw(0, 0);
    // ヒントメッセージ
    f_hint(L"1.兵士(1) 2.重装備兵(2) 3.タレット(4) 4.戦車(8)").draw(0, MAX_Y - 32);
}
