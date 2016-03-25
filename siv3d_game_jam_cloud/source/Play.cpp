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
    // カメラ
    camera.lookat = Vec3(16.f, 0.f, 0.f);
    camera.pos = Vec3(16.f, 4.f, -32.f);

    // 味方数
    player_number = 0;

    // コスト
    cost = 10.f;
    f_cost = Font(16);

    // 敵スポーンレート
    spawn_late = 180;

    // ヒントメッセージ
    f_hint = Font(16);
}

Play::~Play()
{

}

// 更新
void Play::update(eScene* _next_scene)
{
    // カメラ
    Graphics3D::SetCamera(camera);

    // 兵士召喚
    /// ! プレイヤー召喚クラス
    if (Input::Key1.clicked && cost >= 10)
    {
        character.push_back(make_shared<Soldier>(Vec3(8.f, 0.5f, Random(-16.f, 16.f))));
        // コスト消費
        cost -= character.back()->get_cost();
        player_number++;
    }

    // 敵召喚
    /// ! 敵召喚クラス
    if (Random(1, spawn_late) == 1)
    {
        for (int i = 0; i < Random(1, 3); ++i)
        {
            character.push_back(make_shared<Spider>(Vec3(32.f, 0.5f, Random(-16.f, 16.f))));
        }

        // スポーンレートを上げる
        spawn_late -= Random(0, 10);
        if (spawn_late < 1) spawn_late = 1;
    }

    // キャラクター更新
    for (auto i : character)
    {
        i->update();
    }

    /// ここから当たり判定 ----------------

    // プレイヤー攻撃処理
    if (Input::KeyZ.clicked)
    {
        for (auto i : character)
        {
            // SEを鳴らす
            i->action_se();

            auto attack = i->get_collision();
            for (auto j : character)
            {
                auto defense = j->get_collision();

                if (attack == PLAYER && defense == ENEMY)
                {
                    j->damage(i->get_attack());
                    break;
                }
            }
        }
    }

    // 死亡判定
    for (int i = 0; i < character.size(); ++i)
    {
        if (character.at(i)->is_dead())
        {
            // コスト還元
            if (character.at(i)->get_collision() == ENEMY)
            {
                cost += character.at(i)->get_cost();
            }
            // 削除
            character.erase(character.begin() + i);
        }
    }

    // 防御判定
    for (auto i : character)
    {
        // キャスト
        if (dynamic_pointer_cast<Enemy>(i) == nullptr)
        {
            // 失敗したら戻る
            continue;
        }
        // 拠点を攻撃されたら
        if (dynamic_pointer_cast<Enemy>(i)->is_attack_base())
        {
            // リザルト画面へ
            *_next_scene = RESULT;
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
    f_cost(L"コスト: ", cost).draw(0, 0, Palette::Black);
    // ヒントメッセージ
    f_hint(L"1Keyで兵士召喚(コスト10), Zで攻撃! ---- 現在の兵数: ", player_number, L" ---- Wave: ", ((181.f - (float)spawn_late) / 181.f) * 100.f).draw(0, MAX_Y - 32, Palette::Black);
}
