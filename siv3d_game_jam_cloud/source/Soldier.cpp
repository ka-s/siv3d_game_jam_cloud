//
// Soldier.cpp
//

#include "stdafx.h"

Soldier::Soldier(Vec3 _location)
{
    // ���W
    location = _location;
    // �̗�
    hit_point = 180.f;
    // �U����
    attack = 1.f;
    // �R�X�g
    cost = 1.f;

    // ���b�V��
    mesh = Box(location, 1);
}

Soldier::~Soldier()
{

}

// �X�V
void Soldier::update()
{

}

// �`��
void Soldier::draw()
{
    // ���b�V���`��
    mesh.setPos(location);
    mesh.draw(Palette::Aqua);
}
