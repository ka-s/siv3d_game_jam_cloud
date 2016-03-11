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
    // カメラ
    Graphics3D::SetCamera(camera);

    // 兵士召喚
    if (Input::Key1.clicked && cost >= 1)
    {
        character.push_back(make_shared<Soldier>(Vec3(8.f, 0.5f, 0.f)));
        // コスト消費
        cost -= character.back()->get_cost();
    }

    // 敵召喚
    if (System::FrameCount() % (60 * 3) == 0)
    {
        character.push_back(make_shared<Spider>(Vec3(32.f, 0.5f, 0.f)));
    }

    // キャラクター更新
    for (auto i : character)
    {
        i->update();
    }

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
    f_hint(L"1Keyで兵士召喚, Zで攻撃!").draw(0, MAX_Y - 32, Palette::Black);
}
