#pragma once

#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <iostream>
#include <vector>
#include<string>
#include<ctime>

#include "Weapon.h"
#include "Gun.h"
#include "Sword.h"

class Character {
    int hp, level;
    int sword;
    std::string name;
    Weapon* have_weapon;
    Character* target;
    bool haveTarget;

public:
    Character(std::string name) {
        this->hp = 80;
        this->level = 1;
        this->name = name;
    }




    ~Character() {
        if (have_weapon != nullptr)
            delete have_weapon;
        if (this->target != nullptr)
            this->target = nullptr;

        delete this->target;
    }


    void attack() {}


    void pickWeapon(Weapon* weapon) {
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
    void attacked(Weapon* weapon) {
        if (weapon == nullptr) {
            return;
        }
        if (weapon->get_durability() > 0) {
            this->hp = this->hp - weapon->get_damage();
            std::cout << this->name << "의 hp가 -" << weapon->get_damage() << "만큼 감소합니다." << std::endl;
            weapon->used();

            if (this->hp <= 0) {
                std::cout << this->name << "이 죽었습니다." << std::endl;
            }
            else {
                std::cout << "무기의 내구도가 없습니다." << std::endl;
            }
        }
    }

    int getHp() {
        return this->hp;
    }
    void do_action(bool isComputer = false) {
        std::cout << std::endl << "[" << this->name << " 턴]" << std::endl;

        int action;

        if (isComputer) {
            srand(time(NULL));
            action = rand() % 2 + 1;
        }
        else {
            std::cout << "동작을 선택해주세요 (1. 무기줍기 2. 공격) : ";
            std::cin >> action;
        }

        switch ((action)) {

        case 1:
            if (isComputer) {
                srand(time(NULL));
                action = rand() % 2 + 1;
            }
            else {
                std::cout << "줍고 싶은 무기를 선택하세요 (1. 칼 2. 총) : ";
                std::cin >> action;
            }

            if (action == 1) {
                this->pickWeapon(new Sword());

            }
            else if (action == 2) {
                this->pickWeapon(new Gun());
            }
            else {
                std::cout << "무기를 줍지 못했습니다." << std::endl;
            }

            break;

        case 2:
            this->attack();
            this->target->attacked(this->get_have_weapon());

            break;
        default:
            std::cout << "행동에 실패했습니다." << std::endl;
            break;
        }


    }

    void setTarget(Character* target) {
        this->target = target;
    }

    std::string get_name() {
        return this->name;
    }

    bool isDead() {
        bool isDead = this->hp <= 0 ? true : false;

        if (isDead) {
            std::cout << this->target->get_name() << "의 승리!" << std::endl;
        }

        return isDead;
    }
};




#endif