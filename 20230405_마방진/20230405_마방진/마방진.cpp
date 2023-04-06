#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

int main()
{
    srand((unsigned int)time(NULL));
    int mabangjin = 0;

    std::cout << "마방진의 크기를 정해주세요" << std::endl;
    std::cin >> mabangjin;
    int side = mabangjin;
    mabangjin = mabangjin * mabangjin;
     // N * N의 숫자를 저장하는 array 1~N*N
    int random = 0; // array 숫자 중 하나를 무작위

    while (true) {
        std::vector<std::vector<int>> matrix; //bingo판
        std::vector<int> v; //빙고 한줄
        std::vector<int>array;
        int count = 0;
        for (int i = 0; i < side; i++) {
            matrix.push_back(v);
        }
        while (count < mabangjin)
        {
            bool is_exist = false; //array 안에 지금 뽑은 random 숫자가 있는지 판별하기 위한 bool
            random = rand() % mabangjin + 1;

            for (int i = 0; i < count; i++) {
                if (array[i] == random) {
                    is_exist = true;
                    break;
                }
            }

            if (is_exist == false) { //array 안에 없다면
                array.push_back(random);
                matrix[count / side].push_back(random); 

               // std::cout << "프로그레스 : " << matrix[count / side][count % side] << " ";
                count++;
            }
        }
        int diagonal1 = 0; //대각선1
        int diagonal2 = 0; //대각선2
        std::vector<int> answer_set; // 가로 세로 대각선 한 줄의 합이 들어있는 벡터
        //int answer_set_size = 0;
        for (int i = 0; i < side; i++) {
            int row = 0; // 가로 한줄
            int col = 0; // 세로 한줄

            diagonal1 += matrix[i][i];
            diagonal2 += matrix[i][side - i-1];


            for (int j = 0; j < side; j++) {

                col += matrix[i][j];
                row += matrix[j][i];
            }


            answer_set.push_back(row);
            answer_set.push_back(col);
            //answer_set_size += 2;


        }
        answer_set.push_back(diagonal1);
        answer_set.push_back(diagonal2);

        //answer_set_size += 2;
        std::cout << std::endl;
        int answer = answer_set[0];
        bool correct = true;
        for (int i = 0; i < answer_set.size() ; i++) {
           // std::cout << answer_set[i] << " ";
            if (answer_set[i] != answer) {
                correct = false;
                break;
            }
        }

        if (correct == true) {
            for (int i = 0; i < side; i++) {
                for (int j = 0; j < side; j++) {
                    std::cout << matrix[i][j] << " ";
                }
                std::cout << std::endl;
            }
            break;
        }
        //else {
            //for (int i = 0; i < side; i++) {
                //matrix[i].clear();
          //  }
           /* matrix.clear();
            array.clear();
            answer_set.clear();
            v.assign();*/
       // }

       
    }
   
    }