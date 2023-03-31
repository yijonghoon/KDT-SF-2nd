// 20230331-클래스.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using std::cout;
using std::cin;
using std::string;
using std::endl;
//protected 라는 자료형 : 자기 자신과, 자식 클래스에서 접근 가능
//public 모든 곳에서 접근 가능
//private 자기 자신(해당 클래스 내)에서만 접근 가능
class Person { // Student의 부모 클래스, 슈퍼클래스, 상위 클래스

protected:
     //선언이 안되어있을때는 기본적으로 private
    std::string name;
    int age;
    //필드, 메소드, 생성자
public: // private, protected
    /*std::string name;*/

    Person(){}

    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }
    void sleep() {
        std::cout << name <<"(" << age << "세) " << "드르렁" << endl;
    }
    
};
// Person클래스의 public 뜻 > 부모클래스에서 상속받은 멤버들의 접근제어자의 한계를 지정해준다. 만약 protected Person 이렇게 받았다면 main함수(자식클래스 아님)에서 study는 사용 못함.
class Student : protected Person{ // Person의 자식클래스, 서브클래스, 

    string stud_id;
    // 본인(Student) 생성자에서 부모의 생성자를 호출함.
    // Student 생성자를 작성하지 않았다는 건, Student 기본 생성자를 호출하고 
public:
    //Student 생성자를 작성하지 않은 경우
    //Student(){Person()};

   // Student(string name) {
   //     this->name = name;
   //}
    //부모클래스의 생성자를 선택함
    Student(string name, int age) {
        this->stud_id = "111111111";
        this->name = name;
        this->age = age;
        // this->age = age;
    }

    void study() {
        sleep();
        cout << "공부한다" << endl;
    }
};


int main()
{
    Person p("이종훈", 30);
    Student s("이종훈", 29);
    
    /*s.sleep();*/
    s.study();
    p.sleep();
    return 0;
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
