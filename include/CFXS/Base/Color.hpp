// [CFXS] //
#pragma once
#include <cstdint>

namespace CFXS {

    template<typename COMPONENT_TYPE = uint8_t>
    class Color {
    public:
        /// @brief Create RGBA color from 0xAARRGGBB
        /// @param rgba Color value (Alpha 0 = opaque)
        constexpr Color(uint32_t argb) : _raw_val32(argb) {
        }

        /// @brief Create RGBA color from color components
        /// @param r Red
        /// @param g Green
        /// @param b Blue
        /// @param a Alpha (0 = opaque)
        constexpr Color(COMPONENT_TYPE r, COMPONENT_TYPE g, COMPONENT_TYPE b, COMPONENT_TYPE a = 0) : m_B(b), m_G(g), m_R(r), m_A(a) {
        }

        constexpr COMPONENT_TYPE& ref_GetR() {
            return m_R;
        }

        constexpr COMPONENT_TYPE& ref_GetG() {
            return m_G;
        }

        constexpr COMPONENT_TYPE& ref_GetB() {
            return m_B;
        }

        constexpr COMPONENT_TYPE& ref_GetA() {
            return m_A;
        }

        constexpr COMPONENT_TYPE GetR() const {
            return m_R;
        }

        constexpr COMPONENT_TYPE GetG() const {
            return m_G;
        }

        constexpr COMPONENT_TYPE GetB() const {
            return m_B;
        }

        constexpr COMPONENT_TYPE GetA() const {
            return m_A;
        }

        template<typename SCALE_TO>
        constexpr SCALE_TO GetR(SCALE_TO mul) const {
            return static_cast<SCALE_TO>(m_R * mul);
        }

        template<typename SCALE_TO>
        constexpr SCALE_TO GetG(SCALE_TO mul) const {
            return static_cast<SCALE_TO>(m_G * mul);
        }

        template<typename SCALE_TO>
        constexpr SCALE_TO GetB(SCALE_TO mul) const {
            return static_cast<SCALE_TO>(m_B * mul);
        }

        template<typename SCALE_TO>
        constexpr SCALE_TO GetA(SCALE_TO mul) const {
            return static_cast<SCALE_TO>(m_A * mul);
        }

        constexpr uint32_t GetRawValue32() const {
            return _raw_val32;
        }

        template<typename T>
        T CastTo() {
            return Color<T>(m_R, m_G, m_B, m_A);
        }

        template<typename T>
        Color<T> ScaleTo(T scale) {
            return Color<T>(m_R * scale, m_G * scale, m_B * scale, m_A * scale);
        }

    private:
        union {
            struct {
                COMPONENT_TYPE m_B;
                COMPONENT_TYPE m_G;
                COMPONENT_TYPE m_R;
                COMPONENT_TYPE m_A;
            };
            uint32_t _raw_val32;
        };
    };

    using RGBA       = Color<uint8_t>;
    using RGBA_Float = Color<float>;

} // namespace CFXS