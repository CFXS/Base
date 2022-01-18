// ---------------------------------------------------------------------
// CFXS Framework Base Module <https://github.com/CFXS/CFXS-Base>
// Copyright (C) 2022 | CFXS / Rihards Veips
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>
// ---------------------------------------------------------------------
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