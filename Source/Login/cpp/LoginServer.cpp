#include <iostream>

#include "LoginServer.h"
#include "Session.h"


using asio::ip::tcp;


LoginServer::LoginServer(asio::io_context& io_context, short port)
        : acceptor_(io_context, tcp::endpoint(tcp::v4(), port))
        {
            DoAccept();
        }



void LoginServer::DoAccept()
{
    acceptor_.async_accept(
        [this](std::error_code ec, tcp::socket socket)
        {
            if(!ec)
            {
                std::cout << "신규 클라이언트 접속 성공 !" << std::endl;
                std::make_shared<Session>(std::move(socket))->Start();
            }
            DoAccept();
        }
    );
}