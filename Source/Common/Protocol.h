#pragma once
#include <cstdint>

#pragma pack(push, 1)


struct packetHeader
{
    uint16_t size;
    uint16_t p_id;
};


enum class PacketID : uint16_t
{
    // LOGIN
    LOGIN_REQUEST = 1,
    LOGIN_RESPONSE = 2,


    // GAME SESSION
    SESSION_ENTER = 30,
    SESSION_LEAVE = 31
};


/********************************************
 * 로그인 요청 및 결과 패킷
********************************************/
struct LoginPacket_Req
{
    packetHeader header;
    char user_id[32];
    char password[32];
};

struct LoginPacket_Res
{
    packetHeader header;
    uint8_t isSuccess;          // 1: 성공, 0: 실패
    uint64_t loginToken;        // 로그인 성공 시 부여받은 PID
    char userName[32];          // db 상에 있는 유저네임 반환
};
















#pragma pack(pop)