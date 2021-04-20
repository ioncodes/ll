#pragma once

#include <vector>
#include <optional>
#include <filesystem>
#include <fstream>

#ifdef _WIN32
#include <ll/win/io.hpp>
#else
#endif

#include "ll.hpp"

class file
{
private:
    ll::handle_t m_handle = nullptr;
    const std::string m_path;

public:
    explicit file(const std::string& path) : m_path(path)
    {
#ifdef _WIN32
        m_handle = io::create_file(
                path.c_str(),
                static_cast<uint32_t>(ll::operation::read),
                0,
                nullptr,
                static_cast<uint32_t>(ll::operation::open_existing),
                static_cast<uint32_t>(ll::attribute::normal),
                nullptr);
#else
#endif
    }

    ~file()
    {
        this->close();
    }

    inline size_t size()
    {
#ifdef _WIN32
        return GetFileSize(m_handle, nullptr);
#else
#endif
    }

    inline void close()
    {
#ifdef _WIN32
        if (m_handle)
            CloseHandle(m_handle);
#else
#endif
    }

    ll::handle_t handle() const
    {
        return m_handle;
    }

    template<typename T = uint8_t>
    std::vector<T> read(std::streamsize size = 0)
    {
        if (size == 0)
            size = this->size() / sizeof(T);

        assert(size % sizeof(T) == 0 && "size must be multiple of sizeof(T)");

        std::vector<T> buffer(size);

#ifdef _WIN32
        io::read_file(m_handle, buffer.data(), size);
#else
#endif

        return buffer;
    }

    template<typename T = uint8_t>
    static std::vector<T> read(const std::string& path)
    {
        auto opened_file = file{ path };
        return opened_file.read<T>();
    }
};