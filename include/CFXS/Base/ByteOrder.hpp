#pragma once

namespace CFXS {

    constexpr inline uint16_t SwapByteOrder16(uint16_t input) {
        return __builtin_bswap16(input);
    }

    constexpr inline uint32_t SwapByteOrder32(uint32_t input) {
        return __builtin_bswap32(input);
    }

} // namespace CFXS