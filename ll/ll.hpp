#pragma once

namespace ll
{
    using pattern_t = std::optional<uint8_t>;

#ifdef _WIN32
    #include <Windows.h>
    using handle_t = HANDLE;

    enum class operation : uint32_t
    {
        read = GENERIC_READ,
        create_new = CREATE_NEW,
        open_existing = OPEN_EXISTING
    };

    enum class attribute : uint32_t
    {
        normal = FILE_ATTRIBUTE_NORMAL
    };
#else
    using handle_t = int;
#endif
}