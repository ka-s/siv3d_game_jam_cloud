//
// Spider.h
//

#pragma once

// �w偃N���X
class Spider : public Enemy
{
private:
    // ���b�V��
    Box mesh;

public:
    Spider(Vec3 _location);
    ~Spider();

    // �X�V
    void update();
    // �`��
    void draw();
};
