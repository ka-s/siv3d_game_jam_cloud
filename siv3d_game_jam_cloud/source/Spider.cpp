//
// Spider.cpp
//

#include "stdafx.h"

Spider::Spider(Vec3 _location)
{
    // ���W
    location = _location;
    // �̗�
    hit_point = 5.f;
    // �U����
    attack = 1.f;
    // �R�X�g
    cost = 2.f;
    // �ړ����x
    speed = (32.f - 8.f) / (60.f * 8.f);

    // ���b�V��
    mesh = Model(L"Assets/spider/spider01.obj");
    // �e�N�X�`��
    t_base = Texture(L"Assets/spider/spider_desert.tex.tga");
}

Spider::~Spider()
{

}

// �X�V
void Spider::update()
{
    // �e�֐��Ăяo��
    Enemy::update();
}

// �`��
void Spider::draw()
{
    // ���_�␳
    Vec3 _location = location - Vec3(0.f, 0.5f, 0.f);
    // ���b�V��
    mesh.nodes().at(0).mesh
        .scaled(Vec3(0.1f, 0.1f, 0.1f))
        .rotated(Vec3(0.f, Radians(90.f), 0.f))
        .translated(_location)
        .draw(t_base);
}
