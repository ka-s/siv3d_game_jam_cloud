//
// Play.cpp
//

#include "stdafx.h"

using namespace std;

Play::Play()
{
    // 地面
    ground = Plane(Vec3(0, 0, 0), 128);
    // 拠点
    s_home = 8.0;
    home = Box(Vec3(0, 0, 0), s_home);

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
        character.push_back(make_shared<Soldier>(Vec3(8.f, 0.5f, 0.f)));
        // コスト消費
        cost -= character.back()->get_cost();
    }

    // 敵召喚
    if (Input::KeyQ.clicked)
    {
        character.push_back(make_shared<Spider>(Vec3(32.f, 0.5f, 0.f)));
    }

    // キャラクター更新
    for (auto i : character)
    {
        i->update();
    }

    // プレイヤー攻撃処理
    for (auto i : character)
    {
        auto attack = i->get_collision();
        for (auto j : character)
        {
            auto defense = j->get_collision();

            if (attack == PLAYER && defense == ENEMY)
            {
                j->damage(i->get_attack());
            }
        }
    }

    // 防御判定
    //if (v_soldier.y == 0.0 && v_enemy.y == 0.0 && v_enemy.x == 8)
    //{
    //    hp_soldier -= attack_enemy;
    //}

    // 死亡判定
    for (int i = 0; i < character.size(); ++i)
    {
        if (character.at(i)->is_dead())
        {
            character.erase(character.begin() + i);
        }
    }

}

// 描画
void Play::draw()
{
    // 地面
    ground.draw();
    // 拠点
    home.asMesh().translated(Vec3(0, s_home / 2.0, 0)).scaled(Vec3(1, 2, 1)).draw();

    // キャラクター描画
    for (auto i : character)
    {
        i->draw();
    }

    // コスト表示
    f_cost(L"コスト: ", cost).draw(0, 0);
    // ヒントメッセージ
    f_hint(L"1.兵士(1) 2.重装備兵(2) 3.タレット(4) 4.戦車(8)").draw(0, MAX_Y - 32);
}
