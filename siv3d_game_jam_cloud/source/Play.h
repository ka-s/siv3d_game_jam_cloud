//
// Play.h
//

#pragma once

// ���C���V�[���N���X
class Play : public Scene
{
private:
    // �n��
    Plane ground;
    // ���_
    Box home;
    double s_home;

    // �L�����N�^�[�R���e�i
    std::vector<std::shared_ptr<Character>> character;

    // �R�X�g
    float cost;
    Font f_cost;

    // �q���g���b�Z�[�W
    Font f_hint;

public:
    Play();
    ~Play();

    // �X�V
    void update(eScene* _next_scene) override;
    // �`��
    void draw() override;
};
