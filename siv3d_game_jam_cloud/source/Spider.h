//
// Spider.h
//

#pragma once

// �w偃N���X
class Spider : public Enemy
{
private:
    // ���b�V��
    Model mesh;
    // �e�N�X�`��
    Texture t_base;

public:
    Spider(Vec3 _location);
    ~Spider();

    // �X�V
    void update();
    // �`��
    void draw();
};
