// 20230405_31.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include<cstdlib> //rand(), srand()
#include<ctime> //time()


int main()
{
	srand((unsigned int)time(NULL));
	int number = 0;
	int random = 0;
	bool rock = true;
	int player = 0;
	bool player_in_game = false;
	bool computer_in_game = false;
	while (rock) {
		std::cout << "가위바위보로 선공을 정해주세요 ( 1:가위 2:바위 3:보 ) " << std::endl;
		std::cin >> player;
		random = rand() % 3 + 1;

		if (player == random) {
			std::cout << "무승부입니다 !" << std::endl;
		}
		else if (random == 1) {
			if (player == 2) {
				std::cout << "컴퓨터 가위, 플레이어 바위, 플레이어 승! 플레이어 선공입니다." << std::endl;
				player_in_game = true;
				break;
			}
			else if (player == 3) {
				std::cout << "컴퓨터 가위, 플레이어 보, 플레이어 패! 플레이어 후공입니다." << std::endl;
				computer_in_game = true;
				break;
			}
		}
		else if (random == 2) {
			if (player == 3) {
				std::cout << "컴퓨터 바위, 플레이어 보, 플레이어 승! 플레이어 선공입니다." << std::endl;
				player_in_game = true;
				break;
			}
			else if (player == 1) {
				std::cout << "컴퓨터 바위, 플레이어 가위, 플레이어 패! 플레이어 후공입니다." << std::endl;
				computer_in_game = true;
				break;
			}
		}
		else if (random == 3) {
			if (player == 1) {
				std::cout << "컴퓨터 보, 플레이어 가위, 플레이어 승! 플레이어 선공입니다." << std::endl;
				player_in_game = true;
				break;
			}
			else if (player == 2) {
				std::cout << "컴퓨터 보, 플레이어 바위, 플레이어 패! 플레이어 후공입니다." << std::endl;
				computer_in_game = true;
				break;
			}
		}
		else {
			std::cout << "1 ~ 3 사이의 정수만 입력해 주세요." << std::endl;
		}
	}



	while (number < 31) {
		if (computer_in_game == true) {
			player_in_game = true;
			random = rand() % 3 + 1;

			for (int i = 0; i < random; i++) {
			
				number += 1;
				std::cout<<"컴퓨터 : " << number << std::endl;
				
				if (number == 31) {
					std::cout << "게임 종료! 플레이어의 승리입니다." << std::endl;
					computer_in_game = false;
					player_in_game = false;
					break;
				}
			}
		}

		if (player_in_game == true) {
			computer_in_game = true;
			std::cout << "부를 숫자 개수를 입력하세요. (1~3)" << std::endl;
			std::cin >> player;
			if (0 < player <= 3) {
				for (int i = 1; i <= player; i++) {
					number += 1;
					std::cout << "플레이어 : " << number << std::endl;
					if (number == 31) {
						std::cout << "게임 종료! 플레이어의 패배입니다." << std::endl;
						computer_in_game = false;
						player_in_game = false;
						break;
					}
				}
			}
			else
			{
				std::cout << "1 ~ 3 사이의 정수만 입력해 주세요." << std::endl;
			}
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
