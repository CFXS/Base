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

#ifdef CFXS_DEBUG_TERMINAL_USE_COLORS // [CFXSDEF:Base] Use ANSI escape sequences for terminal colors
    #define ANSI_RESET   "\033[0m"
    #define ANSI_RED     "\e[1;31m"
    #define ANSI_BLUE    "\e[1;34m"
    #define ANSI_GREEN   "\e[1;32m"
    #define ANSI_CYAN    "\e[1;36m"
    #define ANSI_MAGENTA "\e[1;35m"
    #define ANSI_YELLOW  "\e[1;33m"
#else
    #define ANSI_RESET   ""
    #define ANSI_RED     ""
    #define ANSI_BLUE    ""
    #define ANSI_GREEN   ""
    #define ANSI_CYAN    ""
    #define ANSI_MAGENTA ""
    #define ANSI_YELLOW  ""
#endif