// 20230401_가상함수.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <typeinfo>
class Person {
public:
    Person() {
        std::cout << "Person 생성자 입니다." << std::endl;
    }

    //가상함수 : 부모클래스에서 정의될 예정.
    //자식클래스가 재정의(오버라이딩) 할 것이라고 기대하는 함수
    //순수 가상함수 : 구현이 안 되어 있는 함수 ( = 0)
    //virtual void sleep() = 0; // 순수 가상함수
    virtual void sleep() { //가상함수 : 동적 바인딩을 하기 위해 미리 만드는 함수
        std::cout << "잠자기" << std::endl;
    }
    // 업캐스팅이 일어날 때 부모클래스의 소멸자를 가상함수로 만들어 주어야 자식클래스도 제대로 소멸이 된다.
    virtual ~Person() {
        std::cout << "Person의 소멸자 입니다" << std::endl;
    }
};
class Student : public Person {
public:
    Student() : Person() {
        std::cout << "Student 생성자 입니다." << std::endl;
    }
    void sleep() {
      std::cout <<  "10시에 학생 잠자기" << std::endl;
    }
    ~Student() {
        std::cout << "Student 소멸자 입니다." << std::endl;
    }
};
int main()
{
    Student s = Student();
    s.sleep(); // 정적바인딩
    
    Person* s2 = new Student();// 업캐스팅
    std::cout << typeid(s2).name() << std::endl;
    s2->sleep(); // 동적 바인딩
    //가상함수를 쓰는 이유는 동적 바인딩을 하기 위해서임. 
    //현재 s2는 Person을 가리키고 있는 업캐스팅이 일어나 있는데, 
    //Person임에도 Student의 함수를 실행할 수 있게 되는것
    delete s2;
    //Student 소멸자입니다. -> 이게 안나오네? 부모클래스에서 가상함수를 통해 함수를 정의했다면 소멸자 또한 virtual ~Parent 이런식으로 정의해주어야 함
    //Person 소멸자 입니다.
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
