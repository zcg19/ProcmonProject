#ifndef __FILTER_PORT_HPP__
#define __FILTER_PORT_HPP__

#include "FltPortSerializers.hpp"
#include "../Common/FltPortCommand.hpp"

#include <memory>
#include <string>
#include <thread>
#include <Windows.h>
#include <fltUser.h>
#include <CppShallowStream.hpp>

class FilterPort
{
public:
    FilterPort(
        const std::wstring& PortName
    );

    ~FilterPort();

    NTSTATUS Send(
        _In_ std::shared_ptr<KmUmShared::CommandHeader> Command,
        _In_ std::shared_ptr<KmUmShared::CommandReply> Reply
    );

    void Disconnect();
    bool IsConnected();

private:
    void CloseConnectionPort();
    void Listen();

    NTSTATUS
    HandleMessage(
        Cpp::ShallowStream& InputData,
        Cpp::Stream& OutputStream
    );

    template <class T>
    NTSTATUS HandleMessageNotification(
        Cpp::ShallowStream & InputData
    );

    bool isConnected = false;
    std::wstring portName;
    std::unique_ptr<std::thread> listenerThread = nullptr;
    HANDLE driverPort = INVALID_HANDLE_VALUE;
};


template<class T>
inline NTSTATUS FilterPort::HandleMessageNotification(Cpp::ShallowStream & InputData)
{
    T message;
    InputData >> message;

    if (!InputData.IsValid())
    {
        return ERROR_INVALID_PARAMETER;
    }

    std::wcout << message;
    return ERROR_SUCCESS;
}

#endif //__FILTER_PORT_HPP__
