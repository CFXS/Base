#pragma once

// TODO: system endian check

namespace CFXS {

    constexpr inline uint16_t SwapByteOrder16(uint16_t input) {
        return __builtin_bswap16(input);
    }

    constexpr inline uint32_t SwapByteOrder32(uint32_t input) {
        return __builtin_bswap32(input);
    }

    constexpr inline uint16_t HTONS(uint16_t input) {
        return SwapByteOrder16(input);
    }

    constexpr inline uint16_t NTOHS(uint16_t input) {
        return SwapByteOrder16(input);
    }

    constexpr inline uint32_t HTONL(uint32_t input) {
        return SwapByteOrder32(input);
    }

    constexpr inline uint32_t NTOHL(uint32_t input) {
        return SwapByteOrder32(input);
    }

} // namespace CFXS