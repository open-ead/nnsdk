#pragma once

#include <netdb.h>
#include <nn/nn_Result.h>
// @nncbindgen skip-start
#include <nn/util.h>
#include <poll.h>
#include <sys/select.h>
#include <sys/socket.h>
// @nncbindgen skip-end

// @nncbindgen define struct sockaddr*
// @nncbindgen define struct hostent*
// @nncbindgen define struct pollfd*

namespace nn {
class TimeSpan;
}

namespace nn::socket {
struct ResourceStatistics;

#if NN_SDK_VER >= NN_MAKE_VER(7, 0, 0)
struct InAddr {
    uint32_t addr;
};
#endif

// taken from https://switchbrew.org/wiki/Sockets_services#BsdBufferConfig
struct BsdBufferConfig {
    size_t tcp_tx_buf_size =
        0x8000;  ///< Size of the TCP transfer (send) buffer (initial or fixed).
    size_t tcp_rx_buf_size = 0x10000;  ///< Size of the TCP recieve buffer (initial or fixed).
    size_t tcp_tx_buf_max_size =
        0x30000;  ///< Maximum size of the TCP transfer (send) buffer. If it is 0, the size of the
                  ///< buffer is fixed to its initial value.
    size_t tcp_rx_buf_max_size =
        0x30000;  ///< Maximum size of the TCP receive buffer. If it is 0,
                  ///< the size of the buffer is fixed to its initial value.
    size_t udp_tx_buf_size =
        0x2400;  ///< Size of the UDP transfer (send) buffer (typically 0x2400 bytes).
    size_t udp_rx_buf_size = 0xA500;  ///< Size of the UDP receive buffer (typically 0xA500 bytes).
    int sb_efficiency =
        4;  ///< Number of buffers for each socket (standard values range from 1 to 8).
};

struct Config {
    int unkInt1 = 2;  // 0x0 (value is 2 in SMO sdk, 8 in sv. could be BsdBufferConfig's version)
    bool unkBool1 = false;         // 0x4
    bool isUseBsdS = false;        // 0x5
    void* pool;                    // 0x8
    size_t poolSize;               // 0x10
    size_t allocPoolSize;          // 0x18
    BsdBufferConfig bufferConfig;  // 0x20-0x50
    int concurLimit;               // 0x54
    int padding;
};

static_assert(sizeof(Config) == 0x60, "Config Size");

// @nncbindgen
int32_t Recv(int32_t socket, void* out, size_t outLen, int32_t flags);
int32_t RecvFrom(int, void*, size_t, int, sockaddr*, uint32_t*);
// @nncbindgen
int32_t Send(int32_t socket, const void* data, size_t dataLen, int32_t flags);
int32_t SendTo(int, const void*, size_t, int, const sockaddr*, uint32_t);
int32_t Accept(int, sockaddr*, uint32_t*);
// @nncbindgen
int32_t Bind(int, const sockaddr*, uint32_t);
// @nncbindgen
nn::Result Connect(int32_t socket, const sockaddr* address, uint32_t addressLen);
// @nncbindgen
int32_t GetPeerName(int, sockaddr*, uint32_t*);
// @nncbindgen
int32_t GetSockName(int, sockaddr*, uint32_t*);
// @nncbindgen
int32_t GetSockOpt(int, int, int, void*, uint32_t*);
int32_t Listen(int, int);
// @nncbindgen
int32_t SetSockOpt(int32_t socket, int32_t socketLevel, int32_t option, const void*, uint32_t len);
int32_t SockAtMark(int);
int32_t Shutdown(int, int);
int32_t ShutdownAllSockets(bool);
// @nncbindgen
int32_t Socket(int32_t domain, int32_t type, int32_t protocol);
int32_t SocketExempt(int, int, int);
int32_t Write(int, const void*, size_t);
int32_t Read(int, void*, size_t);
// @nncbindgen
nn::Result Close(int32_t socket);
int32_t Select(int, fd_set*, fd_set*, fd_set*, timeval*);
// @nncbindgen
int32_t Poll(pollfd*, size_t, int);
// @nncbindgen
int32_t Fcntl(int, int, ...);
int32_t InetPton(int, const char*, void*);
const char* InetNtop(int af, const void* src, char* dst, uint32_t size);

#if NN_SDK_VER >= NN_MAKE_VER(7, 0, 0)
int32_t InetAton(const char* addressStr, InAddr* addressOut);
char* InetNtoa(InAddr);
#endif

int32_t InetAton(const char* addressStr, in_addr* addressOut);
char* InetNtoa(in_addr);

// @nncbindgen
uint16_t InetHtons(uint16_t val);
// @nncbindgen
uint32_t InetHtonl(uint32_t);
// @nncbindgen
uint16_t InetNtohs(uint16_t);
// @nncbindgen
uint32_t InetNtohl(uint32_t);
// @nncbindgen
int32_t GetLastErrno();
// @nncbindgen
void SetLastErrno(int);
int32_t RecvMsg(int, msghdr*, int);
int32_t RecvMMsg(int, mmsghdr*, size_t, int, nn::TimeSpan*);
int32_t SendMsg(int, const msghdr*, int);
int32_t SendMMsg(int, const mmsghdr*, size_t, int);
int32_t Ioctl(int, uint32_t, void*, size_t);
int32_t Open(const char*, int);
Result Initialize(void* pool, size_t poolSize, size_t allocPoolSize, int concurLimit);
Result Initialize(nn::socket::Config const&);
int32_t Finalize();
int32_t GetAddrInfo(const char*, const char*, const addrinfo*, addrinfo**);
int32_t GetAddrInfo(const char*, const char*, const addrinfo*, addrinfo**, int);
int32_t GetAddrInfoWithoutNsdResolve(const char*, const char*, const addrinfo*, addrinfo**);
int32_t GetAddrInfoWithoutNsdResolve(const char*, const char*, const addrinfo*, addrinfo**, int);
int32_t FreeAddrInfo(addrinfo*);
int32_t GetNameInfo(const sockaddr*, uint32_t, char*, uint32_t, char*, uint32_t, int);
int32_t GetNameInfo(const sockaddr*, uint32_t, char*, uint32_t, char*, uint32_t, int, int);
// @nncbindgen(rename=GetHostByNameCancel)
hostent* GetHostByName(const char* name);
hostent* GetHostByName(const char*, int);
hostent* GetHostByNameWithoutNsdResolve(const char*);
hostent* GetHostByNameWithoutNsdResolve(const char*, int);
hostent* GetHostByAddr(const void*, uint32_t, int);
hostent* GetHostByAddr(const void*, uint32_t, int, int);
// @nncbindgen
int32_t RequestCancelHandle();
// @nncbindgen
int32_t Cancel(int);
int32_t GetHErrno();
int32_t HStrError(int);
int32_t GAIStrError(int);
int32_t Sysctl(int*, size_t, void*, size_t*, void*, size_t);
int32_t DuplicateSocket(int, size_t);
int32_t GetResourceStatistics(ResourceStatistics*, size_t);

}  // namespace nn::socket
