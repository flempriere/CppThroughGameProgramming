// Exercise 10.1
//
// Improve the Simple Boss 2.0 program by adding a new class `FinalBoss`,
// that is derived from the Boss class. The `FinalBoss` should define a
// new method, `MegaAttack()` that inflicts 10 times the amount of damage
// as the `SpecialAttack()` method does

#include <iostream>
using namespace std;

class Enemy {
    public:
        Enemy();
        void Attack() const;
    protected:
        int m_Damage;
};

Enemy::Enemy(): m_Damage(10) {}

void Enemy::Attack() const {
    cout << "Attack inflicts " << m_Damage << " damage points!\n";
}

class Boss : public Enemy {
    public:
        Boss();
        void SpecialAttack() const;
    protected:
        int m_DamageMultiplier;
};

Boss::Boss(): m_DamageMultiplier(3) {}

void Boss::SpecialAttack() const {
    cout << "Special Attack inflicts " << (m_DamageMultiplier * m_Damage);
    cout << " damage points!\n";
}

class FinalBoss : public Boss {
    public:
        FinalBoss();
        void MegaAttack() const;
    private:
        int m_MegaMultiplier;
};

FinalBoss::FinalBoss(): m_MegaMultiplier(10) {}

void FinalBoss::MegaAttack() const {
    cout << "Mega Attack inflicts " << (m_MegaMultiplier * m_DamageMultiplier * m_Damage);
    cout << " damage points!\n";
}

int main() {
    cout << "Creating an enemy.\n";
    Enemy enemy1;
    enemy1.Attack();

    cout << "\nCreating a boss.\n";
    Boss boss1;
    boss1.Attack();
    boss1.SpecialAttack();

    cout << "\n Creating a final boss.\n";
    FinalBoss final1;
    final1.Attack();
    final1.SpecialAttack();
    final1.MegaAttack();

    return 0;
}