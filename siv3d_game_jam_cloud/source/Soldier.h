//
// Soldier.h
//

#pragma once

// ���m�N���X
class Soldier : public Player
{
private:
    // ���b�V��
    Box mesh;

public:
    Soldier(Vec3 _location);
    ~Soldier();

    // �X�V
    void update();
    // �`��
    void draw() override;
};
