//
// Play.cpp
//

#include "stdafx.h"

Play::Play()
{
    // �n��
    ground = Plane(Vec3(0, 0, 0), 32);
    // ���_
    s_home = 8.0;
    home = Box(Vec3(0, 0, 0), s_home);
    // �G
    v_enemy = Vec3(32.0, 0.0, 0.0);
    s_enemy = 1.0;
    enemy = Box(v_enemy, s_enemy);
    hp_enemy = 60;
    attack_enemy = 1;
    speed_enemy = 0.1;
    cost_enemy = 2;
    // ���m
    v_soldier = Vec3(8.0, -12.0, 0.0);
    soldier = Box(v_soldier, 1);
    hp_soldier = 180;
    attack_soldier = 1;

    // �R�X�g
    cost = 4;
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

    // ��������
    if (Input::Key1.clicked && cost >= 1)
    {
        // ���m���ʒu�Ɉړ�
        v_soldier.y = 0.0;
        // �R�X�g������
        cost -= 1;
    }

    // �G�ړ�
    v_enemy.x -= speed_enemy;
    if (v_enemy.x < 8)
    {
        v_enemy.x = 8;
    }

    // �U������
    if (v_soldier.y == 0.0 && v_enemy.y == 0.0)
    {
        hp_enemy -= attack_soldier;
    }
    // �h�䔻��
    if (v_soldier.y == 0.0 && v_enemy.y == 0.0 && v_enemy.x == 8)
    {
        hp_soldier -= attack_enemy;
    }

    // ���S����
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

// �`��
void Play::draw()
{
    // �n��
    ground.draw();
    // ���_
    home.asMesh().translated(Vec3(0, s_home / 2.0, 0)).scaled(Vec3(1, 2, 1)).draw();
    // �G
    enemy.setPos(v_enemy + Vec3(0.0, s_enemy / 2.0, 0.0));
    enemy.draw();
    // ���m
    enemy.setPos(v_soldier + Vec3(0.0, 0.5, 0.0));
    soldier.draw(Palette::Aqua);

    // �R�X�g�\��
    f_cost(L"�R�X�g: ", cost).draw(0, 0);
    // �q���g���b�Z�[�W
    f_hint(L"1.���m(1) 2.�d������(2) 3.�^���b�g(4) 4.���(8)").draw(0, MAX_Y - 32);
}
