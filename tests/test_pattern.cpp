#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <ll/pattern.hpp>

TEST_CASE("Pattern tests", "[pattern.hpp]")
{
    SECTION("Find pattern")
    {
        const std::vector<uint8_t> data = { 0x01, 0x02 };
        auto iterators = pattern::find(data, { 0x01, {} });

        REQUIRE(iterators.size() == 1);
        REQUIRE(*iterators[0] == 0x01);
    }

    SECTION("Create pattern")
    {
        auto pattern = pattern::create("01??");

        REQUIRE(pattern[0] == 0x01);
        REQUIRE(pattern[1] == std::nullopt);
    }
}