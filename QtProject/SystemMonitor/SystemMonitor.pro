#-------------------------------------------------
#
# Project created by QtCreator 2017-06-09T20:39:28
#
#-------------------------------------------------

QT       -= core gui

TARGET = SystemMonitor
TEMPLATE = lib
CONFIG += staticlib

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS


INCLUDEPATH += ../../sourceCode/Serialize \
               ../../sourceCode/Common \
               ../../sourceCode/TraceLog \
               ../../sourceCode/Configure \
               ../../sourceCode/EventHandler \
               ../../sourceCode/TimeHandler \
               ../../sourceCode/Network \
               ../../sourceCode/IoPlatformWrapper \
               ../../sourceCode/Connection \
               ../../sourceCode/Environment \
               ../../sourceCode/IpcMessage \
               ../../sourceCode/SystemMonitorMessage
               ../../sourceCode/Serialize
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES +=../../sourceCode/SystemMonitor/SystemMonitorProcess.cpp \
    ../../sourceCode/Ipc/IIpcConnectionClientStrategy.cpp \
    ../../sourceCode/Ipc/IpcClient.cpp \
    ../../sourceCode/Ipc/IpcConnectionTcpStrategy.cpp \
    ../../sourceCode/IpcMessage/IpcMessageIdGenerator.cpp \
    ../../sourceCode/IpcMessage/IIpcMessage.cpp \
    ../../sourceCode/Connection/IConnectionRx.cpp \
    ../../sourceCode/Common/FilePathHandler.cpp \
    ../../sourceCode/Common/LocalTime.cpp \
    ../../sourceCode/Common/Random.cpp \
    ../../sourceCode/Common/remove_character.cpp \
    ../../sourceCode/Common/replace_character.cpp \
    ../../sourceCode/Common/SystemTime.cpp \
    ../../sourceCode/Common/TimeStat.cpp \
    ../../sourceCode/SystemMonitorMessage/ISystemMonitorMessage.cpp \
    ../../sourceCode/SystemMonitorMessage/SystemInfoMessage.cpp \
    ../../sourceCode/Serialize/ISerializable.cpp \
    ../../sourceCode/Serialize/ReadBuffer.cpp \
    ../../sourceCode/Serialize/WriteBuffer.cpp \
    ../../sourceCode/Environment/CpuUsage.cpp \
    ../../sourceCode/Environment/CpuUsageCalculator.cpp \
    ../../sourceCode/Environment/CpuUsageInfo.cpp \
    ../../sourceCode/Network/IpAddress.cpp \
    ../../sourceCode/Network/IpPort.cpp \
    ../../sourceCode/Network/IpSocketEndpoint.cpp \
    ../../sourceCode/Network/ITcpClient.cpp \
    ../../sourceCode/Network/ITcpServer.cpp \
    ../../sourceCode/Network/SocketImp.cpp \
    ../../sourceCode/Network/TcpClient.cpp \
    ../../sourceCode/Network/TcpServer.cpp \
    ../../sourceCode/Network/TcpSocket.cpp \
    ../../sourceCode/IoPlatformWrapper/SocketWrapper.cpp

HEADERS += \
    ../../sourceCode/SystemMonitor/SystemMonitorProcess.h \
    ../../sourceCode/Ipc/Component.h \
    ../../sourceCode/Ipc/IIpcConnectionClientStrategy.h \
    ../../sourceCode/Ipc/IpcClient.h \
    ../../sourceCode/Ipc/IpcConnectionTcpStrategy.h \
    ../../sourceCode/IpcMessage/IpcMessageIdGenerator.h \
    ../../sourceCode/IpcMessage/IIpcMessage.h \
    ../../sourceCode/IpcMessage/IpcMessageType.h \
    ../../sourceCode/Connection/IConnectionRx.h \
    ../../sourceCode/Connection/IConnectionTx.h \
    ../../sourceCode/Common/App.h \
    ../../sourceCode/Common/AppConst.h \
    ../../sourceCode/Common/FilePathHandler.h \
    ../../sourceCode/Common/generic.h \
    ../../sourceCode/Common/LocalTime.h \
    ../../sourceCode/Common/Macro.h \
    ../../sourceCode/Common/operator.h \
    ../../sourceCode/Common/Random.h \
    ../../sourceCode/Common/remove_character.h \
    ../../sourceCode/Common/replace_character.h \
    ../../sourceCode/Common/SystemTime.h \
    ../../sourceCode/Common/TimeStat.h \
    ../../sourceCode/SystemMonitorMessage/ISystemMonitorMessage.h \
    ../../sourceCode/SystemMonitorMessage/SystemInfoMessage.h \
    ../../sourceCode/SystemMonitorMessage/Component.h \
    ../../sourceCode/Serialize/BufferToData.h \
    ../../sourceCode/Serialize/DataToBuffer.h \
    ../../sourceCode/Serialize/ISerializable.h \
    ../../sourceCode/Serialize/ReadBuffer.h \
    ../../sourceCode/Serialize/WriteBuffer.h \
    ../../sourceCode/Environment/Component.h \
    ../../sourceCode/Environment/CpuUsage.h \
    ../../sourceCode/Environment/CpuUsageCalculator.h \
    ../../sourceCode/Environment/CpuUsageDataType.h \
    ../../sourceCode/Environment/CpuUsageInfo.h \
    ../../sourceCode/Network/IpAddress.h \
    ../../sourceCode/Network/IpPort.h \
    ../../sourceCode/Network/IpSocketEndpoint.h \
    ../../sourceCode/Network/ITcpClient.h \
    ../../sourceCode/Network/ITcpServer.h \
    ../../sourceCode/Network/SocketImp.h \
    ../../sourceCode/Network/TcpClient.h \
    ../../sourceCode/Network/tcpresult.h \
    ../../sourceCode/Network/TcpServer.h \
    ../../sourceCode/Network/TcpSocket.h \
    ../../sourceCode/Network/TcpState.h \
    ../../sourceCode/Network/Component.h \
    ../../sourceCode/IoPlatformWrapper/SocketWrapper.h \
    ../../sourceCode/IoPlatformWrapper/SocketWrapperDef.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
