﻿// 20230401.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int test() {

    return 0;
}
//추상화를 쓰는 이유 : 이 클래스를 상속받았을때 의무적으로 넣어야 하는 속성을 지정해준다
class Person {
public:
    virtual void test() = 0;
    virtual void sleep() = 0;
    virtual void eat() = 0;
};
//추상클래스를 상속받는 자식 클래스는 추상 메소드를 "구현" 해야함. 만약 구현하지 않는다면 자식클래스도 추상클래스가 된다.
class Student : public Person {
public:
    void test() {
        std::cout << "test 함수 입니다" << std::endl;
    }
    void sleep() {
        std::cout << "너무너무 졸려요" << std::endl;

    }
    void eat() {
        std::cout << "너무너무 배고파요" << std::endl;
    }
};

int main()
{
    //Person p = Person(); //Person이 추상클래스이기 때문에 인스턴스를 만들 수 없다

    Student s = Student();
    s.test();
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