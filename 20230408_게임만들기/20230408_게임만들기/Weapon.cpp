#include "Weapon.h"




int Weapon::get_damage() {
    return this->damage;
}

int Weapon::get_durability() {
    return this->durability;
}
std::string Weapon::get_name() {
    return this->name;
}

void Weapon::used() {
    this->durability = this->durability - 1 < 0 ? 0 : this->durability - 1;
}
