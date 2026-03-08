#pragma once
#define ASIO_STANDALONE

#include <asio.hpp>
#include <iostream>
#include <memory>



// [Session 클래스] 연결된 클라이언트 하나를 담당
class Session : public std::enable_shared_from_this<Session> {
public:
    Session(asio::ip::tcp::socket socket);

    virtual void Start();

private:
    virtual void DoRead();

    virtual void DoWrite(std::size_t length);

    asio::ip::tcp::socket socket_;
    enum { max_length = 1024 };
    char data_[max_length];

};
