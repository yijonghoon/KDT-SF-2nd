// 20230408_계산기by종훈.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
double user_input_number = 0;

double userInputNumber() {
    double number;
    std::cout << "숫자를 입력해주세요 : ";
    std::cin >> number;
    user_input_number = number;
    return number;
}

class calculator {
    static double result;
public:

    virtual void calculate() {
        std::cout << getResult();
    }

    static double getResult() {
        return result;
    }
    static void setResult(double new_result) {
        result = new_result;
    }
    static void resetResult() {
        setResult(0);
        result = userInputNumber();
    }
    virtual ~calculator() {
    }
};

double calculator::result = 0;

std::string userInputMethod() {
    std::string method;
    std::cout << "연산자를 입력해주세요 : ";
    std::cin >> method;
    return method;
}

class calculatePlus : public calculator {
public:
    void calculate() {
        setResult(getResult() + userInputNumber());
    }
};
class calculateMinus : public calculator {
    void calculate() {
        setResult(getResult() - userInputNumber());
    }
};
class calculateMultifly : public calculator {
    void calculate() {
        setResult(getResult() * userInputNumber());
    }
};
class calculateDivide : public calculator {
    void calculate() {
        setResult(getResult() / userInputNumber());
    }
};


void methodIdentifier(std::string method) {
    calculator* calculationMethod;
    if (method == "+") {
        calculationMethod = new calculatePlus();
        calculationMethod->calculate();
    }
    else if (method == "-") {
        calculationMethod = new calculateMinus();
        calculationMethod->calculate();
    }
    else if (method == "*") {
        calculationMethod = new calculateMultifly();
        calculationMethod->calculate();

    }
    else if (method == "/") {
        calculationMethod = new calculateDivide();
        calculationMethod->calculate();
    }
    
    else
    {
        std::cout << "잘못된 연산자를 입력하였습니다." << std::endl;
        methodIdentifier(userInputMethod());

    }
    


}




int main()
{
    calculator::setResult(userInputNumber());
    bool isReset = false;
    std::string command;
    while (command != "EXIT")
    {
        if (isReset) {
            calculator::resetResult();
            isReset = false;
        }
        std::string method;
        
        method = userInputMethod();
        methodIdentifier(method);
        
        std::cout << calculator::getResult() << std::endl;

        std::cout << "연산을 계속 진행하시겠습니까? (Y : 계속, AC : 초기화, EXIT : 종료) : ";
        while (true) {
            std::cin >> command;

            if (command == "AC") {
                isReset = true;
                break;
            }
            else if (command == "Y" || command == "EXIT") {
                break;
            }
            else {
                std::cout << "잘못된 명령어 입니다. 대소문자 확인 후 다시 입력해주세요 : ";
            }
        }
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
