// 20230325.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    int num[2][3] = { {2,2,2}, {1,23,3} };

    std::string alphabet[2][4] = { {"a","b","c","d"},{"e","f","g","h"} };

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << num[i][j];
            if (j != 2) {
                std::cout << " ";
            }
        }
        if (i != 1) {
            std::cout << "\n";
        }
    }
    std::cout << "\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << alphabet[i][j];
            if (j != 3) {
                std::cout << " ";
            }
        }
        if (i != 1) {
            std::cout << "\n";
        }
    }

    std::cout << std::endl;
    int num2[3] = { 1, 2, 3 };
    for (int i = 0; i < 3; i++) {
        std::cout << num2[i] << " ";

    }
    std::cout << std::endl;


    //for each 문
    for (int n : num2) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    for (auto n : num2) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    //// &를 붙여서 참조하고있다는걸 나타냄
    //for (auto &n : num2) {
    //    std::cin >> n;
    //}
    //std::cout << std::endl;


    for (auto &arr : alphabet) {
        for (auto a : arr) {
            std::cout << a << " ";

        }

        std::cout << std::endl;
    }

    std::string city[] = { "Korea","Japan","China","France","Swiss" };
    for (auto country : city) {
        std::cout << country << " ";
    }
    std::cout << "\n";
    //std::string city2[5];
    //for (int i = 0; i < sizeof(city2) / sizeof(city2[0]); i++) {
    //    std::cin >> city2[i];
    //}

    //for (auto country : city2) {
    //    std::cout << country << " ";
    //}
    //float score[5];
    //float length = sizeof(score) / sizeof(score[0]);
    //float sum = 0;
    //for (int i = 0; i < length; i++) {

    //    std::cout << i + 1 << "번 학생의 성적을 입력하세요 : ";
    //    std::cin >> score[i];
    //}
    //for (auto grade : score) {
    //    sum = sum + grade;
    //}
    //std::cout << sum / length;



    //float score[3][2];
    //float length = sizeof(score) / sizeof(score[0]);
    //float mathsum = 0;
    //float koreansum = 0;
    //for (int i = 0; i < length; i++) {
    //    for (int j = 0; j < 2; j++) {
    //        if (j == 0) {
    //            std::cout << i + 1 << "번 학생의 국어성적을 입력하세요 : ";
    //            std::cin >> score[i][j];
    //        }
    //        else {
    //            std::cout << i + 1 << "번 학생의 수학성적을 입력하세요 : ";
    //            std::cin >> score[i][j];
    //        }
    //      
    //    }
    //    
    //    
    //}
    //for (auto &student : score) {
    //    int count = 0;
    //    for (auto grade : student) {
    //        if (count == 0) {
    //            koreansum = koreansum + grade;
    //        }
    //        else {
    //            mathsum = mathsum + grade;
    //        }
    //        count++;
    //    }
    //    count = 0;
    //}
    //std::cout << "세 학생의 국어 평균은 : " << koreansum / length << "\n" << "세 학생의 수학 평균은 : " << mathsum / length;
    // 
    

    int correct[3] = { 1, 8, 5 };
    int user[3];
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        std::cout << i+1 << " / 3 " << "중복 없이 1~9 사이의 숫자 3개를 입력하세요 : ";
        std::cin >> user[i];
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (user[i] == correct[j]) {
                sum = sum + 1;
            }
        }
    }
    std::cout << sum << " 개 맞춤!";


    //int num1; //변수의 선언
    //num1 = 0; //변수의 초기화, 할당

    //
    //int num = 0;
    //std::string str = "";
    //// 선언할 때 크기가 정해져야 함.
    //std::string fruit[3] = { "apple", "banana", "grape"};

    //// 선언하면서 초기화도 동시에 하면 자동으로 배열의 크기가 정해짐
    //std::string fruit2[] = { "apple", "banana", "grape" };

    //std::string fruit1[3];
    //fruit1[0] = "aapple";
    //fruit1[1] = "bbanana";
    //fruit1[2] = "ggrape";

    ////sizeof() : 변수의 크기를 byte 단위로 변환
    ////int : 4byte, string : ex. 8byte
    //// int num[3]; > 12byte, sizeof(num) => 12
    //for (int i = 0; i < sizeof(fruit)/sizeof(std::string); i++) {
    //    std::cout << fruit[i] << std::endl;
    //}
    //for (int i = 0; i < sizeof(fruit) / sizeof(fruit[0]); i++) {
    //    std::cout << fruit[i] << std::endl;
    //}
    //std::string fruit3[3];
    //for (int i = 0; i < 3; i++) {
    //    std::cin >> fruit3[i];
    //}
    //for (int i = 0; i < 3; i++) {
    //    std::cout << fruit3[i] << std::endl;
    //}
    ////std::cout << fruit1 << std::endl;
    ////std::cout << fruit1[0] << std::endl;
    ////std::cout << fruit1[1] << std::endl;
    ////std::cout << fruit1[2] << std::endl;



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
