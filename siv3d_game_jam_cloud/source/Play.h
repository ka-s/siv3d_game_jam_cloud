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
    // �G
    Box enemy;
    Vec3 v_enemy;
    double s_enemy;
    int hp_enemy;
    int attack_enemy;
    double speed_enemy;
    int cost_enemy;
    // ���m
    Box soldier;
    Vec3 v_soldier;
    int hp_soldier;
    int attack_soldier;

    // �R�X�g
    int cost;
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
