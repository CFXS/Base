#pragma once
#include <cmath>
#include <algorithm>
#include <cstdint>

namespace CFXS::Math {

    using Float_t                 = float;
    using _ContainingType_Float_t = uint32_t;

    static constexpr _ContainingType_Float_t _FLOAT_SIGN_BIT = 0x80000000;
    union _FloatUnion_t {
        Float_t f;
        _ContainingType_Float_t l;
    };

    static constexpr Float_t PI         = 3.14159265358979323846f;
    static constexpr Float_t LOG_OF_10  = 2.302585092994046f;
    static constexpr Float_t LOG2_OF_10 = 0.3010299956639812f;

    inline Float_t Sin(Float_t x) {
        return sinf(x);
    }

    inline Float_t Cos(Float_t x) {
        return cosf(x);
    }

    inline Float_t Pow(Float_t base, Float_t power) {
        return powf(base, power);
    }

    /// @brief Approximate 10^x
    /// @param x power
    /// @return 10^x
    inline Float_t Approx_Pow10(Float_t x) {
        return expf(x * LOG_OF_10);
    }

    /// @brief dB to ratio (power scale)
    /// @param x dB
    /// @return ratio
    inline Float_t Approx_Ratio_From_dB_Power(Float_t x) {
        return Approx_Pow10(x / 10.0f);
    }

    /// @brief dB to ratio (voltage scale)
    /// @param x dB
    /// @return ratio
    inline Float_t Approx_Ratio_From_dB_Voltage(Float_t x) {
        return Approx_Pow10(x / 20.0f);
    }

    /// @brief Approximate log2
    /// @param x value
    /// @return log2(value)
    inline Float_t Approx_Log2(Float_t x) {
        _FloatUnion_t &fl = *(_FloatUnion_t *)&x;
        fl.l &= ~_FLOAT_SIGN_BIT;
        int e;
        e = (fl.l >> 23) & 0x000000ff;
        e -= 0x7e;
        fl.l &= 0x807fffff;
        fl.l |= 0x3f000000;
        float y = 1.23149591368684f * fl.f;
        y += -4.11852516267426f;
        y *= fl.f;
        y += 6.02197014179219f;
        y *= fl.f;
        y += -3.13396450166353f;
        y += e;
        return y;
    }

    // [Log10 Approximation]
    //  - Speed increase: 9.07x (test sample size - 1M)
    //  - Precision: +- 0.001

    /// @brief Approximate log10
    /// @param x value
    /// @return log10(value)
    inline Float_t Approx_Log10(Float_t x) {
        return Approx_Log2(x) * LOG2_OF_10;
    }

    /// @brief Ratio to approximated dB (power scale)
    /// @param x ratio
    /// @return dB
    inline Float_t Approx_Power_dB(Float_t x) {
        return Approx_Log2(x) * LOG2_OF_10 * 10;
    }

    /// @brief Ratio to approximated dB (voltage scale)
    /// @param x ratio
    /// @return dB
    inline Float_t Approx_Voltage_dB(Float_t x) {
        return Approx_Log2(x) * LOG2_OF_10 * 20;
    }

    /// @brief Convert fixed point number to floating point
    /// @tparam FRACTIONAL_BITS number of fractional bits
    /// @param input fixed point value
    /// @return floating point value
    template<int FRACTIONAL_BITS>
    float FixedToFloat(uint32_t input) {
        static_assert(FRACTIONAL_BITS > 0);
        return (static_cast<float>(input) / (1 << FRACTIONAL_BITS));
    }

    /// @brief Convert floating point value to fixed point
    /// @tparam TARGET_TYPE output value type (default = int)
    /// @tparam FRACTIONAL_BITS number of fractional bits
    /// @param input input value
    /// @return fixed point value
    template<int FRACTIONAL_BITS, typename TARGET_TYPE = int>
    TARGET_TYPE FloatToFixed(float input) {
        static_assert(FRACTIONAL_BITS > 0);
        return static_cast<TARGET_TYPE>(input * (1 << FRACTIONAL_BITS));
    }

    /// @brief Remap one number range to another
    /// @tparam T value type
    /// @param x input
    /// @param in_min input low bound
    /// @param in_max input high bound
    /// @param out_min output low bound
    /// @param out_max output high bound
    /// @return remapped value
    template<typename T>
    inline T Map(T x, T in_min, T in_max, T out_min, T out_max) {
        return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
    }

    /// @brief Remap one number range to another
    /// @param x input
    /// @param in_min input low bound
    /// @param in_max input high bound
    /// @param out_min output low bound
    /// @param out_max output high bound
    /// @return remapped value
    inline Float_t Map(Float_t x, Float_t in_min, Float_t in_max, Float_t out_min, Float_t out_max) {
        return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
    }

    /// @brief Clamp value to range
    /// @tparam T value type
    /// @param x value
    /// @param low range low bound
    /// @param high range high bound
    /// @return clamped value
    template<typename T>
    inline T Clamp(T x, T low, T high) {
        return std::clamp<T>(x, low, high);
    }

    template<typename T>
    inline T ClampMap(T x, T in_min, T in_max, T out_min, T out_max) {
        return Clamp<T>(Map<T>(x, in_min, in_max, out_min, out_max), out_min, out_max);
    }

    inline Float_t ClampMap(Float_t x, Float_t in_min, Float_t in_max, Float_t out_min, Float_t out_max) {
        return Clamp<Float_t>(Map<Float_t>(x, in_min, in_max, out_min, out_max), out_min, out_max);
    }

} // namespace CFXS::Math