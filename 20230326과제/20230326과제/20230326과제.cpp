// 20230326과제.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <string>



int main()
{

    std::vector<char> str_set;

    std::string str;
    std::getline(std::cin, str);

    for (int i = 0; i < str.length(); i++) {
        bool is_in = false;
        if (str[i] != ' '){
            for (int j = 0; j < str_set.size(); j++) {
   
                if (str[i] == str_set.at(j)) {
                    is_in = true;
                }
            
        }
        if (is_in == false) {
            str_set.push_back(str[i]);
        }}
        
    }
    std::cout << "\n" << str_set.size() << " 개 (" ;

    for (int i = 0; i < str_set.size()-1; i++) {
        std::cout << str_set[i] << ", ";
    }
    std::cout << str_set[str_set.size()-1] << " )";



    int x, y;
    while (true) {

        std::cin >> x;
        std::cin >> y;

        if (x <= 0 || y <= 0) {
            std::cout << "x와 y 모두 양수를 입력해 주세요." << std::endl;
        }
        else {
            break;
        }
    }
    std::vector<std::vector<int>> arr = { };
    for (int i = 0; i < x; i++) {
        arr.push_back({});
        for (int j = 0; j < y; j++) {
            arr[i].push_back(j + i * y + 1);
        }
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::vector<int> makesum= {};

    while(true){
        std::cout << std::endl << "숫자를 입력하세요 (0 : exit)  : ";
        int num;
        std::cin >> num;
        makesum.push_back(num);

        if (num == 0) {
            break;
        }
    }
    int sum = 0;
    for (int i = 0; i < makesum.size(); i++) {
        sum = sum + makesum[i];
    }

    std::cout << "사용자가 입력한 수의 합은 " << sum << " 입니다. \n";

    
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
