// 20230325afternoon.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    int x, y;
    while (true) {
        
        std::cin >> x;
        std::cin >> y;

        if (x <= 0 || y <= 0) {
            std::cout << "x와 y 모두 양수를 입력해 주세요." << std::endl;
        }
        else {
            break;
        }
    }

    int** arr2 = new int* [x];
    for (int i = 0; i < x; i++) {
        arr2[i] = new int[y];

    }
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            arr2[i][j] = j + i*y +1;
        }
    }
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            std::cout << arr2[i][j] << " ";
        }
        std::cout << "\n";
    }

    int z;
    std::cin >> z;

    int* arr3 = new int[z];

        for (int i = 0; i < z; i++) {
            int score;
            std::cin >> score;
            arr3[i] = score;
    }
        float sum = 0;
        for (int i = 0; i < z; i++) {
            sum = sum + arr3[i];
        }
        std::cout << sum / z;



    //포인터 : 메모리 주소를 저장하는 변수
    //포인터를 이용하면, 동적 메모리를 생성할 수 있다.
    //포인터가 나오기 전에 배운 변수, 배열 -> 정적메모리
    // 힙 영역 : 동적 메모리가 저장됨. 할당과 해제를 직접 관리해줘야 한다. delete p; 이 명령어를 통해 할당을 해제할 수 있다.
    // 스택 영역 : 정적 메모리가 저장됨.
    // 주의. 포인터를 이용하면 동적 메모리를 생성할 수 있다는 거지, 포인터를 이용한 모든 변수가 동적 메모리는 아님!
    //int* p = new int;
    //delete p; //p에 걸린 할당을 해제해줘야 필요없이 메모리를 잡고 있는걸 막아줄 수 있다.

    //int num;
    //std::cin >> num;
    ////int* arr = new int[num];

    ////for (int i = 0; i < num; i++) {
    ////    arr[i] = i + 1;
    ////}
    ////for (int i = 0; i < num; i++) {
    ////    std::cout << arr[i] << " ";
    ////}

    ////delete[] arr; 
    //int **arr2 = new int* [num];

    //for (int i = 0; i < num; i++) {
    //    arr2[i] = new int[num];
    //}

    //for (int i = 0; i < num; i++) {
    //    for (int j = 0; j < num; j++) {
    //        std::cout << arr2[i][j] << " ";
    //    }
    //    std::cout << std::endl;

    //}
    //for (int i = 0; i < num; i++) {
    //    delete[] arr2[i];
    //}
    //delete[] arr2;
    

    // num * num 행렬
    // int* arr1 = new int[num]; //일차원 동적 배열


   // int n = 3;
   // int* p = &n;

   // std::cout << p << "\n"; //그냥 변수이름으로 접근하면, 주소값이 담긴다
   // std::cout << *p <<"\n"; // p에 담긴 주소가 가리키고 있는 값
   // std::cout << "\n";
   // std::cout << "\n";

   // n = 10;
   // std::cout << p << std::endl; //그냥 변수이름으로 접근하면, 주소값이 담긴다
   // std::cout << *p << std::endl; // p에 담긴 주소가 가리키고 있는 값
   // std::cout << "\n";
   // std::cout << "\n";
   // int n2 = 30;
   // p = &n2;
   // std::cout << p << std::endl; //그냥 변수이름으로 접근하면, 주소값이 담긴다
   // std::cout << *p << std::endl; // p에 담긴 주소가 가리키고 있는 값
   // std::cout << "\n";
   // std::cout << "\n";
   // std::string str = "aaa";
   // std::string* str_p = &str;

   // std::cout << "str_p는 다음과 같이 나옵니다. \n";
   // std::cout << str_p << std::endl;
   // std::cout << "*str_p는 다음과 같이 나옵니다. \n";
   // std::cout << *str_p << std::endl;

   // std::string& str_pp = *str_p;
   // std::cout << "str_pp는 다음과 같이 나옵니다. \n";
   // std::cout << str_pp << std::endl;
   // std::cout << "&str_pp는 다음과 같이 나옵니다. \n";
   // std::cout << &str_pp << std::endl;

   // int& num = n;
   // std::cout << n << std::endl;
   // std::cout << &n << std::endl;
   // std::cout << num << std::endl;
   ///* std::cout << *num << std::endl;*/
   // std::cout << &num << std::endl;



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
