//
// Title.h
//

#pragma once

// �^�C�g���V�[���N���X
class Title : public Scene
{
private:

public:
    Title();
    ~Title();

    // �X�V
    void update(eScene* _next_scene) override;
    // �`��
    void draw() override;
};
