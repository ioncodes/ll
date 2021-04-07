#include <vector>
#include <optional>
#include <filesystem>
#include <fstream>

#include "ll.hpp"

namespace utils {
    template<typename T>
	std::vector<size_t> find_pattern(const std::vector<T>& data, std::vector<ll::pattern_t> pattern) {
		std::vector<size_t> indices;

		for (size_t i = 0; i < data.size(); ++i) {
			bool found = false;

			for (size_t j = 0; j < pattern.size(); ++j) {
				found = (pattern[j].has_value() && i + j < data.size() && data[i + j] == pattern[j]) || !pattern[j].has_value();

				if (!found) break;
			}

			if (found) indices.push_back(i);
		}

		return indices;
	}

	template<typename T = uint8_t>
    std::vector<T> read_file(const std::filesystem::path& path) {
        std::ifstream file(path, std::ios::binary);

        file.seekg(0, std::ios_base::end);
        std::streampos length = file.tellg();
        file.seekg(0, std::ios_base::beg);

        std::vector<T> buffer(length / sizeof(T));
        file.read((char*)buffer.data(), length);

        return buffer;
    }

	template<typename T = uint8_t>
	std::vector<T> slice(const std::vector<T>& data, size_t start, size_t end) {
		return std::vector<T>(data.begin() + start, data.begin() + end);
	}
}