//
// Character.cpp
//

#include "stdafx.h"

Character::Character()
{
    // ���W
    location = Vec3(0.f, 0.f, 0.f);
    // �̗�
    hit_point = 1.f;
    // �U����
    attack = 1.f;
    // �R�X�g
    cost = 1.f;
}

Character::~Character()
{

}
