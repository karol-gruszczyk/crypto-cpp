#ifndef CRYPTO_CPP_LIBRARY_H
#define CRYPTO_CPP_LIBRARY_H

#include <vector>

std::vector<std::byte> get_nth_bit_data(const std::vector<std::byte> &input, unsigned char n_bit = 0);

std::vector<std::byte> save_on_nth_bit(
        const std::vector<std::byte> &input,
        const std::vector<std::byte> &message,
        unsigned char n_bit = 0
);

#endif //CRYPTO_CPP_LIBRARY_H