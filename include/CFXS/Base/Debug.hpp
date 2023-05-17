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

#include "ANSI_Colors.hpp"
#include "DebugTerminal.hpp"
#include <stdio.h>

#ifdef CFXS_DEBUG
    #define CFXS_BREAK()     __bkpt
    #define CFXS_printf(...) printf(__VA_ARGS__)
#endif

#ifndef CFXS_BREAK
    #define CFXS_BREAK()
#endif
#ifndef CFXS_printf
    #define CFXS_printf(...) printf(__VA_ARGS__)
#endif

#ifdef CFXS_DEBUG_ASSERT
    #define CFXS_ASSERT(condition, ...)                                 \
        if (!(condition)) {                                             \
            printf(DEBUG_TERMINAL_ERROR_COLOR "[ASSERT] " __VA_ARGS__); \
            printf("\n" DEBUG_TERMINAL_RESET_COLOR);                    \
            CFXS_BREAK();                                               \
        }
    #define CFXS_ERROR(...)                                        \
        printf(DEBUG_TERMINAL_ERROR_COLOR "[ERROR] " __VA_ARGS__); \
        printf("\n" DEBUG_TERMINAL_RESET_COLOR);                   \
        CFXS_BREAK();
#else
    #define CFXS_ASSERT(condition, ...)
    #define CFXS_ERROR(...)
#endif

#define CFXS_REVERSE_ASSERT(message, condition) CFXS_ASSERT(condition, message)

#ifdef __cplusplus
// Generic debug level masks
namespace CFXS {

    using DebugLevel_t = uint8_t;

    struct DebugLevel {
        static constexpr DebugLevel_t DBG      = 0;
        static constexpr DebugLevel_t SPAM     = 1;
        static constexpr DebugLevel_t TRACE    = 2;
        static constexpr DebugLevel_t INFO     = 3;
        static constexpr DebugLevel_t WARNING  = 4;
        static constexpr DebugLevel_t ERROR    = 5;
        static constexpr DebugLevel_t CRITICAL = 6;
        static constexpr DebugLevel_t OFF      = 0xFF;
    };

} // namespace CFXS
#endif