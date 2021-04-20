#pragma once

#include <vector>
#include <optional>
#include <filesystem>
#include <fstream>

#include "ll.hpp"

namespace utils {
    template<typename... Tx>
    static std::string fmt(const char* fmt, Tx&&... args)
    {
        std::string buffer;
        buffer.resize(snprintf(nullptr, 0, fmt, args...));
        snprintf(buffer.data(), buffer.size() + 1, fmt, std::forward<Tx>(args)...);
        return buffer;
    }

    template<typename T = uint8_t>
    std::vector<T> read_file(const std::filesystem::path& path)
    {
        std::ifstream file(path, std::ios::binary);

        file.seekg(0, std::ios_base::end);
        std::streampos length = file.tellg();
        file.seekg(0, std::ios_base::beg);

        std::vector<T> buffer(length / sizeof(T));
        file.read((char*)buffer.data(), length);

        return buffer;
    }

    template<typename T = uint8_t>
    std::vector<T> slice(const std::vector<T>& data, size_t start, size_t end)
    {
        return std::vector<T>(data.begin() + start, data.begin() + end);
    }
}