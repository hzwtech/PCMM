#include "SystemMonitorConnectionTx.h"
#include "ISystemMonitorMessage.h"
#include "ReadBuffer.h"
#include "Trace.h"
#include <stdint.h>

namespace SystemMonitor {
SystemMonitorConnectionReceiver::SystemMonitorConnectionReceiver(std::shared_ptr<ISystemMonitorHandler> monitorHandler)
    :monitorHandler_(monitorHandler)
{
}

SystemMonitorConnectionReceiver::~SystemMonitorConnectionReceiver()
{

}

void SystemMonitorConnectionReceiver::onConnect()
{

}

void SystemMonitorConnectionReceiver::onReceive(std::unique_ptr<IpcMessage::IIpcMessage> msg)
{
    TRACE_ENTER();
    if (!msg)
    {
        TRACE_ERROR("Invalid message!");
        return;
    }
    SystemMonitorMessage::ISystemMonitorMessage* message = dynamic_cast<SystemMonitorMessage::ISystemMonitorMessage*>(msg.get());
    if (message != nullptr)
    {
        IpcMessage::SystemMonitorType systemMonitorType = message->getSystemMonitorType();
        switch (systemMonitorType)
        {
        case IpcMessage::SystemMonitorType::MonitorRequest:
            monitorHandler_->reportSystemInfo();
            break;
        default:
            TRACE_ERROR("Unsupported message! monitor type = " << systemMonitorType);
            break;
        }
    }
    else
    {
        TRACE_ERROR("Unsupported message! message type = " << msg->getMessageType());
    }
}

void SystemMonitorConnectionReceiver::onDisconnect()
{

}

}
