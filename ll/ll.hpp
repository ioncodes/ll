#pragma once

namespace ll
{
    using pattern_t = std::optional<uint8_t>;

#ifdef _WIN32
    #include <Windows.h>
    using handle_t = HANDLE;
#else
    using handle_t = void*;
#endif
}