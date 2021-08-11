// [CFXS] //
#pragma once

#include <array>
#include <CFXS/Base/ByteOrder.hpp>
#include <CFXS/Base/Debug.hpp>

namespace CFXS {

    class IPv4 {
    public:
        constexpr IPv4(uint32_t val) : m_Value(val) {
        }
        constexpr IPv4(uint8_t oct1, uint8_t oct2, uint8_t oct3, uint8_t oct4) : m_Bytes{oct1, oct2, oct3, oct4} {
        }
        constexpr IPv4(const IPv4& other) : m_Value(other.m_Value) {
        }

        constexpr uint32_t ToNetworkOrder() const {
            return HTONL(m_Value);
        }

        constexpr uint32_t GetValue() const {
            return m_Value;
        }

        inline bool IsValidNetmask() const {
            uint32_t mask = ToNetworkOrder();
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
            if (m_Bytes[0] == 0xFF || m_Bytes[0] == 0)
                return false;
            if (m_Bytes[3] == 0xFF || m_Bytes[3] == 0)
                return false;
            if (m_Bytes[1] == 0xFF || m_Bytes[2] == 0xFF)
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
            return m_Bytes[index];
#else
            return m_Bytes[3 - index];
#endif
        }

        inline const uint8_t& operator[](uint8_t index) const {
            CFXS_ASSERT(index < 4, "Index (%u) out of range", index);
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
            return m_Bytes[index];
#else
            return m_Bytes[3 - index];
#endif
        }

    private:
        union {
            std::array<uint8_t, 4> m_Bytes;
            uint32_t m_Value;
        };
    };

} // namespace CFXS