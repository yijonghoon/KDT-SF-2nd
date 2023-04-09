#pragma once
#ifndef __WEAPON_H__
#define __WEAPON_H__

#include <iostream>
#include <vector>
#include<string>
#include<ctime>



class Weapon {
    int damage, durability;
    std::string name;
public:
    Weapon(int damage, int durability, std::string name) {
        this->damage = damage;
        this->durability = durability;
        this->name = name;
    }

    int get_damage() {};
    int get_durability() {};
    std::string get_name() {};
    void used() {};

    virtual void attack() {}
    virtual ~Weapon() {}


};

#endif