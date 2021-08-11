// [CFXS] //
#pragma once

#include "ANSI_Colors.hpp"
#include "DebugTerminal.hpp"

#ifdef CFXS_DEBUG
    #define CFXS_BKPT() __bkpt
    #ifdef CFXS_DEBUG_ASSERT
        #define CFXS_ASSERT(condition, ...)                                                \
            if (!(condition)) {                                                            \
                CFXS_println(__DEBUG_TERMINAL_ERROR_COLOR__ "[ASSERT_FAIL] " __VA_ARGS__); \
                CFXS_println(__DEBUG_TERMINAL_RESET_COLOR__);                              \
                CFXS_BKPT();                                                               \
            }
    #endif
#endif

#ifndef CFXS_ASSERT
    #define CFXS_ASSERT(condition, ...)
#endif