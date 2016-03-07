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

public:
    Character();
    ~Character();

    // �X�V
    virtual void update() = 0;
    // �`��
    virtual void draw() = 0;
};
