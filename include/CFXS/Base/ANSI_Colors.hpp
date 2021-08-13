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

#ifdef CFXS_DEBUG_TERMINAL_USE_COLORS
    #define __ANSI_RESET__   "\033[0m"
    #define __ANSI_RED__     "\e[1;31m"
    #define __ANSI_BLUE__    "\e[1;34m"
    #define __ANSI_GREEN__   "\e[1;32m"
    #define __ANSI_CYAN__    "\e[1;36m"
    #define __ANSI_MAGENTA__ "\e[1;35m"
    #define __ANSI_YELLOW__  "\e[1;33m"
#else
    #define __ANSI_RESET__   ""
    #define __ANSI_RED__     ""
    #define __ANSI_BLUE__    ""
    #define __ANSI_GREEN__   ""
    #define __ANSI_CYAN__    ""
    #define __ANSI_MAGENTA__ ""
    #define __ANSI_YELLOW__  ""
#endif