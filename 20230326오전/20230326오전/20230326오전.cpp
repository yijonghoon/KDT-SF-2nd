

#include <iostream>
#include <vector>

namespace test {
    int num = 1;
    int sum(int n, int n2) {
        return n + n2;
    }
}

int main()
{
    int num = 0;
    std::cout << num << std::endl;
    std::cout << test::num << std::endl;

    std::string str = "aa";


    std::vector<int> v0(4);
    // 크기가 4인 배열을 만듦. 모든 값 0으로 초기화

    std::vector<int> v1 = { 1, 2, 3 };
    //크기가 3인 배열. 원소가 1, 2, 3 으로 초기화
  
    std::vector<int> v22(4, 1);
    //크기가 4인 배열을 만듦. 모든 값을 1로 초기화
    //{1,1,1,1}
    std::vector<int> v3;
    v3.assign(5, 2);
    // 크기가 5인 배열을 만듦. 모든 값을 2로 초기화

    std::vector<int> v(7);
    v.assign(5, 2);
    // 벡터의 크기가 5인 배열로 만듦 모두 2로 초기화
    // v.size()로 벡터의 사이즈를 가져올 수 있음
    // v.at()로 
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " "; // out of range 오류가 발생해도 잘 잡아주지 않는다.
        std::cout << v.at(i) << std::endl; // 오류를 잡아줌
    }
    std::cout << "------------------------------------" << std::endl;
    v.push_back(6); // vector의 제일 마지막에 원소를 push함 {2,2,2,2,2,6}
    v.pop_back(); // 제일 마지막 원소를 꺼낸다 {2,2,2,2,2,}
    v.push_back(7); // {2,2,2,2,2,7}
    v.begin(); // vector의 시작 주소를 반환함.
    v.insert(v.begin(), 5); //{5,2,2,2,2,2,6}
    v.erase(v.begin(),v.begin()+3); // {2,2,2,6}

    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " "; // index오류가 발생해도 프로그램이 잡지 못하기때문에 아래에 있는 v.at(i)를 쓰는것이다. 확시랗게 하기 위해서. 근데 버그 재현이 안되고있는 상황
        std::cout << v.at(i) << std::endl;
    }
    v.clear(); // { }

    //이차원배열
    std::vector<std::vector<int>> v2 = {{1,2},{3,4}};
    for (int i = 0; i < v2.size(); i++) {
        for (int j = 0; j < v2.at(i).size(); j++) {
            std::cout << v2.at(i).at(j) << " ";
        }
        std::cout << std::endl;
    }




    return 0;
}

