#include "Character.h"


void Character::attack() {
    if (have_weapon == nullptr) {
        std::cout << "무기가 없습니다." << std::endl;
        return;
    }

    if (have_weapon->get_durability() == 0) {
        std::cout << "무기 내구도가 없습니다." << std::endl;
    }
    else {
        have_weapon->attack();
        std::cout << this->name << " 플레이어가 " << this->target->get_name() << "을 공격했습니다." << std::endl;
    }
}

void Character::pickWeapon(Weapon* weapon) {
    if (have_weapon != nullptr) {
        delete have_weapon;
        std::cout << "무기를 버립니다." << std::endl;
    }

    std::cout << weapon->get_name() << " 줍기" << std::endl;
    this->have_weapon = weapon;
}
Weapon* get_have_weapon() {
    return this->have_weapon;
}