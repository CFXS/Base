#pragma once

#include <array>

namespace CFXS {

    class MAC_Address {
    public:
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

        constexpr bool operator==(const MAC_Address& other) const {
            uint32_t first   = *reinterpret_cast<const uint32_t*>(GetDataPointer());
            uint32_t first2  = *reinterpret_cast<const uint32_t*>(other.GetDataPointer());
            uint16_t second  = *reinterpret_cast<const uint16_t*>(GetDataPointer() + 4);
            uint16_t second2 = *reinterpret_cast<const uint16_t*>(other.GetDataPointer() + 4);

            return (first == first2) && (second == second2);
        }

        constexpr bool operator!=(const MAC_Address& other) const {
            return !(*this == other);
        }

        constexpr uint8_t& operator[](uint8_t index) {
            return m_Data[index];
        }

        constexpr const uint8_t& operator[](uint8_t index) const {
            return m_Data[index];
        }

    private:
        std::array<uint8_t, 6> m_Data;
    };

} // namespace CFXS