// first_project.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
// iostream : 입출력을 제공하는 라이브러리
using namespace std;
// 가장 먼저 호출되는 함수
int main()
{
    /* std::cout << "hello world!\n";

     bool bool123 = true;
     bool123 = false;



     int a = 1;
     int b = 2;
     std::cout << a + b;
     std::cout << "\n";

     float f = 1.2;
     float g = 3.9;
     std::cout << f + g;

     bool c1 = true;
     std::cout << c1;
     std::cout << "\n";

     char d = 'a';
     std::cout << d;
     std::cout << "\n";

     char e = 'b';
     std::cout << e;
     std::cout << "\n";

     std::string str1 = "안녕?";

     std::cout << str1;
     std::cout << "\n";

     std::string test1 = "1";
     std::string test2 = "2";
     std::cout << test1 + test2 + "\n";

     std::string test3 = "포스코";
     test3 = "코딩온";
     std::cout << test3;
     std::cout << "\n";


     int cina;
     std::cin >> cina;

     std::cout << cina + 10;

     std::cout << "\n";

     int cintesta;
     std::string cintestb;

     std::cin >> cintesta;
     std::cout << cintesta << test3;

     //같은 타입을 +할 수 있지만 다르면 안됨, 타입이 다를 경우 <<로 연결, 타입이 같은 경우 +로 연결
     cout << cintestb;*/

    std::cout << "--------------실습1--------------------";
    std::cout << "\n";

     string str1;
     int int1;
     std::cout << "이름을 입력하세요." ;
     std::cout << "\n";
     std::cout << "이름 : ";
     std::cin >> str1;

     std::cout << "나이를 입력하세요";
     std::cout << "\n";
     std::cout << "나이 : ";
     std::cin >> int1;

     std::cout << "안녕하세요! " << str1 << "님(" << int1 << "세)";

    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";


    //if (3 > 5) {
    //    std::cout << "3이 5보다 크다.";
    //}
    //else if (5 > 1) {
    //    std::cout << "5가 1보다 크다.";
    //}
    //else if (3 > 1) {
    //    std::cout << "3이 1보다 크다.";
    //}
    //else {
    //    std::cout << "4";
    //}

    //std::cout << "\n";
    //std::cout << "\n";
    //std::cout << "\n";

    //if (3 > 5 || 1 > 0) {
    //    std::cout << "||를 써서 or 연산 할 수 있다";
    //}
    //std::cout << "\n";
    //std::cout << "\n";
    //std::cout << "\n";

    //int a = 5;
    //if (a > 10) {
    //    std::cout << "a가 10보다 큽니다.";
    //}
    //else if (a == 5) {
    //    std::cout << "a는 5입니다.";

    //}
    //else {
    //    std::cout << "a는 10보다 크지 않고 5가 아닙니다.";
    //}
    //std::cout << "\n";
    //std::cout << "\n";
    //std::cout << "\n";

    //char abc = 'a';

    //// switch 조건문은 기본 타입만 비교가 가능하다
    //switch (abc) {
    //case 'a':
    //    std::cout << "a";
    //    break;
    //case 'b':
    //    std::cout << "b";
    //    break;
    //default:
    //    std::cout << ""; //기본실행코드
    //    break;

    //}
    //a > 5 ? std::cout << "5보다 크다" : std::cout << "5보다 크지 않다";

std::cout << "--------------실습2--------------------";
std::cout << "\n";

std::cout << "나이를 입력하세요. ";
int age;
std::cin >> age;
if (age < 8) {
    std::cout << "유아";

}
else if (age < 14) {
    std::cout << "초등학생";

}
else if (age < 17) {
    std::cout << "중학생";

}
else if (age < 20) {
    std::cout << "고등학생";

}
else if (age < 200) {
    std::cout << "성인";

}
else {
    std::cout << "나이가 너무 많습니다..!";
}
std::cout << "\n";
std::cout << "\n";

std::cout << "--------------실습3--------------------";
std::cout << "\n";
string name;
std::cout << "이름을 입력하세요. ";

std::cin >> name;
if (name == "홍길동") {
    std::cout << "남자";

}
else if (name == "성춘향") {
    std::cout << "여자";
}
else {
    std::cout << "모르겠어요";
}

std::cout << "\n";
std::cout << "\n";

std::cout << "--------------실습4--------------------";
std::cout << "\n";
std::cout << "숫자를 입력해주세요. ";
int b;
std::cin >> b;

std::cout << "\n";
b % 5 ? std::cout <<b << "는 5의 배수가 아니네요 ㅜㅜ" : std::cout << b << "는 5의 배수입니다.";



std::cout << "\n";
std::cout << "\n";

std::cout << "--------------실습5--------------------";
std::cout << "\n";
std::cout << "숫자를 입력해주세요. ";
std::cout << "\n";
int c;

std::cin >> c;

std::cout << "숫자를 입력해주세요. ";
std::cout << "\n";
int d;
std::cin >> d;
std::cout << "\n";

std::cout << "어떤 연산을 하고 싶으신가요?";
string e;
std::cin >> e;
if (e == "나눗셈") {
    if (d != 0) {
        std::cout <<"몫은" << c / d << "나머지는" << c % d;
    }
    else {
        std::cout << "0으로 나누지 마시길 바랍니다.";

    }
}
else if (e == "덧셈") {
    std::cout << c + d;

}
else if (e == "뺄셈") {
    std::cout << c - d;

}
else if (e == "곱셈") {
    std::cout << c * d;

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
