//
// Soldier.h
//

#pragma once

// ���m�N���X
class Soldier : public Player
{
public:
    // ���b�V��
    Box mesh;

private:
    Soldier(Vec3 _location);
    ~Soldier();

    // �X�V
    void update() override;
    // �`��
    void draw() override;
};
