#include "MemoryInfoBriefly.h"
#include "MemoryUsageInfo.h"
#include "WriteBuffer.h"
#include "ReadBuffer.h"

namespace Environment {
MomeryInfoBriefly::MomeryInfoBriefly()
{

}

void MomeryInfoBriefly::serialize(Serialize::WriteBuffer& writeBuffer) const
{
    writeBuffer.write(static_cast<uint8_t>(memTotal_.size()));
    writeBuffer.write(memTotal_.c_str(), memTotal_.size());
    writeBuffer.write(static_cast<uint8_t>(memFree_.size()));
    writeBuffer.write(memFree_.c_str(), memFree_.size());
}
void MomeryInfoBriefly::unserialize(Serialize::ReadBuffer& readBuffer)
{
    char buffer[128];
    std::fill(buffer, buffer + 128, 0);
    uint8_t size = 0;

    // memTotal
    readBuffer.read(size);
    readBuffer.read(buffer, size);
    memTotal_ = std::string(buffer, size);

    // memFree
    readBuffer.read(size);
    readBuffer.read(buffer, size);
    memFree_ = std::string(buffer, size);
}

std::ostream& MomeryInfoBriefly::operator <<(std::ostream& os) const
{
    os << "["
       << "memTotal=" << memTotal_
       << ", memFree=" << memFree_
       << "]";
    return os;
}

void MomeryInfoBriefly::updateMemUsageInfo()
{
    MemoryUsageInfo memUsageInfo;
    memUsageInfo.update();
    MemoryUsageInfoRawData rawData = memUsageInfo.getMemoryUsageInfoRawData();
    memTotal_ = rawData[MEMTOTAL];
    memFree_ = rawData[MEMFREE];
}
}
