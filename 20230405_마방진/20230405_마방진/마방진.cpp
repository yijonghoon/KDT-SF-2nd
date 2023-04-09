#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

int main()
{
    srand((unsigned int)time(NULL));
    int side = 0;

    std::cout << "�������� ũ�⸦ �����ּ���" << std::endl;
    std::cin >> side;
    int side_squre = side * side;
     // N * N�� ���ڸ� �����ϴ� array 1~N*N
    int random = 0; // array ���� �� �ϳ��� ������
    int while_count = 0;


    while (true) {
        while_count++; 
        std::cout << while_count << std::endl;

        // �ð�ȭ�� ���� ����Ƚ���� count �ϴ� �ڵ�


        std::vector<std::vector<int>> matrix; //������ ����. pushback�� ���� ���� vector�� Ȱ����.
        std::vector<int> v;
        for (int i = 0; i < side; i++) {
            matrix.push_back(v);
        }
        // ������ ���带 ����� ���� �ڵ�

        int count = 0; // N^2���� ���ڸ� �̱� ���� count
        std::vector<int>array; // ���� N^2 ���� �̾� ���� ���� ���� ex: { 3, 5, 1, 7, 6, 2, 4, 9, 8 } ... ���� �̸��� ��̿��� �˼��մϴ�
        while (count < side_squre)
        {
            random = rand() % side_squre + 1; // ���� ���ڸ� �ϳ� �̰�
            bool is_exist = false; // array �ȿ� ���� ���� random ���ڰ� �ִ��� �Ǻ��ϱ� ���� bool
            for (int i = 0; i < count; i++) {
                if (array[i] == random) {
                    is_exist = true; // array �ȿ� �ߺ��Ǵ� ��찡 �ִٸ� false ���� is_exist�� true�� �ٲ��ش�.
                    break;
                }
            }

            if (is_exist == false) { //array �ȿ� �ߺ��� �ϳ��� ���ٸ�
                array.push_back(random); // array �ȿ� �־� �ְ�
                matrix[count / side].push_back(random); // ������ �ȿ��� ���ڸ� ä���ش�.
                count++;
            }
        }

        // N^2���� ���� ���� set�� �̾ƿ��� �ڵ�


        int diagonal1 = 0; //�밢��1
        int diagonal2 = 0; //�밢��2
        std::vector<int> answer_set; // ���� ���� �밢�� �� ���� ���� ����ִ� ����
        //int answer_set_size = 0;
        for (int i = 0; i < side; i++) {
            int row = 0; // ���� ���� (������ ���� ����)
            int col = 0; // ���� ����

            diagonal1 += matrix[i][i]; // �밢�� ���ϱ�
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

        // ���� ���� �밢���� ���� answer_set�� �־��ִ� �ڵ�



        int answer = answer_set[0]; // array�� ù��° ���ڸ� ���� ǥ������ �����
        bool correct = true;
        for (int i = 1; i < answer_set.size() ; i++) {
           // std::cout << answer_set[i] << " ";
            if (answer_set[i] != answer) {
                correct = false; // �ϳ��� �ٸ��� false
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
            std::cout << std::endl  << while_count << "ȸ �õ� �� �����߽��ϴ�." << std::endl;
            matrix.clear();
            break; // break�� while�� Ż��
        }
      
    }
   
    }

// �ڵ��� �Ѱ� :
// 
// 1. ���ڸ� �̾ƿö� combination�� ���� �ʾƼ� ���ڸ� �̾� ���°� ��ȿ�����̴�.
// 2. Combination�� ���� �ʾƼ� ������ ������ ���� set�� �õ��Ѵ�.
// 3. ���� ���� �밢�� �����ϴ� array�� answer_set�� ������ side�� ũ�⿡ ����ؼ� �������ִµ�, ������ vector�� ó�����̴�.
// 4. 
// 
// 
// 
// 3 X 3 �������� ��� �ּ� 772ȸ �ִ� 19��ȸ 