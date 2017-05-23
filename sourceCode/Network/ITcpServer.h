#ifndef _NETWORK_ITCPSERVER_H_
#define _NETWORK_ITCPSERVER_H_
#include "TcpResult.h"
namespace Network {

class ITcpServer
{
public:
    ITcpServer();
    ~ITcpServer();
    virtual TcpResult init() = 0;
    virtual TcpResult listen(int backlog) = 0;
    virtual TcpResult accept(int flag) = 0;
    virtual TcpResult disconnect() = 0;
    virtual TcpResult cleanup() = 0;
};

}
#endif // _NETWORK_ITCPSERVER_H_