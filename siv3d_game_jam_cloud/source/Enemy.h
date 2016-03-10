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
    // ���_�P���t���O
    bool attack_base;

public:
    Enemy();
    ~Enemy();

    // �X�V
    void update() override;
    // �`��
    void draw() override;

    // �ړ�
    void move();
    
    // ���_�P���t���O�擾
    bool is_attack_base();
};
