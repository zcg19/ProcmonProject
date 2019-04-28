#ifndef __FLT_PORT_PROCESS_TERMINATE_MESSAGE_HPP__ 
#define __FLT_PORT_PROCESS_TERMINATE_MESSAGE_HPP__ 

#include <CppString.hpp>
#include <sal.h>

namespace KmUmShared
{
    class ProcessTerminateMessage
    {
    public:
        ProcessTerminateMessage() = default;
        virtual ~ProcessTerminateMessage() = default;

        ProcessTerminateMessage(
            _In_ unsigned __int64 Timestamp,
            _In_ unsigned __int32 ProcessId
        );

        friend Cpp::Stream& operator<<(Cpp::Stream& Stream, const ProcessTerminateMessage& ProcessCreateMessage);
        friend Cpp::Stream& operator>>(Cpp::Stream& Stream, ProcessTerminateMessage& ProcessCreateMessage);

    public:
        unsigned __int64 timestamp = 0;
        unsigned __int32 processId = 0;
    };
}

#endif //__FLT_PORT_PROCESS_TERMINATE_MESSAGE_HPP__