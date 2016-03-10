//
// Character.h
//

#pragma once

// �L�����N�^�[���N���X
class Character
{
protected:
    // ���W
    Vec3 location;
    // �̗�
    float hit_point;
    // �U����
    float attack;
    // �R�X�g
    float cost;
    // �����蔻��^�C�v
    eCollision collision;

public:
    Character();
    ~Character();

    // �X�V
    virtual void update() = 0;
    // �`��
    virtual void draw() = 0;

    // ��_���[�W
    void damage(float _damage);
    // ���S����
    bool is_dead();

    // �R�X�g�擾
    float get_cost();
    // �U���͎擾
    float get_attack();
    // �����蔻��^�C�v�擾
    eCollision get_collision();
};
