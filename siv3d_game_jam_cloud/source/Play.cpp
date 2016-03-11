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
    // �J����
    camera.lookat = Vec3(16.f, 0.f, 0.f);
    camera.pos = Vec3(16.f, 4.f, -32.f);

    // ������
    player_number = 0;

    // �R�X�g
    cost = 10.f;
    f_cost = Font(16);

    // �G�X�|�[�����[�g
    spawn_late = 180;

    // �q���g���b�Z�[�W
    f_hint = Font(16);
}

Play::~Play()
{

}

// �X�V
void Play::update(eScene* _next_scene)
{
    // �J����
    Graphics3D::SetCamera(camera);

    // ���m����
    if (Input::Key1.clicked && cost >= 10)
    {
        character.push_back(make_shared<Soldier>(Vec3(8.f, 0.5f, Random(-16.f, 16.f))));
        // �R�X�g����
        cost -= character.back()->get_cost();
        player_number++;
    }

    // �G����
    if (Random(1, spawn_late) == 1)
    {
        for (int i = 0; i < Random(1, 3); ++i)
        {
            character.push_back(make_shared<Spider>(Vec3(32.f, 0.5f, Random(-16.f, 16.f))));
        }

        // �X�|�[�����[�g���グ��
        spawn_late -= Random(0, 10);
        if (spawn_late < 1) spawn_late = 1;
    }

    // �L�����N�^�[�X�V
    for (auto i : character)
    {
        i->update();
    }

    // �v���C���[�U������
    if (Input::KeyZ.clicked)
    {
        for (auto i : character)
        {
            // SE��炷
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

    // ���S����
    for (int i = 0; i < character.size(); ++i)
    {
        if (character.at(i)->is_dead())
        {
            // �R�X�g�Ҍ�
            if (character.at(i)->get_collision() == ENEMY)
            {
                cost += character.at(i)->get_cost();
            }
            // �폜
            character.erase(character.begin() + i);
        }
    }

    // �h�䔻��
    for (auto i : character)
    {
        // �L���X�g
        if (dynamic_pointer_cast<Enemy>(i) == nullptr)
        {
            // ���s������߂�
            continue;
        }
        // ���_���U�����ꂽ��
        if (dynamic_pointer_cast<Enemy>(i)->is_attack_base())
        {
            // ���U���g��ʂ�
            *_next_scene = RESULT;
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
    f_cost(L"�R�X�g: ", cost).draw(0, 0, Palette::Black);
    // �q���g���b�Z�[�W
    f_hint(L"1Key�ŕ��m����(�R�X�g10), Z�ōU��! ---- ���݂̕���: ", player_number, L" ---- Wave: ", ((181.f - (float)spawn_late) / 181.f) * 100.f).draw(0, MAX_Y - 32, Palette::Black);
}
