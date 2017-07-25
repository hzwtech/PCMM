#ifndef SYSTEMERRORINFO_H
#define SYSTEMERRORINFO_H
#include <string>
#ifdef WIN32
#include <winsock2.h>
#endif
namespace IoPlatformWrapper {

#ifdef WIN32
inline int GetLastErrorNo()
{
    return ::WSAGetLastError();
}
std::string GetErrorMessageFromErrorCode(int errorCode);
std::string GetLastErrorMessage();
#else
inline int GetLastErrorNo()
{
    return errno;
}

inline std::string GetErrorMessageFromErrorCode(int errorCode)
{
    return ::strerror(errno);
}

inline std::string GetLastErrorMessage()
{
    return GetSocketErrorMessageFromErrorCode(GetLastSocketErrorNo());
}
#endif


}
#endif // SYSTEMERRORINFO_H
