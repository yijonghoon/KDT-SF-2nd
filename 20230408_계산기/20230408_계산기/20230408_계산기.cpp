// 20230408_계산기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using std::cout;
using std::cin;
using std::string;
using std::endl;

class calculator {
    static double result;
public:

    virtual void calculate() {
        
        cout << "결과 : " << getResult() << endl;
        
    };
    static double getResult() {
        return result;
    };
    static void setResult(double num) {
        result = num;
    
    }
    ;
    static void resetResult() {
        double num;
        cout << "숫자를 입력해주세요 : ";
        cin >> num;

        result = num;
    };
    virtual ~calculator() {
    };
   
};

double calculator::result = 0;






class calculatorDivide : public calculator {
    void calculate() {
        double num;

        cout << "숫자를 입력해주세요 : ";
        cin >> num;

        setResult(getResult() / num);
        cout << "-------------------------------------------------------" << endl;
        cout << "결과 : " << getResult() << endl;
        cout << "-------------------------------------------------------" << endl;
    };
};

class calculatorMultiple : public calculator {
    void calculate() {
        double num;

        cout << "숫자를 입력해주세요 : ";
        cin >> num;

        this->setResult(getResult() * num);
        cout << "-------------------------------------------------------" << endl;
        cout << "결과 : " << getResult() << endl;
        cout << "-------------------------------------------------------" << endl;
    }
};

class calculatorPlus : public calculator {
    void calculate() {
        double num;

        cout << "숫자를 입력해주세요 : ";
        cin >> num;

        this->setResult(getResult() + num);
        cout << "-------------------------------------------------------" << endl;
        cout << "결과 : " << getResult() << endl;
        cout << "-------------------------------------------------------" << endl;
    }
};

class calculatorMinus : public calculator {
    void calculate() {
        double num;

        cout << "숫자를 입력해주세요 : ";
        cin >> num;

        this->setResult(getResult() - num);
        cout << "-------------------------------------------------------" << endl;
        cout << "결과 : " << getResult() << endl;
        cout << "-------------------------------------------------------" << endl;
    }
};

int main() {
    int inputNum = 0;
    string comm = "";
    bool isRest = true;
    char oper;
    while (comm != "EXIT")
    {
        if (isRest) {
            calculator::resetResult();
            isRest = false;
        }

        calculator* c;

        cout << "연산자를 입력해주세요 : ";
        cin >> oper;

        switch (oper)
        {
        case '+':
            c =  new calculatorPlus();
            break;
        case '-':
            c =  new calculatorMinus();
            break;
        case '*':
            c =  new calculatorMultiple();
            break;
        case '/':
            c = new calculatorDivide();
            break;
        default:
            cout << "잘못된 연산자를 입력하였습니다." << endl;
            continue;
        }

        c->calculate();

        cout << "연산을 계속 진행하시겠습니까? (Y : 계속, AC : 초기화, EXIT : 종료) : ";

        //정해진 값을 입력하지 않은 경우 계속 입력
        while (true) {
            cin >> comm;

            if (comm == "AC") {
                isRest = true;
                break;
            }
            else if (comm == "Y" || comm == "EXIT") {
                break;
            }
            else {
                cout << "잘못된 명령어 입니다. 대소문자 확인 후 다시 입력해주세요 : ";
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
