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
#include <cstdio>

#ifdef CFXS_DEBUG
    #define CFXS_BKPT() __bkpt
    #ifdef CFXS_DEBUG_ASSERT
        #define CFXS_ASSERT(condition, ...)                                     \
            if (!(condition)) {                                                 \
                printf(__DEBUG_TERMINAL_ERROR_COLOR__ "[ASSERT] " __VA_ARGS__); \
                printf("\n"__DEBUG_TERMINAL_RESET_COLOR__);                     \
                CFXS_BKPT();                                                    \
            }
    #endif
#endif

#ifndef CFXS_ASSERT
    #define CFXS_ASSERT(condition, ...)
#endif