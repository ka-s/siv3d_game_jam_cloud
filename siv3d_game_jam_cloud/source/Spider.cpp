//
// Spider.cpp
//

#include "stdafx.h"

Spider::Spider(Vec3 _location)
{
    // ���W
    location = _location;
    // �̗�
    hit_point = 60.f;
    // �U����
    attack = 1.f;
    // �R�X�g
    cost = 2.f;
    // �ړ����x
    speed = 0.01f;

    // ���b�V��
    mesh = Box(location, 1);
}

Spider::~Spider()
{

}

// �X�V
void Spider::update()
{

}

// �`��
void Spider::draw()
{
    // ���b�V��
    mesh.setPos(location);
    mesh.draw();
}
