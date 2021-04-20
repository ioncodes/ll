#pragma once

#include <vector>
#include <optional>
#include <filesystem>
#include <fstream>

class file
{
private:
    std::ifstream m_file;
    std::filesystem::path m_path;
    std::streampos m_size;

public:
    explicit file(const std::string& path) :
        m_path(path), m_file(std::ifstream(m_path, std::ios::binary)), m_size(0)
    {
        m_file.seekg(0, std::ios_base::end);
        m_size = m_file.tellg();
        m_file.seekg(0, std::ios_base::beg);
    }

    template<typename T = uint8_t>
    std::vector<T> read(std::streamsize amount = 0)
    {
        if (amount == 0)
            amount = m_size / sizeof(T);

        assert(amount % sizeof(T) == 0 && "amount must be multiple of sizeof(T)");

        std::vector<T> buffer(amount);
        m_file.read((char*)buffer.data(), amount);

        return buffer;
    }

    template<typename T = uint8_t>
    static std::vector<T> read(const std::string& path)
    {
        auto opened_file = file{ path };
        return opened_file.read<T>();
    }
};