// 20230331_실습_오버라이딩.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Student {
    std::string name, school, stu_id;
    int age;

public:
    Student(std::string name, std::string school, int age, std::string stu_id) {
        this->name = name;
        this->age = age;
        this->school = school;
        this->stu_id = stu_id;
    }
    void lunch() {
        std::cout << "점심은 학식" << std::endl;
    }
};

class Kim : Student {

public:
    Kim(std::string name, std::string school, int age, std::string stu_id) : Student(name, school, age, stu_id) {

    }
    void lunch() {
        std::cout << "점심은 김가네 김밥" << std::endl;
    }

};
class Baek : Student {
public:
    Baek(std::string name, std::string school, int age, std::string stu_id) : Student(name, school, age, stu_id) {

    }
    void lunch() {
        std::cout << "점심은 백종원 피자 " << std::endl;
    }
};

int main()
{
    Kim kim("이종훈", "중탑초등학교", 29, "2015041112");
    Baek baek("이종훈", "중탑초등학교", 29, "2015041112");

    kim.lunch();
    baek.lunch();
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
