// 20230402_실습2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

class stack {
    static int count;
public:
    static std::string name;
    stack(std::string name) {
        this->name += name ;
        count++;
    }
    static int get_number() {
        return count;
    }
};
std::string stack::name = "";
int stack::count = 0;
int main()
{
    while (1) {
        std::cout << "이름쌓기~ 이름쌓기~ :" << stack::name <<std::endl;
        std::string name;
        std::getline(std::cin, name);
        if (stack::get_number() != 0) {
            if(name.substr(0, stack::name.length()) != stack::name) {
                break;
        }
            else {
                //std::cout << name.substr(stack::name.length(), name.length()) << std::endl;
                stack s(name.substr(stack::name.length(), name.length()));
            }
        }
        else {
            //std::cout << name.substr(stack::name.length(), name.length()) << std::endl;
            //std::cout << stack::name.length()  << " " << name.length() ;
            stack s(name.substr(stack::name.length(),name.length()));
            
            //std::cout << name.substr(stack::name.length(), name.length()) << std::endl;
        }
       
      
    }
    
    std::cout << "게임 종료! " << stack::get_number() << "명까지 성공했습니다!";
    
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
