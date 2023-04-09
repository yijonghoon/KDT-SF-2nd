#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

int main()
{
    srand((unsigned int)time(NULL));
    int side = 0;

    std::cout << "마방진의 크기를 정해주세요" << std::endl;
    std::cin >> side;
    int side_squre = side * side;
     // N * N의 숫자를 저장하는 array 1~N*N
    int random = 0; // array 숫자 중 하나를 무작위
    int while_count = 0;


    while (true) {
        while_count++; 
        std::cout << while_count << std::endl;

        // 시각화를 위해 시행횟수를 count 하는 코드


        std::vector<std::vector<int>> matrix; //마방진 보드. pushback을 쓰기 위해 vector를 활용함.
        std::vector<int> v;
        for (int i = 0; i < side; i++) {
            matrix.push_back(v);
        }
        // 마방진 보드를 만들기 위한 코드

        int count = 0; // N^2개의 숫자를 뽑기 위한 count
        std::vector<int>array; // 숫자 N^2 개를 뽑아 오기 위한 벡터 ex: { 3, 5, 1, 7, 6, 2, 4, 9, 8 } ... 벡터 이름이 어레이여서 죄송합니다
        while (count < side_squre)
        {
            random = rand() % side_squre + 1; // 랜덤 숫자를 하나 뽑고
            bool is_exist = false; // array 안에 지금 뽑은 random 숫자가 있는지 판별하기 위한 bool
            for (int i = 0; i < count; i++) {
                if (array[i] == random) {
                    is_exist = true; // array 안에 중복되는 경우가 있다면 false 였던 is_exist를 true로 바꿔준다.
                    break;
                }
            }

            if (is_exist == false) { //array 안에 중복이 하나도 없다면
                array.push_back(random); // array 안에 넣어 주고
                matrix[count / side].push_back(random); // 마방진 안에도 숫자를 채워준다.
                count++;
            }
        }

        // N^2개의 랜덤 숫자 set을 뽑아오는 코드


        int diagonal1 = 0; //대각선1
        int diagonal2 = 0; //대각선2
        std::vector<int> answer_set; // 가로 세로 대각선 한 줄의 합이 들어있는 벡터
        //int answer_set_size = 0;
        for (int i = 0; i < side; i++) {
            int row = 0; // 가로 한줄 (세로일 수도 있음)
            int col = 0; // 세로 한줄

            diagonal1 += matrix[i][i]; // 대각선 더하기
            diagonal2 += matrix[i][side - i-1];

            for (int j = 0; j < side; j++) {
                col += matrix[i][j];
                row += matrix[j][i];
            }
            answer_set.push_back(row);
            answer_set.push_back(col);
        }
        answer_set.push_back(diagonal1);
        answer_set.push_back(diagonal2);

        // 가로 세로 대각선을 전부 answer_set에 넣어주는 코드



        int answer = answer_set[0]; // array의 첫번째 숫자를 정답 표본으로 사용함
        bool correct = true;
        for (int i = 1; i < answer_set.size() ; i++) {
           // std::cout << answer_set[i] << " ";
            if (answer_set[i] != answer) {
                correct = false; // 하나라도 다르면 false
                break;
            }
        }

        if (correct == true) {
            std::cout << std::endl;
            for (int i = 0; i < side; i++) {
                for (int j = 0; j < side; j++) {
                    std::cout << matrix[i][j] << " ";
                    
                    
                }
                std::cout << std::endl;
                matrix[i].clear();
            }
            std::cout << std::endl  << while_count << "회 시도 후 성공했습니다." << std::endl;
            matrix.clear();
            break; // break로 while문 탈출
        }
      
    }
   
    }

// 코드의 한계 :
// 
// 1. 숫자를 뽑아올때 combination을 쓰지 않아서 숫자를 뽑아 오는게 비효율적이다.
// 2. Combination을 쓰지 않아서 기존에 실패한 숫자 set도 시도한다.
// 3. 가로 세로 대각선 검증하는 array인 answer_set의 갯수는 side의 크기에 비례해서 정해져있는데, 아직은 vector로 처리중이다.
// 4. 
// 
// 
// 
// 3 X 3 마방진의 경우 최소 772회 최대 19만회 