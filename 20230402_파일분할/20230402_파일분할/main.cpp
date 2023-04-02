
#include <iostream>
#include "Person.h"
#include "Student.h"
// # include <> // .h X 내가 만들지 않은 파일
// # include "" // 내가 만든 파일


int main()
{
	Person p("김소연");
	Person p2("채동현");

	std::cout << "인원은 " << Person::getCnt();

	Student p3("채동현");

	std::cout << "인원 : " << Person::getCnt() << std::endl;

}
