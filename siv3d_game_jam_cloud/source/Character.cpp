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
    // �����蔻��^�C�v
    collision = NONE;
}

Character::~Character()
{

}

// ��_���[�W
void Character::damage(float _damage)
{
    hit_point -= _damage;
}

// ���S����
bool Character::is_dead()
{
    if (hit_point <= 0)
    {
        return true;
    }

    return false;
}

// �R�X�g�擾
float Character::get_cost()
{
    return cost;
}

// �U���͎擾
float Character::get_attack()
{
    return attack;
}

// �����蔻��^�C�v�擾
eCollision Character::get_collision()
{
    return collision;
}
