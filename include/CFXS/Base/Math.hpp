#pragma once
#include <cmath>

namespace CFXS::Math {

    using Float_t = float;

    static constexpr Float_t PI = 3.14159265358979323846f;
    static Float_t Sin(Float_t x) { return sinf(x); }
    static Float_t Cos(Float_t x) { return cosf(x); }
    static Float_t Pow(Float_t base, Float_t power) { return powf(base, power); }

} // namespace CFXS::Math