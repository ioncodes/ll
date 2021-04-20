#pragma once

#include <vector>
#include <optional>
#include <filesystem>
#include <fstream>
#include "utils.hpp"

namespace pattern {
    using pattern_t = std::optional<uint8_t>;

    template<typename T>
    auto find(const std::vector<T> &data, std::vector<pattern_t> pattern)
    {
        std::vector<typename std::vector<T>::const_iterator> indices;

        for (size_t i = 0; i < data.size(); ++i)
        {
            bool found = false;

            for (size_t j = 0; j < pattern.size(); ++j)
            {
                found = (pattern[j].has_value() && i + j < data.size() && data[i + j] == pattern[j]) ||
                        !pattern[j].has_value();

                if (!found)
                    break;
            }

            if (found)
                indices.push_back(std::next(data.begin(), i));
        }

        return indices;
    }

    auto create(const std::string& pattern_str)
    {
        std::vector<pattern_t> pattern;

        for (auto ptr = pattern_str.begin(); ptr < pattern_str.end(); ptr++)
        {
            const char character1 = *ptr;
            const char character2 = *std::next(ptr);

            if (character1 == '?' || character2 == '?')
            {
                pattern.emplace_back(std::nullopt);
                continue;
            }

            const auto hex_string = utils::fmt("0x%c%c", character1, character2);
            const auto hex_value = std::stoul(hex_string, nullptr, 16);
            pattern.emplace_back(hex_value);
        }

        return pattern;
    }
};