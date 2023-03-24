// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 매개변수는 함수의 외부에서 사용되는 값을 함수의 내부에서 사용하고 싶을때
// return(반환값)은 함수의 내부에서 얻은 값을 함수의 외부에서 사용하고 싶을 때

//1. 매개변수 x return x
void test_1() {

}
//2. 매개변수 o return x
void test_2(int num, std::string str, float num3) {

}
//3. 매개변수 o return o
std::string test_3(int num, std::string str, float num3){


	return "test";
}
//4. 매개변수 x return o
int function() {
	int a = 2;
	std::string b = "b";
	return a;
}
int sum(int num1, int num2) {
	int result = num1 + num2;
	return result;
}
int assignment1(int a, int b) {
	int result = a + b;
	return result;
}
int assignment2(int a, int b) {
	int result = 0;
	if (a > b) {
		result = a - b;
	}
	else if (a <= b) {
		result = b - a;
	}
	return result;
}
int assignment3(int a, int b) {
	int result = a * b;
	return result;


}
float assignment4(int a, int b) {
	float result = (float)a / (float)b;
	return result;
}

std::string no2(int a) {
	if (a % 2 == 0) {
		std::cout << "짝수";
	}
	else {
		std::cout << "홀수";
	}
	return "바보";
}

int no3(int a, int b, int c) {

	if (a >= b) {
		if (a >= c) {
			return a;
		}
		else {
			return c;
		}
	}
	else {
		if (b >= c) {
			return b;
		}
		else {
			return c;
		}
	}
}

int main()
{

	int a,b,c;

std::cin >> a;
std::cin >> b;
std::cin >> c;


std::cout << no3(a,b,c);


	//int c, d;
	//std::cin >> c;
	//std::cin >> d;

	//std::cout << "결과는 : " << assignment1(c, d) << std::endl;

	//int e, f;
	//std::cin >> e;
	//std::cin >> f;

	//std::cout << "결과는 : " << assignment2(e, f) << std::endl;

	//int a, b;

	//std::cin >> a;
	//std::cin >> b;


	//std::cout <<"결과는 : " << assignment3(a, b) << std::endl;

	//int g, h;
	//std::cin >> g;
	//std::cin >> h;
	//std::cout << "결과는 : " << assignment4(g, h) << std::endl;

	//test_1();
	//test_2(12, "21", 12);
	//int num = 5;
	//std::string str = "str";
	//test_3(num, str, 10);
	//function();

	//int result = sum(5, 8);
	//std::cout << sum(5,13);
	//int j = 0;
 //  // (초기값; 조건문; 증감문)
	//for (int i = 0; i <= 5; i++) {
	//	std::cout << "안녕하세요" << i;
	//	std::cout << "\n";
	//	j ++;
	//}
	//std::cout << "for문 끝!" <<"\n"<< j << "번 출력함";
	//std::cout << "\n";
	//int l;
	//std::cout << "\n";
	//// (초기값; 조건문; 증감문)
	//for (int k = 10; k >= 5; k--) {
	//	std::cout << "안녕하세요" << k;
	//	std::cout << "\n";
	//	l = k;
	//}


	//std::cout << "for문 끝!"<<"\n" << l << "번 출력함";
	//std::cout << "\n";
	//std::cout << "\n";
	//int i = 0;
	//while (i < 5) {
	//	i++;
	//	std::cout << "안녕하세요" << i << std::endl;
	//}
	//std::cout << "\n";


	/////*int order;
	////int americano = 0;
	////int latte = 0;
	////while (true) {
	////	std::cout << "아메리카노를 주문하시려면 1번, 라떼 주문은 2번, 주문을 완료하시려면 3번을 눌러주세요" << std::endl;
	////	std::cin >> order;

	////	if (order == 1) {
	////		americano++;
	////		std::cout << "아메리카노를 성공적으로 주문" << std::endl;
	////	}
	////	else if (order == 2) {
	////		latte ++;
	////		std::cout << "라떼를 성공적으로 주문" << std::endl;
	////	}
	////	else if(order == 3){ 

	////		std::cout<< "아메리카노 " <<americano << "잔," << "라떼 " << latte << "잔 주문 완료했습니다." << std::endl;

	////		break;
	////	}
	////	else {
	////		std::cout << "1~3까지의 숫자만 입력하세요."<<std::endl;
	////	}

	////	std::cout << "감사합니다." << std::endl;
	////}*/
	//int dowhile = 0;
	//do {
	//	std::cout << "두와일문";
	//	dowhile++;
	//} while (dowhile < 3);

	//std::cout << "------------------------ 실습 1 -------------------------" << std::endl;
	//std::cout << "\n" << std::endl;
	//std::cout << "------------------------ (1) -------------------------" << std::endl;
	//for (int i = 1; i <= 9; i++) {
	//	std::cout << "5 * " << i << " = " << i * 5 << std::endl;
	//}

	//std::cout << "------------------------ (2) -------------------------" << std::endl;

	//for (int i = 1; i <= 9; i++) {
	//	std::cout << i << "단"<<std::endl;
	//	for (int j = 1; j <= 9; j++) {
	//		std::cout << i << " * " << j << " = " << i * j << std::endl;
	//	}
	//}
	//std::cout << "------------------------ 실습 2 -------------------------" << std::endl;
	//std::cout << "\n" << std::endl;
	//std::cout << "1부터 n까지의 합 구하기" << std::endl << std::endl;
	//std::cout << "숫자(양의 정수)를 입력하세요 : ";
	//int number;
	//std::cin >> number;
	//std::cout << "\n";
	//std::cout << "1부터 100까지의 합은 : ";
	//int count = 1;
	//int sum = 0;
	//while (count <= number) {
	//	sum = sum + count;
	//	count++;
	//}
	//std::cout << sum;

	//std::cout << "------------------------ 실습 3 -------------------------" << std::endl;

	//int dan = 5, num = 9;

	//while (dan == 5) {
	//	std::cout << dan << "단\n";
	//	num = 1;
	//	while (num <= 9) {
	//		std::cout << dan << " x " << num << " = "
	//			<< dan * num << std::endl;
	//		num++;
	//	}
	//	dan++;
	//	std::cout << std::endl;
	//}


	// dan = 1, num = 1;

	//while (dan <= 9) {
	//	std::cout << dan << "단\n";
	//	num = 1;
	//	while (num <= 9) {
	//		std::cout << dan << " x " << num << " = "
	//			<< dan * num << std::endl;
	//		num++;
	//	}
	//	dan++;
	//	std::cout << std::endl;
	//}


	//std::cout << "\n" << std::endl;
	//std::cout << "1부터 n까지의 합 구하기" << std::endl << std::endl;
	//std::cout << "숫자(양의 정수)를 입력하세요 : ";
	//int number;
	//std::cin >> number;
	//std::cout << "\n";
	//std::cout << "1부터 100까지의 합은 : ";
	//int count = 1;
	//int sum = 0;
	//while (count <= number) {
	//	sum = sum + count;
	//	count++;
	//}
	//std::cout << sum;

	//std::cout << "------------------------ 실습 3 -------------------------" << std::endl;

	//int order;
	//int americano = 0;
	//int latte = 0;
	//while (true) {
	//	std::cout << "숫자를 입력하세요 ( 0 = exit )" << std::endl;
	//	std::cin >> order;

	//	if (order == 0) {
	//		break;
	//	}
	//	else {
	//		americano = americano + order;
	//	}

	//	std::cout << "감사합니다." << std::endl;
	//}

	//std::cout << "input : ";
	//int number;
	//std::cin >> number;
	//std::cout << "\n";
	//std::cout << "output : "<<std::endl;
	//int count = 1;
	//int sum = 0;
	//while (count <= number) {
	//	sum = sum + 1;
	//	for (int star = 1; star <= sum; star++) {
	//		std::cout << "*";
	//	}
	//	count++;
	//	std::cout << "\n";
	//}


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
