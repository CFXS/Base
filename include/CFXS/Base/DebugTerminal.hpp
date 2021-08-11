// [CFXS] //
#pragma once

#ifdef CFXS_DEBUG_TERMINAL_USE_COLORS
    #define __DEBUG_TERMINAL_RESET_COLOR__ __ANSI_WHITE__
    #define __DEBUG_TERMINAL_ERROR_COLOR__ __ANSI_RED__
#else
    #define __DEBUG_TERMINAL_RESET_COLOR__ ""
    #define __DEBUG_TERMINAL_ERROR_COLOR__
#endif