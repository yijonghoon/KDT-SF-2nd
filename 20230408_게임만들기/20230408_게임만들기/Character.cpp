#include "Character.h"


void Character::attack() {
    if (have_weapon == nullptr) {
        std::cout << "���Ⱑ �����ϴ�." << std::endl;
        return;
    }

    if (have_weapon->get_durability() == 0) {
        std::cout << "���� �������� �����ϴ�." << std::endl;
    }
    else {
        have_weapon->attack();
        std::cout << this->name << " �÷��̾ " << this->target->get_name() << "�� �����߽��ϴ�." << std::endl;
    }
}

void Character::pickWeapon(Weapon* weapon) {
    if (have_weapon != nullptr) {
        delete have_weapon;
        std::cout << "���⸦ �����ϴ�." << std::endl;
    }

    std::cout << weapon->get_name() << " �ݱ�" << std::endl;
    this->have_weapon = weapon;
}
Weapon* get_have_weapon() {
    return this->have_weapon;
}