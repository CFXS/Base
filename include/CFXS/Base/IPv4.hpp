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

#include <cstdio>
#include <CFXS/Base/ByteOrder.hpp>
#include <CFXS/Base/Debug.hpp>
#include <array>

namespace CFXS {

    class IPv4 {
    public:
        constexpr IPv4() : m_Value(0) {
        }
        constexpr IPv4(uint32_t val) : m_Value(HTONL(val)) {
        }
        constexpr IPv4(uint8_t oct1, uint8_t oct2, uint8_t oct3, uint8_t oct4) :
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
            m_Data{oct1, oct2, oct3, oct4}
#else
            m_Data{oct4, oct3, oct2, oct1}
#endif
        {
        }
        template<size_t N>
        constexpr IPv4(const char (&ip_string)[N]) : m_Value(0) {
            int octet       = 0;
            int num         = 0;
            uint8_t nums[3] = {0, 0, 0};
            for (int i = 0; i <= N; i++) {
                if (i == N || ip_string[i] == '.') {
                    if (num == 1) {
                        m_Data[octet] += nums[0];
                    } else if (num == 2) {
                        m_Data[octet] += nums[1] + nums[0] * 10;
                    } else if (num == 3) {
                        m_Data[octet] += nums[2] + nums[1] * 10 + nums[0] * 100;
                    }

                    octet++;

                    if (i == N || octet == 4) {
                        return;
                    }

                    num     = 0;
                    nums[0] = 0;
                    nums[1] = 0;
                    nums[2] = 0;
                } else {
                    if (ip_string[i] >= '0' && ip_string[i] <= '9') {
                        nums[num] = ip_string[i] - '0';
                        num++;
                        if (num > 3)
                            num = 3;
                    }
                }
            }
        }
        constexpr IPv4(const IPv4& other) : m_Value(other.m_Value) {
        }

        static constexpr IPv4 BROADCAST() {
            return IPv4{0xFFFFFFFF};
        }

        static constexpr IPv4 ANY() {
            return IPv4{0x00000000};
        }

        constexpr uint32_t ToHostOrder() const {
            return HTONL(m_Value);
        }

        constexpr uint32_t GetValue() const {
            return m_Value;
        }

        template<typename T>
        constexpr const T* GetPointerCast() const {
            return reinterpret_cast<const T*>(&m_Value);
        }

        inline bool IsValidSubnetMask() const {
            uint32_t mask = GetValue();
            if (mask == 0)
                return 0;
            if (mask & (~mask >> 1)) {
                return 0;
            } else {
                return 1;
            }
        }

        inline bool IsBroadcast() const {
            return m_Value == 0xFFFFFFFF;
        }

        inline bool IsValidHostAddress() const {
            if (m_Data[0] == 0xFF || m_Data[0] == 0)
                return false;
            if (m_Data[3] == 0xFF || m_Data[3] == 0)
                return false;
            if (m_Data[1] == 0xFF || m_Data[2] == 0xFF)
                return false;

            return true;
        }

        constexpr bool operator==(const IPv4& other) const {
            return m_Value == m_Value;
        }

        constexpr bool operator!=(const IPv4& other) const {
            return m_Value != m_Value;
        }

        inline uint8_t& operator[](uint8_t index) {
            CFXS_ASSERT(index < 4, "Index (%u) out of range", index);
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
            return m_Data[index];
#else
            return m_Data[3 - index];
#endif
        }

        inline const uint8_t& operator[](uint8_t index) const {
            CFXS_ASSERT(index < 4, "Index (%u) out of range", index);
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
            return m_Data[index];
#else
            return m_Data[3 - index];
#endif
        }

        inline IPv4& operator=(const IPv4& other) {
            m_Value = other.m_Value;
            return *this;
        }

        inline char* PrintTo(char* dest, int maxLen) const {
            snprintf(dest, maxLen, "%u.%u.%u.%u", this->operator[](0), this->operator[](1), this->operator[](2), this->operator[](3));
            return dest;
        }

    private:
        union {
            std::array<uint8_t, 4> m_Data;
            uint32_t m_Value;
        };
    };

} // namespace CFXS