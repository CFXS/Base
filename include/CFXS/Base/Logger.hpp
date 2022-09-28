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
#include <cstdio>
#include <utility>

namespace CFXS {

    template<typename Config>
    class Logger {
    public:
        template<typename... Args>
        static void Log(Args&&... args) {
            if constexpr (Config::ENABLED) {
                printf(Config::LOG_PREFIX);
                printf(std::forward<Args>(args)...);
                printf("\n");
            }
        }

        template<typename... Args>
        static void LogConstructor(Args&&... args) {
            if constexpr (Config::ENABLED) {
                printf(Config::CONSTRUCTOR_PREFIX);
                printf(std::forward<Args>(args)...);
                printf("\n");
            }
        }

        template<typename... Args>
        static void LogDestructor(Args&&... args) {
            if constexpr (Config::ENABLED) {
                printf(Config::DESTRUCTOR_PREFIX);
                printf(std::forward<Args>(args)...);
                printf("\n");
            }
        }

        template<typename... Args>
        static void LogError(Args&&... args) {
            if constexpr (Config::ENABLED) {
                printf(Config::ERROR_PREFIX);
                printf(std::forward<Args>(args)...);
                printf("\n");
            }
        }

        template<typename... Args>
        static void LogWarning(Args&&... args) {
            if constexpr (Config::ENABLED) {
                printf(Config::WARNING_PREFIX);
                printf(std::forward<Args>(args)...);
                printf("\n");
            }
        }
    };

} // namespace CFXS