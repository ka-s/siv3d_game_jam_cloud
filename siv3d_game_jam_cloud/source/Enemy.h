//
// Enemy.h
//

#pragma once

// �G�T�C�h�̃L�����N�^�[�N���X
class Enemy : public Character
{
protected:
    // �ړ����x
    float speed;

public:
    Enemy();
    ~Enemy();

    // �X�V
    void update() override;
    // �`��
    void draw() override;

    // �ړ�
    void move();
};
