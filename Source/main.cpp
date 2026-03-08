#define ASIO_STANDALONE
#include <asio.hpp>
#include <iostream>

#include "LoginServer.h"




int main() {
    try {
        asio::io_context io_context; // kqueue/epoll의 이벤트 루프(Reactor) 역할
        
        LoginServer server(io_context, 7777); // 7777번 포트 개방
        std::cout << "로그인 서버 시작 (Port: 7777)...\n";
        
        // 이 함수가 호출되면 이벤트 루프가 돌면서 비동기 작업들을 처리하기 시작합니다.
        io_context.run(); 
        
    } catch (std::exception& e) {
        std::cerr << "서버 에러 발생: " << e.what() << "\n";
    }
    return 0;
}