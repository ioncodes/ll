#include <vector>
#include <optional>

namespace utils {
    template<typename T>
	std::vector<size_t> find_pattern(std::vector<T>& data, std::vector<std::optional<T>> pattern) {
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
}