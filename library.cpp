#include "library.h"

#include <cstddef>
#include <stdexcept>

std::vector<std::byte> get_nth_bit_data(const std::vector<std::byte>& input, unsigned char n_bit) {
    auto byte_count = input.size() / 8;
    auto data = std::vector<std::byte >(byte_count, std::byte(0x00));
    auto bitAnd = std::byte(0x01) << n_bit;

    for (unsigned long i = 0; i < byte_count; ++i) {
        for (int j = 7; j >= 0; --j) {
            data[i] <<= 1;
            data[i] |= input[i * 8 + j] & bitAnd;
        }
    }

    return data;
}


std::vector<std::byte> save_on_nth_bit(
        const std::vector<std::byte>& input,
        const std::vector<std::byte>& message,
        unsigned char n_bit
        ) {
    if (message.size() > input.size() / 8) {
        throw std::overflow_error("received too long message to store in input");
    }

    auto result = input;

    for (unsigned long i = 0; i < message.size(); ++i) {
        auto byte = message[i];
        for (int j = 0; j < 8; ++j) {
            auto bit = byte & std::byte(0x01);
            if (bit == std::byte(1))
                result[i * 8 + j] |= (std::byte(1) << n_bit);
            else
                result[i * 8 + j] &= ~(std::byte(1) << n_bit);
            byte >>= 1;
        }
    }

    return result;
}

