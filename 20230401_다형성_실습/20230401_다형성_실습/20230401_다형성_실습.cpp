﻿// 20230401_다형성_실습.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <typeinfo>
class Snack {
    std::string name, company;
    int price;
public:
    Snack(std::string name){
        this->name = name;
        this->company = "aaa";
    }
    std::string getSnackname(){
        return name;
    }
};


class Candy : public Snack {
protected:
    std::string flavor;
public:
    Candy(std::string name) : Snack(name) {
        this->flavor = "yogurt strawberry";
    }
    std::string getCandyflavor() {
        return flavor;
    }
};


class Chocolate : public Snack {
    std::string shape;
public:
    Chocolate(std::string name) : Snack(name) {
        this->shape = "square";
    }
    std::string getChocolateshape() {
        return shape;
    }
};

int main()
{
    Snack* snackBasket[4] = { new Candy("anytime"),new Candy("Tong_almond"),new Chocolate("abc_chocolate"),new Chocolate("hershey") };
    //Snack snackBasket[4] = { Candy("anytime"), Candy("Tong almond"), Chocolate("abc_chocolate"), Chocolate("hershey") };
    Chocolate* chocoBasket[2] = { };
    Candy* candyBasket[2] = { };

    for (int i = 0; i < 4; i++) {
        std::cout << snackBasket[i]->getSnackname()<< /*typeid(snackBasket[i]).name() <<*/ std::endl;

        if (i < 2) {
            candyBasket[i] = (Candy*)snackBasket[i];
            std::cout << candyBasket[i]->getCandyflavor() << std::endl;
        }
        else {
            chocoBasket[i-2] = (Chocolate*)snackBasket[i];
            std::cout << chocoBasket[i - 2]->getChocolateshape() << std::endl;
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
