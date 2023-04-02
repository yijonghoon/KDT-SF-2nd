// 20230402_강의.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
// 일반 멤버들은 객체가 생성될 때 메모리가 잡힘. -> 객체 없이는 멤버에 접근할 수 없었음.
// static 멤버는 class가 읽히는 순간 메모리가 잡힌다.
// 일반 메모리에 접근할 수 있다는 보장이 없기 때문에 일반 멤버에 접근할 수 없다. static 멤버에만 접근 가능
// 일반 메소드에서 스태틱 메모리에는 항상 접근 가능, 스태틱메소드는 일반 메모리에 항상 접근할 수는 없다.
class Person {
public:
    static int population;
    Person() {
        plusPopulation();
    }
    // static이라는 말을 붙이지 않으면 int getPopulation() 함수는 객체로만 접근 가능하다 ex) p.getPopulation() o , Person.getPopulation() x 그렇기때문에 잘 신경써야할거같다
    static int getPopulation() {
        return population;
    }

    void plusPopulation() {
        population++;
    }

    static int static_var;
    std::string name;
    void sleep() {
        name = "aaa";
    }
    static void static_method(){
        static_var = 123;

        std::cout << "static_method" << std::endl;
        // name = "Aaaaaaaaaa"; // 일반 필드이기 때문에 접근 x
    }

};

int Person::static_var = 0;
int Person::population = 0;

int main()
{
    Person::static_var = 3;
    std::cout << Person::static_var << std::endl;
    Person::static_method();
    Person p;
    p.name = "이종훈";
    p.static_var = 2;
    

    Person p2;

    
    p2.name = "김재연";
    std::cout << p.static_var << " " << p2.static_var << std::endl;
    p2.static_var = 5;
    std::cout << p.name << " " << p2.name << std::endl;
    std::cout << p.static_var << " " << p2.static_var << std::endl;
    p.static_method();

    std::cout << p.population; 
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
