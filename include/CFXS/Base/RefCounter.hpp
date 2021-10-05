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
#include <CFXS/Base/Debug.hpp>

namespace CFXS {

    template<typename T, typename Inheriter>
    class RefCounter {
    public:
        T GetRefCount() {
            return m_RefCount;
        }

        void IncRefCount() {
            m_RefCount++;
        }

        void DecRefCount() {
            CFXS_ASSERT(m_RefCount, "Reference count is 0");
            m_RefCount--;
            if (!m_RefCount) {
                static_cast<Inheriter*>(this)->RefCountZero();
            }
        }

    private:
        T m_RefCount = 0;
    };

} // namespace CFXS