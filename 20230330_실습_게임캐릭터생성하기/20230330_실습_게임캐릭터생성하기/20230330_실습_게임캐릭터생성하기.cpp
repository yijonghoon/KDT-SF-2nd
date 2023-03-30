// 20230330_실습_게임캐릭터생성하기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include<cstdlib> //rand(), srand()
#include<ctime> //time()



class Character {
	std::string name;
	int level, item_num, hp, max_hp, attack;
public:
	Character(std::string name) {
		setName(name);
		this->item_num = 0;
		this->level = 0;
		int rand_hp = 0;
		for (int i = 0; i < 40; i++) {
			rand_hp += rand() % 5;
		}
		this->hp = rand_hp;

		int rand_attack = 0;

		for (int i = 0; i < 10; i++) {
			rand_attack += rand() % 5;
		}
		this->attack = rand_attack;
	}
	std::string getName() {
		return this->name;
	}
	int getLevel() {
		return this->level;
	}
	int getItem_num() {
		return this->item_num;
	}
	int getHp() {
		return this->hp;
	}
	int getMax_hp() {
		return this->max_hp;
	}
	int getAttack() {
		return this->attack;
	}
	void setName(std::string name) {
		this->name = name;
	}
	void changeItem_num(int item_num) {
		this->item_num += item_num;
	}
	void changeLevel(int level) {
		this->level += level;
		int rand_hp = 0; // hp 증감
		for (int i = 0; i < 4; i++) {
			rand_hp += rand() % 5;
		}
		this->hp += level * rand_hp;
		
		int rand_attack = 0; // attack 증감
		for (int i = 0; i < 1; i++) {
			rand_attack += rand() % 5;
		}
		this->attack += level*rand_attack;
	}
	void changeHp(int hp) {
		this->hp += hp;
	}
	void changeMax_hp(int hp){
		this->max_hp += hp;
	}
};
int main()
{

	srand((unsigned int)time(NULL));

	std::string name;
	std::cout << "이름을 입력해주세요 : ";
	std::cin >> name;
	Character knight(name);
	std::string knight;
	std::cout << "\n" << knight.getName() << " 캐릭터가 생성 되었습니다." << std::endl;
	bool go = true;
	while (go) {
		int command;
		std::cout << "어떤 동작을 실행하시겠습니까? (0: 종료) ";
		std::cin >> command;
		std::cout << std::endl;

		switch (command) {
		case 0:
			std::cout << "이용해주셔서 감사합니다." << std::endl;
			go = false;
			break;
		case 1:
			std::cout << "새 이름을 입력해 주세요 : ";
			std::cin >> name;
			knight.setName(name);

			std::cout << std::endl << "New name : " << knight.getName() << std::endl;
			break;

		case 2:
			std::cout << "Level up!" << std::endl;
			knight.changeLevel(1);
			std::cout << "현재 레벨 : " << knight.getLevel() << std::endl;
			break;
		case 3:
			std::cout << "아이템을 얻었습니다 !" << std::endl;
			knight.changeItem_num(1);
			std::cout << "현재 아이템 개수 : " << knight.getItem_num() << std::endl;
			break;
		case 4:
			
			if (knight.getItem_num() != 0) {
				knight.changeItem_num(-1);
				std::cout << "아이템을 사용했습니다 !" << std::endl;
				std::cout << "현재 아이템 개수 : " << knight.getItem_num() << std::endl;
			}
			else {
				std::cout << "아이템이 없습니다 !" << std::endl;
			}
			break;
		case 5:
			std::cout << "상 태 창 !" << std::endl;
			std::cout << "이 름 : " << knight.getName() << std::endl;
			std::cout << "level : " << knight.getLevel() << std::endl;
			std::cout << "체 력 : " << knight.getHp() << std::endl;
			std::cout << "공격력 : " << knight.getAttack() << std::endl;
			std::cout << "잔여 아이템 : " << knight.getItem_num() << std::endl;
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
