// 20230329-실습.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	//  std::ifstream file;
	//  std::string line;
	//  file.open("hello.txt");
	//  std::vector <std::string> lines = {};
	///*  lines.push_back("hello");*/
	//  //cout << lines[0] << endl;;
	//  int counter = 0;
	//  if (file.is_open()) {
	//      while (getline(file, line)) {
	//          lines.push_back(line);
	//          std::cout << line << std::endl;
	//          counter++;
	//      }
	//  }

	//  std::ofstream file2("bye.txt");
	//  if (!file2.fail()) {
	//      cout << "success" << endl;
	//      for (int i = 0 ; i < counter; i++ ) {
	//          file2 << lines[counter -i -1] << std::endl;
	//      }
	//      
	//  }
	//  else cout << "fail to open file\n";


	  //// 과제 1번
	  //std::ofstream file("member.txt");
	  //std::cout << "3명의 회원에 대한 이름 비밀번호를 순차적으로 입력하세요." << std::endl;
	  //std::string information;
	  //for (int i = 0; i < 3; i++){
	  //    cout << i+1 <<"번째 회원 : " ;
	  //    getline(std::cin, information);
	  //    file << information << std::endl;
	  //    cout << endl;

	  //}

	  //cout << "------------------회원 명부 파일 읽기------------------" << std::endl;
	  //std::ifstream file2("member.txt");
	  //while (getline(file2, information)) {
	  //    cout << information << endl;
	  //}
	  // file2.close();
	  //

	  //과제 2번
	std::ofstream file("member_assign.txt");

	std::string information;
	cout << "이름을 입력하세요 : ";
	getline(std::cin, information);
	file << information << std::endl;
	cout << "비밀번호를 입력하세요 : ";
	getline(std::cin, information);
	file << information << std::endl;

	std::ifstream file_open("member_assign.txt");
	string id;
	string pw;
	file_open >> id;
	file_open >> pw;
	file.close();

	std::ifstream file2("member.txt");

	string answer_id;
	string answer_pw;
	bool if_success = false;
	while (!file2.eof()) {
		file2 >> answer_id;
		file2 >> answer_pw;


		if (id == answer_id && pw == answer_pw) {
			std::cout << "로그인 성공!" << endl;
			if_success = true;
			break;
		}

	}
	if (!if_success) {
		std::cout << "로그인 실패!" << endl;
		file2.close();
	}
	else {
		string telephone;
		cout << "전화번호를 입력하세요 : " << std::endl;
		getline(cin, telephone);


		vector<string> signed_member_info;
		int counter1 = 0;
		string member_info;
		bool made_newfile = false;
		if (if_success) {
			std::ifstream file3;
			file3.open("member_tel.txt");
			if (file3.is_open()) {
				while (getline(file3, member_info)) {
					signed_member_info.push_back(member_info);
					counter1++;
				}

				bool match = 0;
				for (int i = 0; i < counter1; i++) {
					if (signed_member_info[i].substr(0,id.length()) == id) {
						signed_member_info[i] = id + " " + telephone;
						match = 1;
					}


				}
				if (match == 0) {
					counter1++;
					signed_member_info.push_back(id + " " + telephone);
				}

				std::ofstream file4("member_tel.txt");

				for (int i = 0; i < counter1; i++) {
					if (i != counter1 - 1) {
						file4 << signed_member_info[i] << endl;
					}
					else {
						file4 << signed_member_info[i];
					}
				}



			}

			else {
				std::ofstream file4("member_tel.txt");
				file4 << id + " " + telephone;
				made_newfile = true;
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
