#pragma once
#ifndef __SWORD_H__
#define __SWORD_H__
#include "Weapon.h"




class Sword : public Weapon {
public:
    Sword() :Weapon(5, 3, "°Ë") {

    }
    void attack() {}
};

#endif