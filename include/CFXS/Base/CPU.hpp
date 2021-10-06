// ---------------------------------------------------------------------
// CFXS Framework Base Module <https://github.com/CFXS/CFXS-Base>
// Copyright (C) 2021 | CFXS / Rihards Veips
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
#include <cstddef>

namespace CFXS::CPU {

    static constexpr size_t CLOCK_FREQUENCY = CFXS_CPU_CLOCK_FREQUENCY;
    static constexpr size_t CYCLES_PER_MS   = CLOCK_FREQUENCY / 1000;
    static constexpr size_t CYCLES_PER_USEC = CLOCK_FREQUENCY / 1000000;

    // TODO: platform specific template
    static __always_inline uint32_t GetCycleCount() { return (*(volatile uint32_t*)0xE0001004); }
    static __always_inline void EnableInterrupts() { asm volatile("cpsie i"); };
    static __always_inline void DisableInterrupts() { asm volatile("cpsid i"); };
    static __always_inline bool AreInterruptsEnabled() {
        uint32_t primask;
        asm volatile("mrs %0, primask" : "=r"(primask));
        return primask == 0;
    }

    void Delay_us(size_t us);
    void Delay_ms(size_t ms);

} // namespace CFXS::CPU