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

#include <array>
#include <cstring>

namespace CFXS {

    class MAC_Address {
    public:
        constexpr MAC_Address() : m_Data({0, 0, 0, 0, 0, 0}) {
        }
        constexpr MAC_Address(uint8_t b) : m_Data({b, b, b, b, b, b}) {
        }
        constexpr MAC_Address(const uint8_t data[6]) : m_Data({data[0], data[1], data[2], data[3], data[4], data[5]}) {
        }
        constexpr MAC_Address(uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint8_t e, uint8_t f) : m_Data({a, b, c, d, e, f}) {
        }
        constexpr MAC_Address(const MAC_Address& other) : m_Data(other.m_Data) {
        }

        /// @brief Construct MAC address from string
        /// @param mac_string "12:34:56:AB:CD:EF"
        template<size_t N>
        constexpr MAC_Address(const char (&mac_string)[N]) : m_Data({0, 0, 0, 0, 0, 0}) {
            int idx = 0;
            int loc = 0;
            for (int i = 0; i < N; i++) {
                char ch = mac_string[i];

                if (ch == ':') {
                    idx++;
                    loc = 0;
                    continue;
                }

                if (loc < 2) {
                    if (ch >= '0' && ch <= '9') {
                        int val = ch - '0';
                        m_Data[idx] += loc & 1 ? val : (val << 4);
                    } else if (ch >= 'a' && ch <= 'f') {
                        int val = (ch - 'a') + 10;
                        m_Data[idx] += loc & 1 ? val : (val << 4);
                    } else if (ch >= 'A' && ch <= 'F') {
                        int val = (ch - 'A') + 10;
                        m_Data[idx] += loc & 1 ? val : (val << 4);
                    }
                }

                loc++;
            }
        }

        /// @brief Get raw data pointer
        /// @return Raw data pointer
        constexpr uint8_t* GetRawData() {
            return m_Data.data();
        }

        /// @brief Get raw data pointer
        /// @return Raw data pointer
        constexpr const uint8_t* GetRawData() const {
            return m_Data.data();
        }

        inline bool operator==(const MAC_Address& other) const {
            return memcmp(GetRawData(), other.GetRawData(), 6) == 0;
        }

        inline bool operator!=(const MAC_Address& other) const {
            return !(*this == other);
        }

        inline uint8_t& operator[](uint8_t index) {
            return m_Data[index];
        }

        inline const uint8_t& operator[](uint8_t index) const {
            return m_Data[index];
        }

        inline MAC_Address& operator=(const MAC_Address& other) {
            m_Data = other.m_Data;
            return *this;
        }

        /// @brief Print formatted string to buffer
        /// @param dest Buffer to print to
        /// @param maxLen Max buffer size
        /// @return Printed end pointer
        inline char* PrintTo(char* dest, int maxLen) const {
            snprintf(dest, maxLen, "%02X:%02X:%02X:%02X:%02X:%02X", m_Data[0], m_Data[1], m_Data[2], m_Data[3], m_Data[4], m_Data[5]);
            return dest;
        }

    private:
        std::array<uint8_t, 6> m_Data;
    };

} // namespace CFXS