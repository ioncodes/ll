#include <catch2/catch.hpp>
#include <ll/file.hpp>

TEST_CASE("File tests", "[file.hpp]")
{
    SECTION("Open file")
    {
#ifdef _WIN32
        auto test_file = file{"tests.exe"};
        REQUIRE(test_file.handle() != INVALID_HANDLE_VALUE);
#else
        auto test_file = file{"/bin/sh"};
        auto content = test_file.read();
        REQUIRE(test_file.read()[1] == 'E');
#endif
    }

    SECTION("Read file")
    {
#ifdef _WIN32
        auto test_file = file{"tests.exe"};
#else
        auto test_file = file{"/bin/sh"};
        auto content = test_file.read();
        REQUIRE(test_file.read()[1] == 'E');
#endif

        auto content = test_file.read();

        REQUIRE(content[0] == 'M');
        REQUIRE(content[1] == 'Z');
    }
}