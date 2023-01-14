#pragma once
#include <cmath>

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

    inline Float_t Approx_Pow10(Float_t x) {
        return expf(x * LOG_OF_10);
    }

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

    inline Float_t Approx_Log10(Float_t x) {
        return Approx_Log2(x) * LOG2_OF_10;
    }

    inline Float_t Approx_Power_dB(Float_t x) {
        return Approx_Log2(x) * LOG2_OF_10 * 10;
    }

    inline Float_t Approx_Voltage_dB(Float_t x) {
        return Approx_Log2(x) * LOG2_OF_10 * 20;
    }

    template<int FRACTIONAL_BITS>
    float FixedToFloat(uint32_t input) {
        static_assert(FRACTIONAL_BITS > 0);
        return (static_cast<float>(input) / (1 << FRACTIONAL_BITS));
    }

} // namespace CFXS::Math