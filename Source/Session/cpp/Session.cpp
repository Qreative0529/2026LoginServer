#include "Session.h"


using asio::ip::tcp;

Session::Session(tcp::socket socket) : socket_(std::move(socket)) {}

void Session::Start()
{
    DoRead();
}



void Session::DoRead()
{
    auto self(shared_from_this());
    socket_.async_read_some(asio::buffer(data_, max_length),
    [this, self](std::error_code ec, std::size_t length)
    {
        if(!ec)
        {
            std::cout << "클라이언트 수신 패킷 : " << std::string(data_, max_length) << "\n";
            DoWrite(length);
        }
    });
}


void Session::DoWrite(std::size_t length)
{
    auto self(shared_from_this());
    asio::async_write(socket_, asio::buffer(data_, length),
    [this, self](std::error_code ec, std::size_t length)
    {
        if (!ec) DoRead();
    });
}