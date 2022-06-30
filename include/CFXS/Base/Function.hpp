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
