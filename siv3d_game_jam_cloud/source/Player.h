//
// Player.h
//

#pragma once

// �v���C���[�T�C�h�̃L�����N�^�[�N���X
class Player : public Character
{
private:

public:
    Player();
    ~Player();

    // �X�V
    void update() override;
    // �`��
    void draw() override;

};
