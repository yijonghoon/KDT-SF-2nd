// 20230405_타임어택끝말잇기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <ctime>

int main()
{
	std::vector<std::string> words;
	std::string answer = "";
	char last_word = 'e';
	words.push_back("airplane");
	int count = 0;
	bool repeat = false;

	clock_t start, finish;
	int time_limit = 15;
	double duration;


	start = clock();
	while (true) {
		repeat = false;
		for (int i = 0; i < count+1; i++) {
			std::cout << words[i] << " -> ";
		}
		std::cout << "다음 단어를 입력하세요 : ";
		std::cin >> answer;
		for (int i = 0; i < count + 1; i++) {
			if (answer == words[i]) {
				std::cout << "중복입니다." << std::endl;
				repeat = true;
			}
		}
		if (repeat == false) {
			if (answer[0] == last_word) {
				words.push_back(answer);
				finish = clock();
				duration = (double)(finish - start) / CLOCKS_PER_SEC;
				if (duration < time_limit) {
					count++;
				}
				else {
					break;
				}
				last_word = answer.back();
			}
			else {
				std::cout << "잘못된 입력값입니다." << std::endl;
			}
		}
		finish = clock();

		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		if (duration > time_limit) {
			break;
		}
	}
	std::cout <<"끝 ! " << count << "개 성공하셨습니다." << std::endl;


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
