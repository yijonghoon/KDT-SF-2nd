// 20230331_오버라이딩.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Person {
protected	:
	int age;
	std::string name;
public:
	Person(int age, std::string name) {
		this->age = age;
		this->name = name;
	}
	void sleep() {
		std::cout << "드르렁~" << std::endl;
	}
	int override_test(int num) {
		return num;
	}
	int getAge() {
		return age;
	}
};

class Student : public Person {
	std::string stu_id;
public:
	Student(int age, std::string name, std::string stu_id) : Person(age, name) {
		this->stu_id = stu_id;
	}
	void study() {
		std::cout << "공부하기!" << std::endl;
	}
	// 부모클래스에서 정의한 메소드를 자식클래스에서 다시 정의하는, 메소드 오버라이딩이 일어남
	void sleep() {
		std::cout << "12시에 잠자기" << std::endl;


	}
	int override_test(int num) {
		return num + getAge();
	}
	//함수(메소드)의 원형이 같다. 함수 이름, 매개변수 종류, 개수까지 다 같다.
};
int main()
{
	Student s(29, "이종훈","2015041112");
	std::cout << s.override_test(10);
	
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
