// [CFXS] //
#pragma once

#include <array>

namespace CFXS {

    class MAC_Address {
    public:
        constexpr MAC_Address(uint8_t b) : m_Data({b, b, b, b, b, b}) {
        }
        constexpr MAC_Address(const uint8_t data[6]) : m_Data({data[0], data[1], data[2], data[3], data[4], data[5]}) {
        }
        constexpr MAC_Address(uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint8_t e, uint8_t f) : m_Data({a, b, c, d, e, f}) {
        }
        constexpr MAC_Address(const MAC_Address& other) : m_Data(other.m_Data) {
        }

        constexpr uint8_t* GetDataPointer() {
            return m_Data.data();
        }

        constexpr const uint8_t* GetDataPointer() const {
            return m_Data.data();
        }

        inline bool operator==(const MAC_Address& other) const {
            return memcmp(GetDataPointer(), other.GetDataPointer(), 6) == 0;
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

    private:
        std::array<uint8_t, 6> m_Data;
    };

} // namespace CFXS