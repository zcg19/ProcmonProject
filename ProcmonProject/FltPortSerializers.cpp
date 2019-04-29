#include "FltPortSerializers.hpp"

std::wostream& operator<<(std::wostream& Stream, Cpp::String& String)
{
    Stream.write((const wchar_t*)String.GetNakedPointer(), String.GetSize() / sizeof(wchar_t));
    return Stream;
}

std::wostream& operator<<(std::wostream& Stream, KmUmShared::ProcessCreateMessage& ProcessCreateMessage)
{
    Stream << "[ProcessCreateMessage]" << std::endl
        << "\t> [Timestamp] " << ProcessCreateMessage.timestamp << std::endl
        << "\t> [Parent ID] " << ProcessCreateMessage.parentPid << std::endl
        << "\t> [Process ID] " << ProcessCreateMessage.processId << std::endl
        << "\t> [Image Path] " << ProcessCreateMessage.imagePath << std::endl
        << "\t> [Command Line] " << ProcessCreateMessage.commandLine << std::endl
        << std::endl;

    return Stream;
}

std::wostream& operator<<(std::wostream& Stream, KmUmShared::ProcessTerminateMessage& ProcessTerminateMessage)
{
    Stream << "[ProcessTerminateMessage]" << std::endl
        << "\t> [Timestamp] " << ProcessTerminateMessage.timestamp << std::endl
        << "\t> [Process ID] " << ProcessTerminateMessage.processId << std::endl
        << std::endl;

    return Stream;
}

std::wostream & operator<<(std::wostream & Stream, KmUmShared::ThreadCreateMessage & ThreadCreateMessage)
{
    Stream << "[ThreadCreateMessage]" << std::endl
        << "\t> [Timestamp] " << ThreadCreateMessage.timestamp << std::endl
        << "\t> [Process ID] " << ThreadCreateMessage.processId << std::endl
        << "\t> [Thread ID] " << ThreadCreateMessage.threadId << std::endl
        << std::endl;

    return Stream;
}

std::wostream & operator<<(std::wostream & Stream, KmUmShared::ThreadTerminateMessage & ThreadTerminateMessage)
{
    Stream << "[ThreadTerminateMessage]" << std::endl
        << "\t> [Timestamp] " << ThreadTerminateMessage.timestamp << std::endl
        << "\t> [Process ID] " << ThreadTerminateMessage.processId << std::endl
        << "\t> [Thread ID] " << ThreadTerminateMessage.threadId << std::endl
        << std::endl;

    return Stream;
}

std::wostream & operator<<(std::wostream & Stream, KmUmShared::ModuleMessage & ModuleMessage)
{
    Stream << "[ImageLoadedMessage]" << std::endl
        << "\t> [Timestamp] " << ModuleMessage.timestamp << std::endl
        << "\t> [Process ID] " << ModuleMessage.processId << std::endl
        << "\t> [Image Name] " << ModuleMessage.imageName << std::endl
        << "\t> [Image Base] " << std::hex << ModuleMessage.imageBase << std::dec << std::endl
        << "\t> [Image Size] " << std::hex << ModuleMessage.imageSize << std::dec << std::endl
        << std::endl;

    return Stream;
}

std::wostream & operator<<(std::wostream & Stream, KmUmShared::RegistryCreateMessage & RegistryCreateMessage)
{
    Stream << "[RegistryCreateMessage]" << std::endl
        << "\t> [Timestamp] " << RegistryCreateMessage.timestamp << std::endl
        << "\t> [Process ID] " << RegistryCreateMessage.processId << std::endl
        << "\t> [Key Name] " << RegistryCreateMessage .string1 << std::endl
        << "\t> [Status] " << RegistryCreateMessage.status << std::endl
        << std::endl;

    return Stream;
}

std::wostream & operator<<(std::wostream & Stream, KmUmShared::RegistrySetValueMessage & RegistrySetValueMessage)
{
    Stream << "[RegistrySetValueMessage]" << std::endl
        << "\t> [Timestamp] " << RegistrySetValueMessage.timestamp << std::endl
        << "\t> [Process ID] " << RegistrySetValueMessage.processId << std::endl
        << "\t> [Key Name] " << RegistrySetValueMessage.string1 << std::endl
        << "\t> [Value Name] " << RegistrySetValueMessage.string2 << std::endl
        << "\t> [Status] " << RegistrySetValueMessage.status << std::endl
        << std::endl;

    return Stream;
}


std::wostream& operator<<(std::wostream& Stream, KmUmShared::RegistryDeleteKeyValueMessage& RegistryDeleteKeyValueMessage)
{
    Stream << "[RegistryDeleteKeyValueMessage]" << std::endl
        << "\t> [Timestamp] " << RegistryDeleteKeyValueMessage.timestamp << std::endl
        << "\t> [Process ID] " << RegistryDeleteKeyValueMessage.processId << std::endl
        << "\t> [Key Name] " << RegistryDeleteKeyValueMessage.string1 << std::endl
        << "\t> [Value Name] " << RegistryDeleteKeyValueMessage.string2 << std::endl
        << "\t> [Status] " << RegistryDeleteKeyValueMessage.status << std::endl
        << std::endl;

    return Stream;
}
