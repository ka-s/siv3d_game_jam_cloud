//
// Play.h
//

#pragma once

// ���C���V�[���N���X
class Play : public Scene
{
private:

public:
    Play();
    ~Play();

    // �X�V
    void update(eScene* _next_scene) override;
    // �`��
    void draw() override;
};
