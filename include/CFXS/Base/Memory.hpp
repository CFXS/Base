#pragma once

#define __mem8(x)  (*(__rw uint8_t*)(x))
#define __mem16(x) (*(__rw uint16_t*)(x))
#define __mem32(x) (*(__rw uint32_t*)(x))
#define __mem64(x) (*(__rw uint64_t*)(x))

template<typename T, typename ADDR>
inline const T& __memT(ADDR addr) {
    constexpr auto size = sizeof(T);
    if constexpr (size == 1) {
        return *(T*)((__rw uint8_t*)(addr));
    }
    if constexpr (size == 2) {
        return *(T*)((__rw uint16_t*)(addr));
    }
    if constexpr (size == 4) {
        return *(T*)((__rw uint32_t*)(addr));
    }
    if constexpr (size == 8) {
        return *(T*)((__rw uint64_t*)(addr));
    }
    static_assert("Invalid size");
    return *(T*)((__rw uint8_t*)(addr));
}