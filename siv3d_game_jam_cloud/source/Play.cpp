//
// Play.cpp
//

#include "stdafx.h"

using namespace std;

Play::Play()
{
    // �n��
    ground = Plane(Vec3(0, 0, 0), 128);
    // ���_
    s_home = 8.0;
    home = Box(Vec3(0, 0, 0), s_home);

    // �R�X�g
    cost = 4.f;
    f_cost = Font(16);

    // �q���g���b�Z�[�W
    f_hint = Font(16);
}

Play::~Play()
{

}

// �X�V
void Play::update(eScene* _next_scene)
{
    // �t���[�J����
    Graphics3D::FreeCamera();

    // ���m����
    if (Input::Key1.clicked && cost >= 1)
    {
        character.push_back(make_shared<Soldier>(Vec3(8.f, 0.5f, 0.f)));
        // �R�X�g����
        cost -= character.back()->get_cost();
    }

    // �G����
    if (Input::KeyQ.clicked)
    {
        character.push_back(make_shared<Spider>(Vec3(32.f, 0.5f, 0.f)));
    }

    // �L�����N�^�[�X�V
    for (auto i : character)
    {
        i->update();
    }

    // �v���C���[�U������
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

    // �h�䔻��
    //if (v_soldier.y == 0.0 && v_enemy.y == 0.0 && v_enemy.x == 8)
    //{
    //    hp_soldier -= attack_enemy;
    //}

    // ���S����
    for (int i = 0; i < character.size(); ++i)
    {
        if (character.at(i)->is_dead())
        {
            character.erase(character.begin() + i);
        }
    }

}

// �`��
void Play::draw()
{
    // �n��
    ground.draw();
    // ���_
    home.asMesh().translated(Vec3(0, s_home / 2.0, 0)).scaled(Vec3(1, 2, 1)).draw();

    // �L�����N�^�[�`��
    for (auto i : character)
    {
        i->draw();
    }

    // �R�X�g�\��
    f_cost(L"�R�X�g: ", cost).draw(0, 0);
    // �q���g���b�Z�[�W
    f_hint(L"1.���m(1) 2.�d������(2) 3.�^���b�g(4) 4.���(8)").draw(0, MAX_Y - 32);
}
