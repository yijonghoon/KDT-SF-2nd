#pragma comment(lib, "ws2_32.lib") // 명시적으로 라이브러리를 호출하는 방법 중 하나.

#include <WinSock2.h> //winsock 헤더 사용중
#include <string>
#include <iostream>
#include <thread>
#include <vector>

#define MAX_SIZE 1024
#define MAX_CLIENT 3 // 최대 3명

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct SOCKET_INFO {
    SOCKET sck; // ctrl + 클릭 하면 헤더 속 SOCKET 코드를 찾아갈 수 있다, socket은 unsigned int pointer를 갖고 있구나 하고 예측할 수 있다.
    string user; // user : 사람의 이름
};

std::vector<SOCKET_INFO> sck_list; // 서버에 연결된 client 저장할 변수
SOCKET_INFO server_sock; // 서버 소켓의 정보를 저장할 변수
int client_count = 0;  //현재 접속하고 있는 클라이언트의 수 카운트.

void server_init(); // 서버용 소켓을 만드는 함수. ~ listen()
void add_client(); // accept 함수 실행되고 있을 예정
void send_msg(const char* msg); // send () 실행
void recv_msg(int idx); // recv() 실행
void del_client(int idx); // 클라이언트와의 연결을 끊을 때

int main() {
    WSADATA wsa;

    // Winsock를 초기화하는 함수. MAKEWORD(2, 2)는 Winsock의 2.2 버전을 사용하겠다는 의미.
    // 실행에 성공하면 0을, 실패하면 그 이외의 값을 반환.
    // 0을 반환했다는 것은 Winsock을 사용할 준비가 되었다는 의미.
    int code = WSAStartup(MAKEWORD(2, 2), &wsa); // 성공하면 0. !0 => 1

    // code가 0이 되면 if문을 실행하겠다.
    if (!code) {
        server_init(); // 서버측 소켓 활성화

        std::thread th1[MAX_CLIENT]; 
        // 크기가 MAX_CLIENT인 배열 생성. 배열에 담길 자료형은 std::thread
        // thread = 대기, thread가 끝났다고 하기 전까지 main 함수가 종료되지 않도록 해줌. 메소드 .join
        for (int i = 0; i < MAX_CLIENT; i++) {
            th1[i] = std::thread(add_client); 
            // 클라이언트 받을 수 있는 상태를 만들어 줌, accept
            // 클라이언트 별로 각자 다른 일을 할 수 있게끔 다중스레드를 만들어 줌
        }

        while (1) {
            string text, msg = "";

            std::getline(cin, text);
            const char* buf = text.c_str();
            msg = server_sock.user + " : " + buf;
            send_msg(msg.c_str());
        }

        for (int i = 0; i < MAX_CLIENT; i++) {
            th1[i].join();
        }

        closesocket(server_sock.sck); //소켓 종료
    }
    else {
        cout << "프로그램 종료. (Error code : " << code << ")"; // if를 통과 못하면 (초기화 실패), 프로그램 종료
    }

    WSACleanup();

    return 0;
}

void server_init() {
    server_sock.sck = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);  // SOCK_STREAM은 TCP 1, UDP 2, 자유 3 이렇게 코드를 가져온다.
    // 서버 소켓을 특정할 수 있는 int형 숫자를 담음. server+sock의 sck
    // SOCKET_INFO sck, user
    SOCKADDR_IN server_addr = {};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(7777); // ~~~~:7777
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY); //  127.0.0.1: ~~~~

    bind(server_sock.sck, (sockaddr*)&server_addr, sizeof(server_addr));
    // server_sock.sck, 주소를 할당하고 싶은 socket
    // (sockaddr*)&server_addr의 경우 server_addr의 자료형 SOCKADDR_IN을 sockaddr* 형으로 변환

    listen(server_sock.sck, SOMAXCONN);

    server_sock.user = "서버";

    cout << "서버 On" << endl;
}

void add_client() {
    // 클라이언트와 서버와 연결에 성공하면, 새로운 소켓을 하나 생성하게 되는데, 
    // 그 주소를 담을 변수 => addr
    SOCKADDR_IN addr = {};
    int addrsize = sizeof(addr);
    char buf[MAX_SIZE] = { }; // 메시지 최대 길이 설정

    ZeroMemory(&addr, addrsize); //  addr 메모리를 0x00으로 초기화/addrsize = sizeof(addr), 

    SOCKET_INFO new_client = {};
    // sck, user : 클라이언트의 소켓 정보를 저장

    new_client.sck = accept(server_sock.sck, (sockaddr*)&addr, &addrsize);
    // connect()
    recv(new_client.sck, buf, MAX_SIZE, 0); // 클라이언트 connect(), send()
    // 클라이언트 측에서 바로 user 이름을 담아서 send를 함. recv()로 받기 위해
    new_client.user = string(buf); // buf를 string형으로 변환해서 user에 저장

    string msg = "[공지] " + new_client.user + " 님이 입장했습니다.";
    cout << msg << endl; // 서버 콘솔에 공지 찍음.
    sck_list.push_back(new_client); // sck list 에 추가함.
    // [ {12345,"jonghoon"}, {43210,"yijonghoon"},{32134,"hoon"} ]

    std::thread th(recv_msg, client_count); //client_count = 현재 클라이언트의 수(입장 전 0)
    // 방금 생성된 client가 앞으로도 계속 메시지를 받을 수 있도록 recv

    client_count++; // 클라이언트 수 늘려줌.
    cout << "[공지] 현재 접속자 수 : " << client_count << "명" << endl;
    send_msg(msg.c_str());

    th.join(); // 얘를 만날때까지 main함수의 종료가 보류됨.
}

void send_msg(const char* msg) {
    for (int i = 0; i < client_count; i++) {
        send(sck_list[i].sck, msg, MAX_SIZE, 0);
    }
}

void recv_msg(int idx) {
    char buf[MAX_SIZE] = { };
    string msg = "";

    while (1) { //recv_msg가 한번 실행되면 받을때까지 계속 대기.
        ZeroMemory(&buf, MAX_SIZE); // buf 0으로 초기화
        if (recv(sck_list[idx].sck, buf, MAX_SIZE, 0) > 0) {
            msg = sck_list[idx].user + " : " + buf;
            cout << msg << endl;
            send_msg(msg.c_str());
        }
        else {
            msg = "[공지] " + sck_list[idx].user + " 님이 퇴장했습니다.";
            cout << msg << endl;
            send_msg(msg.c_str());
            del_client(idx);
            return;
        }
    }
}

void del_client(int idx) {
    closesocket(sck_list[idx].sck);
    client_count--;
}


/*

코드의 구조
server_init 서버측 소켓 활성화
max client = 3

for(MAX_CLIENT){
클라이언트를 받을 수있는 상태
accept,

*/