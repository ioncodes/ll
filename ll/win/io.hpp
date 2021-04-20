#pragma once

#include <Windows.h>

// macro: printf("%x\n", GetLastError());


namespace io
{
    HANDLE create_file(LPCSTR                lpFileName,
                       DWORD                 dwDesiredAccess,
                       DWORD                 dwShareMode,
                       LPSECURITY_ATTRIBUTES lpSecurityAttributes,
                       DWORD                 dwCreationDisposition,
                       DWORD                 dwFlagsAndAttributes,
                       HANDLE                hTemplateFile)
    {
        return CreateFileA(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
    }

    BOOL read_file(HANDLE handle, LPVOID buffer, DWORD size)
    {
        DWORD bytes_read;
        return ReadFile(handle, buffer, size, &bytes_read, nullptr);
    }
}