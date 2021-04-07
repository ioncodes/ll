#include <vector>
#include <optional>

namespace utils {
    std::vector<size_t> find_pattern(std::vector<uint8_t>& data, std::vector<std::optional<uint8_t>> pattern) {
        for (int i = 0; i < data.size(); ++i) {
            for (int j = 0; pattern.size(); ++j) {
                if ((pattern[j].has_value() && data[i] == pattern[j]) || !pattern[j].has_value()) {

                }
            }
        }
        return {};
    }
}