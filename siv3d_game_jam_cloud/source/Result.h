//
// Result.h
//

#pragma once

// ���U���g�V�[���N���X
class Result : public Scene
{
private:

public:
    Result();
    ~Result();

    // �X�V
    void update(eScene* _next_scene) override;
    // �`��
    void draw() override;
};
