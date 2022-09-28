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

#include <utility>
#include <type_traits>
#include <functional>

namespace CFXS {

    template<class R, class UserType, bool IsVoid, class... Args>
    class FunctionBase;

    // function with no userdata
    template<class R, class UserType, class... Args>
    class FunctionBase<R, UserType, true, Args...> {
    protected:
        using FuncDef = R (*)(Args...);

        constexpr FunctionBase() {
        }
        constexpr FunctionBase(const FuncDef& func) : m_Function(std::move(func)) {
        }
        constexpr FunctionBase(const FuncDef& func, const UserType& userData) : m_Function(std::move(func)) {
        }

        FuncDef m_Function = nullptr;

    public:
        constexpr FuncDef GetFunctionPointer() const {
            return m_Function;
        }

        constexpr R operator()(Args... args) const {
            return m_Function(std::forward<Args>(args)...);
        }

        constexpr bool operator==(const FunctionBase& other) const {
            if (this == &other)
                return true;

            return m_Function == other.m_Function;
        }

        constexpr explicit operator bool() const noexcept {
            return m_Function;
        }
    };

    // function with userdata
    template<class R, class UserType, class... Args>
    class FunctionBase<R, UserType, false, Args...> {
    protected:
        using FuncDef = R (*)(UserType, Args...);

        constexpr FunctionBase() {
        }
        constexpr FunctionBase(const FuncDef& func) : m_Function(func) {
        }
        constexpr FunctionBase(const FuncDef& func, const UserType& userData) : m_Function(std::move(func)), m_UserData(userData) {
        }

        UserType m_UserData{};
        FuncDef m_Function = nullptr;

    public:
        constexpr R operator()(Args... args) const {
            return m_Function(m_UserData, std::forward<Args>(args)...);
        }

        constexpr bool operator==(const FunctionBase& other) const {
            if (this == &other)
                return true;

            return (m_Function == other.m_Function) && (m_UserData == other.m_UserData);
        }

        constexpr FuncDef GetFunctionPointer() const {
            return m_Function;
        }

        constexpr explicit operator bool() const noexcept {
            return m_Function;
        }
    };

    template<class T>
    class Function;

    class NoFunctionUserData {
    public:
        NoFunctionUserData() = delete;
    };

    template<class R, class UserType, class... Args>
    class Function<R(UserType, Args...)> : public FunctionBase<R, UserType, std::is_same<UserType, NoFunctionUserData>::value, Args...> {
        using FunctionBaseType = FunctionBase<R, UserType, std::is_same<UserType, NoFunctionUserData>::value, Args...>;

    public:
        constexpr Function() noexcept : FunctionBaseType() {
        }

        constexpr Function(nullptr_t) noexcept : FunctionBaseType() {
        }

        template<typename F>
        constexpr Function(F func, UserType userData) : FunctionBaseType(func, userData) {
        }

        template<typename F>
        constexpr Function(F func) : FunctionBaseType(func) {
        }
    };

} // namespace CFXS
