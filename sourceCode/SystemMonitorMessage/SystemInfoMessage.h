#ifndef _SYSTEMMONITORMESSAGE_SYSTEMINFOMESSAGE_H_
#define _SYSTEMMONITORMESSAGE_SYSTEMINFOMESSAGE_H_
#include "ISystemMonitorMessage.h"
#include "CpuUsageInfo.h"
#include "SystemInfoBriefly.h"
#include "Component.h"
#include "Macro.h"

namespace SystemMonitorMessage {

class SystemInfoMessage : public ISystemMonitorMessage
{
    Environment::CpuUsageInfo cpuUsageInfo_;
    Environment::SystemInfoBriefly systemInfoBriefly_;
public:
    SystemInfoMessage();
    SystemInfoMessage(const Environment::CpuUsageInfo& cpuUsageInfo,
                      const Environment::SystemInfoBriefly& systemInfoBriefly);
    inline const Environment::CpuUsageInfo& getCpuUsageInfo() const {return cpuUsageInfo_;}
    inline const Environment::SystemInfoBriefly& getSystemInfoBriefly() const {return systemInfoBriefly_;}
    virtual ~SystemInfoMessage();

private:
    virtual void serialize(Serialize::WriteBuffer& writeBuffer) const;
    virtual void unserialize(Serialize::ReadBuffer& readBuffer);
    virtual IpcMessage::SystemMonitorMessageType getSystemMonitorType() const;
    virtual std::ostream& operator<< (std::ostream& os) const;

private:
    void write(Serialize::WriteBuffer& writeBuffer) const;
    void read(Serialize::ReadBuffer& readBuffer);
    void print(std::ostream& os) const;
public:
    GETCLASSNAME(SystemInfoMessage)
};

}

#endif // _SYSTEMMONITORMESSAGE_SYSTEMINFOMESSAGE_H_
