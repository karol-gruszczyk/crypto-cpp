#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <vector>
#include "library.h"

std::vector<std::byte> get_vector(unsigned length, unsigned char fill) {
    std::vector<std::byte> v(length);
    for (unsigned long i = 0; i < length; ++i) {
        v[i] = std::byte(fill);
    }
    return v;
}

TEST_CASE("reading simple data") {
    REQUIRE(get_nth_bit_data(get_vector(0, 0)) == get_vector(0, 0));
    REQUIRE(get_nth_bit_data(get_vector(5, 0x01)) == get_vector(0, 0));
    REQUIRE(get_nth_bit_data(get_vector(16, 0x01)) == get_vector(2, 0xff));
    REQUIRE(get_nth_bit_data(get_vector(19, 0x01)) == get_vector(2, 0xff));
    REQUIRE(get_nth_bit_data(get_vector(8, 0xfe)) == get_vector(1, 0x00));
}

TEST_CASE("write simple data") {
    REQUIRE(save_on_nth_bit(get_vector(0, 0), get_vector(0, 0)) == get_vector(0, 0));
    REQUIRE(save_on_nth_bit(get_vector(16, 0x00), get_vector(2, 0xff)) == get_vector(16, 0x01));
    REQUIRE(save_on_nth_bit(get_vector(16, 0xff), get_vector(2, 0x00)) == get_vector(16, 0xfe));
}

TEST_CASE("write and read") {
    std::vector<std::byte> data(64, std::byte(0xff));
    std::vector<std::byte> message;
    for (int i = 0; i < 8; ++i) {
        message.push_back(std::byte(i));
    }

    REQUIRE(get_nth_bit_data(save_on_nth_bit(data, message)) == message);
}
