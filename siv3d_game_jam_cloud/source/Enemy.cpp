//
// Enemy.cpp
//

#include "stdafx.h"

Enemy::Enemy()
{
    // �ړ����x
    speed = 1.f;
    // �����蔻��^�C�v
    collision = ENEMY;
    // ���_�P���t���O
    attack_base = false;
}

Enemy::~Enemy()
{

}

// �X�V
void Enemy::update()
{
    // ����
    move();

    // ���_�P���`�F�b�N
    if (location.x < 8.f)
    {
        attack_base = true;
    }
}

// �`��
void Enemy::draw()
{

}

// �ړ�
void Enemy::move()
{
    location.x -= speed;
}

// ���_�P���t���O�擾
bool Enemy::is_attack_base()
{
    return attack_base;
}
