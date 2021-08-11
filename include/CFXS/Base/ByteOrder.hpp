// [CFXS] //
#pragma once

namespace CFXS {

    constexpr inline uint16_t SwapByteOrder16(uint16_t input) {
        return __builtin_bswap16(input);
    }

    constexpr inline uint32_t SwapByteOrder32(uint32_t input) {
        return __builtin_bswap32(input);
    }

    constexpr inline uint16_t HTONS(uint16_t input) {
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        return SwapByteOrder16(input);
#else
        return input;
#endif
    }

    constexpr inline uint16_t NTOHS(uint16_t input) {
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        return SwapByteOrder16(input);
#else
        return input;
#endif
    }

    constexpr inline uint32_t HTONL(uint32_t input) {
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        return SwapByteOrder32(input);
#else
        return input;
#endif
    }

    constexpr inline uint32_t NTOHL(uint32_t input) {
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        return SwapByteOrder32(input);
#else
        return input;
#endif
    }

} // namespace CFXS