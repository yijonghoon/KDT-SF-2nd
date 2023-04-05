#include <iostream>
#include<cstdlib> //rand(), srand()
#include<ctime> //time()


int main()
{
    srand((unsigned int)time(NULL));
    int lotto[6];
    int random = 0;
    int count = 0;
    int player_lotto[6];
    int numbers;
    int correct = 0;
    std::cout << "중복 없이 25 이하의 숫자 여섯개를 입력해주세요. 띄어쓰기로 구분 (ex: 10 20 17 25 15 12) " << std::endl;;
    for (int i = 0; i < 6; i++) {
        std::cin >> player_lotto[i];
    }


    while (count < 6)
    {
        bool is_exist = false;
        random = rand() % 25 + 1;

        for (int i = 0; i < count; i++) {
            if (lotto[i] == random) {
                is_exist = true;

            }
        }
        if (is_exist == false) {
            lotto[count] = random;
            count++;
        }
    }
    for (int i = 0; i < 6; i++) {
        std::cout << lotto[i] << " ";
    }

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (lotto[i] == player_lotto[j]) {
                correct++;
            }
        }
    }
    std::cout << std::endl << correct <<"개 맞았습니다." << std::endl;
    std::cout << 7 - correct << "등 입니다 !";
}
