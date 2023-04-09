// 20230408_게임만들기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include<string>
#include<ctime>

#include "Character.h"
#include "Weapon.h"
#include "Gun.h"
#include "Sword.h"


class Sword : public Weapon {
public:
    Sword() :Weapon(5, 3, "검") {

    }
    void attack() {
        std::cout << "찌르기!" << std::endl;

    }
};
class Gun : public Weapon {
public:
    Gun() : Weapon(10, 1, "총") {

    }
    void attack() {
        std::cout << "총쏘기!" << std::endl;
    }
};
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


    void attack() {
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


int main()
{
    std::string name;
    std::cout << "캐릭터 이름 입력 : ";
    std::cin >> name;

    Character player = Character(name);
    Character com = Character("computer");

    player.setTarget(&com);
    com.setTarget(&player);

    int action = 0;

    while (player.getHp() > 0 && com.getHp() > 0) {

        player.do_action();

        if (com.isDead()) {
            break;
        }
        com.do_action(true);

        if (player.isDead()) {
            break;
        }
    }
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
