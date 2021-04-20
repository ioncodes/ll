#include <catch2/catch.hpp>
#include <ll/file.hpp>

TEST_CASE("File tests", "[file.hpp]")
{
    SECTION("Open file")
    {
#ifdef _WIN32
        test_file = file{"C:\\Windows\\System32\\cmd.exe"};
#else
        auto test_file = file{"/bin/sh"};
        auto content = test_file.read();
        REQUIRE(test_file.read()[1] == 'E');
#endif
    }
}