#define ASIO_STANDALONE
#include <asio.hpp>


// [LoginServer 클래스] 연결을 수락(Accept)하고 세션을 생성
class LoginServer {
public:
    LoginServer(asio::io_context& io_context, short port);

private:
    virtual void DoAccept();

    asio::ip::tcp::acceptor acceptor_;
};

