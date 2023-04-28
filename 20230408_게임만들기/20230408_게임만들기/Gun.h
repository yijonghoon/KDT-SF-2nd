#pragma once
#ifndef __GUN_H__
#define __GUN_H__
#include "Weapon.h"




class Gun : public Weapon {
public:
    Gun() : Weapon(10, 1, "รั") {

    }
    void attack() {}
};



#endif